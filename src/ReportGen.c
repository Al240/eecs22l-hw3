/*
ReportGen.c: SRS file I/O, generates a report detailing criteria (from SRS) 
and their status (req. met/not met) in the target program.

Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.1     5/20/2025   Function implementations, getOutFile() now also creates the file
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#include "../include/ReportGen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <commdlg.h>
#include <regex.h>

char *getOutFile(void) {    // Create an output file
    static char outFileName[MAX_LEN];
    do {
        printf("Enter output file name: ");
        scanf("%s", &outFileName);
    } while (!outFileName);
}

void writeDepTree(char *outFile, Req *pReq, Req *cReq) {    // Writes the dependency tree for a requirement to an output file
    FILE *file = fopen(outFile, "a");
    if (!file) {
        perror("ERROR: Unable to open output file!\n");
        return;
    }
    else {
        if (pReq && cReq) {
        fprintf(file, "%s -> %s\n", pReq->ID, cReq->ID);
        } else if (pReq) {
            fprintf(file, "%s\n", pReq->ID);
        } else if (cReq) {
            fprintf(file, "%s\n", cReq->ID);
        }

        fclose(file);
    }
}

char *getSRS(void) {                // User will input where the SRS file is located, returns file path
    int confirm = 0;
    while (!confirm) {
        static char filePath[MAX_LEN], confirmed[4];
        OPENFILENAME ofn;
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = NULL;
        ofn.lpstrFile = filePath;
        ofn.nMaxFile = sizeof(filePath);
        ofn.lpstrFilter = "Text Files\0*.txt;*.md\0All Files (*.*)\0*.*\0";
        ofn.lpstrTitle = "Open an SRS File";
        ofn.nFilterIndex = 1;
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

        if (GetOpenFileName(&ofn)) {
            printf("Confirm that the following file will be processed as the SRS: %s\n First lines:\n", filePath);
            FILE *srs_file = fopen(filePath, "r");
            if (!srs_file) {
                perror("Could not open SRS file!\n");
                return NULL;
            }
            else {
                char fLine[256];
                int currLine = 1;
                while (currLine<=3 && (fgets(fLine, sizeof(fLine), srs_file))) {
                    printf("%s", fLine);
                    currLine++;
                }
            }
            fclose(srs_file);
            printf("Is this the correct SRS file? (Y)es/(N)o: ");
            scanf("%3c", &confirmed);
            if (confirmed[0] == 'Y' || confirmed[0] == 'y') {
                confirm = 1;
                return filePath;
            }
            else if (confirmed[0] == 'N' || confirmed[0] == 'n') {
                printf("Please select another SRS file:\n");
            }
        }

        else {
            printf("ERROR: Something went wrong selecting the file!\n");
            return NULL;
        }
    }
}

int readSRS(char *reqFile) {       // Parses the SRS file
    FILE *srs = fopen(reqFile, "r");
    if (!srs) {
        perror("ERROR: Unable to open SRS file! Please check the path and file format.\n");
        return 1;
    }

    else {
        int lineNum = 0;
        char lineContents[MAX_LEN], reqID[MAX_REQ_ID];
        Req *mainReq = NULL;  // Pointer to the main requirement being processed
        Req *currentReq = NULL; // Pointer to the current requirement being processed
        regex_t regex;
        regmatch_t match[2];
        FILE *outFile = fopen(getOutFile(), "w");
        if (!outFile) {
            perror("ERROR: Unable to create output file!\n");
            fclose(srs);
            return 2;
        }

        while (fgets(lineContents, sizeof(lineContents), srs)) {
            lineNum++;
            
            // "Main" requirement found
            if (regcomp(&regex, "^ID:\\s*(REQ-[A-Z]+-[A-Z]+-\\d+)", REG_EXTENDED) == 0) {
                if (regexec(&regex, lineContents, 2, match, 0) == 0) {
                    // match[1] contains the start/end of the captured ID
                    int start = match[1].rm_so;
                    int end = match[1].rm_eo;
                    int idLen = end - start;
                    strncpy(reqID, lineContents + start, idLen);
                    reqID[idLen] = '\0'; // Null-terminate
                    mainReq = createReq(&reqID);
                    writeDepTree(outFile, mainReq, NULL);
                }
            }

            // Parent requirement(s) found
            if (regcomp(&regex, "^\\s*Parents:\\s*(REQ-[A-Z]+-[A-Z]+-\\d+)", REG_EXTENDED) == 0) {
                if (regexec(&regex, lineContents, 2, match, 0) == 0) {
                    int start = match[1].rm_so;
                    int end = match[1].rm_eo;
                    int idLen = end - start;
                    strncpy(reqID, lineContents + start, idLen);
                    reqID[idLen] = '\0'; // Null-terminate
                    Req *currentReq = createReq(parentID);
                    appendParentReq(currentReq, mainReq);
                    writeDepTree(outFile, currentReq, mainReq);
                }
            }

            // Child requirement(s) found
            if (regcomp(&regex, "^\\s*Children:\\s*(REQ-[A-Z]+-[A-Z]+-\\d+)", REG_EXTENDED) == 0) {
                if (regexec(&regex, lineContents, 2, match, 0) == 0) {
                    int start = match[1].rm_so;
                    int end = match[1].rm_eo;
                    int idLen = end - start;
                    strncpy(reqID, lineContents + start, idLen);
                    reqID[idLen] = '\0'; // Null-terminate
                    Req *currentReq = createReq(reqID);
                    appendChildReq(currentReq, mainReq);
                    writeDepTree(outFile, mainReq, currentReq);
                }
            }
            regfree(&regex);
        }
        return 0; // Successfully read the SRS file
    }
}