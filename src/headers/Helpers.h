#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>

using namespace std;

class Helpers {
	public:
    Helpers();
    ~Helpers();

	  string readValue(stringstream *line);
};

#endif
