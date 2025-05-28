/*
Reqs.h: Handles SRS file I/O, reading each requirement.
Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.1     5/20/2025   Function implementations
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#include "../include/GetReqs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <commdlg.h>

char *getSRS(void) {                // User will input where the SRS file is located, returns file path
    int confirm = 0;
    while (!confirm) {
        static char filePath[MAX_FILE_PATH], confirmed[4];
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

        else if (!GetOpenFileName(&ofn)) {
            printf("ERROR: No file selected/File Dialog Error!\n");
            return NULL;
        }
    }
}

void readSRS(char *reqFile) {       // Parses the SRS file
    FILE *srs_file = fopen(reqFile, "r");
    if (!srs_file) {
        perror("ERROR: Unable to open SRS file!\n");
        return;
    }
    else {
        Req requirement;
        
    }
}

void printReq(Req *requirement) {   // Prints the requirement to the console
    // To be implemented...
}