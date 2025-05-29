/*
Reqs.c: Handles requirement creation and storage.
Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.1     5/20/2025   Function implementations
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#include "../include/Reqs.h"
#include <stdio.h>
#include <assert.h>

Req *createReq(char *reqID) { // Create a requirement with the given ID
    Req *newReq = malloc(sizeof(Req));
    if (!newReq) {
        perror("ERROR: Not enough memory to create new requirement!\n");
        return NULL;
    }
    else {
        assert(reqID);
        strncpy(newReq->ID, reqID, strlen(reqID)+1);
        newReq->reqParent = NULL;
        newReq->numCReq = 0;
        newReq->childReqs = NULL;
        return newReq;
    }
}

void *appendParentReq(Req *pReq, Req *requirement) { // Adds a parent requirement to the list
    assert(pReq);
    assert(requirement);

    if (pReq->numPReq < MAX_REQ) {
        pReq->reqParents[pReq->numPReq] = requirement;
        pReq->numPReq++;
    }
    else {
        printf("ERROR: This program supports a max. of %d parent requirements for each requirement!\n", MAX_REQ);
    }
}

void *appendChildReq(Req *cReq, Req *pReq) { // Adds a child requirement to the list
    assert(cReq);
    assert(pReq);

    if (pReq->numCReq < MAX_REQ) {
        pReq->childReqs[pReq->numCReq] = cReq;
        pReq->numCReq++;
    }
    else {
        printf("ERROR: This program supports a max. of %d child requirements for each requirement!\n", MAX_CREQ);
    }
}