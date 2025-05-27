/*
GetReqs.h: Handles SRS file I/O, reading each requirement.
Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#ifndef GETREQS_H
#define GETREQS_H

#define MAX_FILE_PATH 256   // Maximum file path length
#define MAX_REQ_ID 32       // Maximum requirement ID length

typedef struct Requirement Req;

/* How each requirement is stored */
struct Requirement {
    char reqID[MAX_REQ_ID];        // Requirement identifier (i.e. REQ-FNC-002)
    char reqParent[MAX_REQ_ID];    // What this requirement depends on (i.e. REQ-FNC-001)
    char reqStatus[16];            // Requirement status (i.e. "met", "not met", "in progress")
};

/* Function Prototypes */
void printReq(Req *requirement);            // Prints the requirement to the console

char *getSRS(void);                         // User will input where the SRS file is located, returns file path

void readSRS(char *reqFile);                // Parses the SRS file

#endif