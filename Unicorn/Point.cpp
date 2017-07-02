#include <Windows.h>
#include <regex>
#include <string>
#include "Point.h"

using namespace std;

/**
 * Point class constructor. 
 * Parse the co-ordinates from the input. 
 */
bool 
Point::parse(string input) {
    string delimiter = ",";
    string x, y, z;

    smatch match;
    regex regex("((.+))"); 

    if (!regex_match(input, match, regex)) {
		return false;
    }

    ssub_match sub_match = match[0];
    string result = sub_match.str();

    int pos = result.find_first_of("(");

    if (pos > -1) {
        result = result.substr(pos + 1);
    }
    
    pos = result.find_first_of(")");

    if (pos > -1) {
        result = result.substr(0, pos);
    }

    pos = result.find_first_of(delimiter);

    if (pos < 0) {
        return false;
    }

    x = result.substr(0, pos);
    result = result.substr(pos + 1);
    pos = result.find_first_of(delimiter);

    if (pos < 0) {
        return false;
    }

    y = result.substr(0, pos);
    z = result.substr(pos + 1);

    pos = z.find_first_of(delimiter);

    if (pos > -1) {
        // More than 3 numbers.
        return false;
    }

    try {
        X = std::stoi(x);
        Y = std::stoi(y);
        Z = std::stoi(z);
    } catch(...) {
        return false;
    }

    return true;
}

/**
 * Using the distance square to avoid the sqrt operation
 * and keep the integer result. 
 */
int 
Point::distanceSquareFrom(Point point) {
    return (point.getX() - X) * (point.getX() - X) +
            (point.getY() - Y) * (point.getY() - Y) +
            (point.getZ() - Z) * (point.getZ() - Z);
}
