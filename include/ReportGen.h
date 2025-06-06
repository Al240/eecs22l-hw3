/*
ReportGen.h: Generates a report detailing criteria (from SRS) 
and their status (req. met/not met) in the target program.

Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#ifndef REPORTGEN_H
#define REPORTGEN_H
#include "Reqs.h"

/* Function Prototypes */
char *getOutFile(void);     // Get input for output file name

void writeDepTree(char *outFile, unsigned int lineNum, Req *pReq, Req *cReq);   // Writes the dependency tree (Line #: parent -> child) to an output file

char *getSRS(void);     // User will input where the SRS file is located, returns file path

int readSRS(char *reqFile);     // Parses the SRS file
#endif