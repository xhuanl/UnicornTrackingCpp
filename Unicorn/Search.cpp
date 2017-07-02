#include "Search.h"
#include <fstream>

bool 
Search::processInputFile() {
        
    ifstream inputfile(inputFile);
    string line;

    while (std::getline(inputfile, line)) {

        // Ignore the line if it is empty.
        if (line.length() == 0) {
            cout << "Invalid input: " << line << endl;
            continue;
        }

        Point point;

        try {
            // Create the Point object from the input.
            if (!point.parse(line)) {
                cout << "Invalid input: " << line << endl;
                continue;
            }

            // Calculate the distance.
            point.setDistanceSquare(centraPoint.distanceSquareFrom(point));

            // Try to add the result to the final list.
            result.add(point);
        } catch(...) {
            cout << "Invalid input: " << line << endl;
            continue;
        }
    }

    return true;
}
    
void 
Search::printResult() {
    	
        // Check if the array is null.
    if (result.getResult() == NULL) {
        cout << "No result to print. " << endl;
        return;
    }

    ofstream outputfile(outputFile);

    if (!outputfile.is_open()) {
        cout << "Cannot create file: " << outputFile << endl;
    }

    for (int i = 0; i < result.getSize(); i++) {
        Point point = result.getResult()[i];
        outputfile << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")" << endl;
    }

    outputfile.close();
    cout << "Successfully output the result." << endl;
}
