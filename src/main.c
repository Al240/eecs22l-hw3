/*
main.c: Main program loop.
Written by: Albert N. // 5/13/2025
EECS 22L Spring 2025 Assignment 3
--------------------------------------------
ver.    Date        Changelog
1.0     5/13/2025   Initial version
--------------------------------------------
*/

#include "../include/ReportGen.h"

int main(void) { // Get SRS file, parse/create dep. tree, and generate report. 
    int readSuccess;
    char *srs = getSRS(); // User will specify SRS file path
    if (!srs) {
        printf("ERROR: Unable to open an SRS file!\n");
        return 1;
    }

    readSuccess = readSRS(srs); // Read and parse the given SRS
    if (readSuccess == 0) {
        printf("Successfully parsed the SRS file! Quitting...\n");
        return 0;
    }
    else {
        printf("There was an error in the SRS parsing process!\n");
        return readSuccess; // Return error code
    }
}