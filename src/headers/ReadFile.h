#ifndef READFILE_H_INCLUDED
#define READFILE_H_INCLUDED

#include <iostream>
#include "./TrackList.h"

using namespace std;

class ReadFile {
	public:
		ReadFile(string fileLocation);
		~ReadFile();

    TrackList *readTracks();
  private:
    string fileLocation;
    Track *readTrackLine(string line);
    string readValue(stringstream *line);
};

#endif
