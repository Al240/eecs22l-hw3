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
#include "GetReqs.h"

/* Function Prototypes */
char *getOutFile(void);     // Get input for output file name

void writeDepTree(Req *requirement, char *outFile);    // Writes the dependency tree for a requirement to an output file

#endif