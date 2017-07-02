/**
 * Search all the points imported from the input file 
 * to find the required number of the closest points.
 */
#include "SearchResult.h"

class Search {
	
private:
    std::string inputFile, outputFile;
    Point centraPoint;
    SearchResult result;

public:
    /**
     * Constructor.
     */
    Search() { }
    Search(std::string input, std::string output, Point point, int targetSize) : 
        inputFile(input), outputFile(output), centraPoint(point), result(targetSize) { }

    /**
     * Read the input file and add the points to the array 
     * if its distance to the central point is close.
     */
    bool processInputFile();

    /**
     * Print the result.
     */
    void printResult();
};