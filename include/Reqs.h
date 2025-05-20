/*
Reqs.h: Handles SRS file I/O, reading each requirement.
Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#ifndef FILEIO_H
#define FILEIO_H

typedef struct Requirement Req;

/* How each requirement is stored */
struct Requirement {
    char *reqID;        // Requirement identifier (i.e. REQ-FNC-002)
    char *reqParent;    // What this requirement depends on (i.e. REQ-FNC-001)
    char *reqStatus;    // Requirement status (i.e. "met", "not met", "in progress")
};

/* Function Prototypes */
void printReq(Req *requirement);            // Prints the requirement to the console

char *getSRS(void);                         // User will input where the SRS file is located, returns file path

void readSRS(char *reqFile);                // Parses the SRS file and returns a pointer to the ReqModule struct

#endif