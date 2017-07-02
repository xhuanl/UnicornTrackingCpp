/**
 * SearchResult class represents the final result to be printed.
 *
 */

#include "Point.h"

class SearchResult {

private:
    int maxSize;        /* Expected the amount of the closest points. */
    int actualSize;     /* Actual amount of the closest points. */
    
    Point* result;      /* The found closest points */

public:
    /**
     * Constructor.
     */
    SearchResult() { 
        actualSize = 0;
    }

    SearchResult(int size);

    /**
     * Add a new point.
     */
    void add(Point point);

    int getSize() {
        return actualSize;
    }
    
    Point* getResult() {
        return result;
    }
};
