#ifndef READFILE_H_INCLUDED
#define READFILE_H_INCLUDED

#include <iostream>
#include "./TrackList.h"
#include "./ArtistList.h"

using namespace std;

class ReadFile {
	public:
		ReadFile(string fileLocation);
		~ReadFile();

    TrackList *readTracks();
    TrackList *readBinaryTracks();
    ArtistList *readArtists();
    ArtistList *readBinaryArtists();
    void testBinaryTrackFile();

  private:
    string fileLocation;
    string readValue(stringstream *line);

    Track *readTrackLine(string line, ofstream *binaryFile);
    Track* readBinaryTrackLine(ifstream *binaryFile);
    int calculateBinaryTrackPosition(string variableName, int currentLine);

    Artist *readArtistLine(string line, ofstream *binaryFile);
    Artist* readBinaryArtistLine(ifstream *binaryFile, int index);
    int calculateBinaryArtistPosition(string variableName, int currentLine);

    TrackList *testReadBinaryTracks(int numberOfTracks);
};

#endif
