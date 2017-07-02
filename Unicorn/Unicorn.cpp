// Unicorn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "Search.h"


/**
 * Entry point of the application.
 * Input should be in the format of
 * "/Users/netapp/input.txt" "(1, 2, 3)" 100 "/Users/netapp/output.txt"
 */
int _tmain(int argc, _TCHAR* argv[])
{
    // Validate the input.
    if (argc != 5) {
        cout << "Invalid command line input." << endl;
    }    

    string inputFile(argv[1]);
    Point targetPoint;
        
    if (!targetPoint.parse(argv[2])) {
        cout << "Invalid target point." << endl;
       return 1;
   }
        
   int count = atoi(argv[3]);
     
   if (count == 0) {
       cout << "Invalid input for the total points to search." << endl;
       return 1;
    }
        
    string outputFile = argv[4];
        
    // Create a Search object 
    Search search(inputFile, outputFile, targetPoint, count);
        
    // Search the points. 
    if (search.processInputFile()) {
        /* Print the output. */
        search.printResult();
    }
        
    cout << "Finished tracking." << endl;
	return 0;
}

