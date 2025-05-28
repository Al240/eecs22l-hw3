/*
ReportGen.c: Generates a report detailing criteria (from SRS) 
and their status (req. met/not met) in the target program.

Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.1     5/20/2025   Function implementations
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#include "../include/ReportGen.h"

char *getOutFile(void) {    // Create an output file
    static char outFileName[MAX_FILE_PATH];
    do {
        printf("Enter output file name: ");
        scanf("%s", &outFileName);
    } while (!outFileName);
}

void writeDepTree(Req *requirement, char *outFile) {    // Writes the dependency tree for a requirement to an output file
    // To be implemented...
}