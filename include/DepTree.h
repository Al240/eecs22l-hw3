/*
DepTree.h: Creates a dependency tree from requirements inside SRS.
Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#ifndef DEPTREE_H
#define DEPTREE_H
#include "Reqs.h"

#define MAX_VERTEX_LABEL_LEN 50  // Max length of the label for a vertex

/* Struct for a Node in the graph (representing a vertex) */
typedef struct Node {
    char label[MAX_VERTEX_LABEL_LEN];   // Label or identifier for the node (e.g., REQ-001)
    struct Edge *edges;                 // Adjacency list of outgoing edges
    struct Node *next;                  // Pointer to next node in the graph (for linked list)
} Node;

/* Struct for an edge between two nodes (directed edge) */
typedef struct Edge {
    struct Node *target; // Target node of the edge
    struct Edge *next;   // Pointer to next edge (for linked list of edges)
} Edge;

/* Struct for the Graph */
typedef struct Graph {
    Node *vertices;  // Head of the linked list of vertices
} Graph;

/* Function Prototypes */
void writeDepTree(Req *requirements, char *outFile);    // Writes the dependency tree to an output file

#endif