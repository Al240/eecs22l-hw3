/*
Reqs.h: Handles requirement creation and storage.
Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#ifndef GETREQS_H
#define GETREQS_H

#define MAX_LEN 512     // Maximum file path or line length
#define MAX_REQ_ID 32   // Maximum requirement ID length
#define MAX_REQ 32     // Maximum number of parent/child requirements

typedef struct Requirement Req;

/* How each requirement is stored */
struct Requirement {
    char ID[MAX_REQ_ID];        // Requirement identifier (i.e. REQ-FNC-002)
    unsigned int numPReq;       // Number of parent requirements
    Req *reqParents[MAX_REQ];   // What this requirement(s) this one depends on (i.e. REQ-FNC-001)
    unsigned int numCReq;       // Number of child requirements
    Req *childReqs[MAX_REQ];    // What requirement(s) does this one depend on
};

/* Function Prototypes */
Req *createReq(char *reqID);                        // Create a requirement with the given ID

Req *appendParentReq(Req *pReq, Req *requirement);  // Adds a parent requirement

Req *appendChildReq(Req *cReq, Req *pReq);          // Adds a child requirement
#endif