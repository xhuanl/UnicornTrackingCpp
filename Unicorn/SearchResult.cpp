#include <Windows.h>
#include "SearchResult.h"

SearchResult::SearchResult(int size) {

    actualSize = 0;
    maxSize = size;
    result = new Point[maxSize];
}

/**
* Add a new point to the result if it is one of the closest points.
*/
void
SearchResult::add(Point point) {

    // Initialize the first element.
    if (actualSize == 0) {
        result[actualSize] = point;
        actualSize++;
        return;
    }

    /*
     * If the expected number of point is not filled and 
     * the distance to the new point is greater the longest 
     * distance we have currently, add the new point as the
     * last element.
    */
    if (point.getDistanceSquare() >= result[actualSize - 1].getDistanceSquare()) {
        if (actualSize < maxSize) {
            result[actualSize] = point;
            actualSize++;
        }
        return;
    }
                
    int i = actualSize - 1;

    if (actualSize < maxSize) {
        result[i + 1] = result[i];
        actualSize++;
    }
        
    /* Similar to the Insertion sort, if the distance to the new point is 
     * between the distances of the existing points, insert the new point
     * to the array with proper order.
     */
    while (i > 0 && point.getDistanceSquare() < result[i].getDistanceSquare()) {
        result[i] = result[i - 1];
        i--;
    }

    result[i] = point;
    return;
}
