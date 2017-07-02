/**
 * Point class to represent the points.
 */
#include <string>
#include <iostream>

using namespace std;

class Point {

private:
	int X, Y, Z;        /* co-ordinates. */
    int distanceSquare; /* The square value of the distance between two points. */
    
public:
	// Constructor.
    Point() { }

    // Constructor.
	Point(int x, int y, int z) {
        X = x;  
        Y = y;  
        Z = z;  
    }
    
    int getX() {
        return  X;
    }
    
    int getY() {
        return Y;
    }
    
    int getZ() {
        return Z;
    }

	bool parse(std::string input);
    
    int getDistanceSquare() {
        return distanceSquare;
    }
    
    void setDistanceSquare(int ds) {
        distanceSquare = ds;
    }
    
    int distanceSquareFrom(Point point);
};
