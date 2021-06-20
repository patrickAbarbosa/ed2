#ifndef READTRACKFILE_H_INCLUDED
#define READTRACKFILE_H_INCLUDED

#include <iostream>
#include "./TrackList.h"

using namespace std;

class ReadTrackFile {
	public:
		ReadTrackFile(string tracksFileLocation);
		~ReadTrackFile();

    void readTracks();
    TrackList *readBinaryTracks();

    void testBinaryTrackFile();
    void printStruct();

  private:
    string tracksFileLocation;
    string binaryFileLocation;

    int calculateColumn(string variableName);
    void readTrackLine(string line, ofstream *binaryFile);
    Track* readBinaryTrackLine(ifstream *binaryFile);
    int calculateBinaryTrackPosition(string variableName, int currentLine);

    TrackList *testReadBinaryTracks(int numberOfTracks);
    void createTracksCSVFile(TrackList *tracks);
};

#endif
