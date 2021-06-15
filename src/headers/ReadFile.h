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
    TrackList *readBinaryTracks();
  private:
    string fileLocation;
    Track *readTrackLine(string line, ofstream *binaryFile);
    string readValue(stringstream *line);
    Track* readBinaryTrackLine(ifstream *binaryFile, int index);
};

#endif
