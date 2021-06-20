#ifndef READARTISTFILE_H_INCLUDED
#define READARTISTFILE_H_INCLUDED

#include <iostream>
#include "./ArtistList.h"

using namespace std;

class ReadArtistFile {
	public:
		ReadArtistFile(string artistsFileLocation);
		~ReadArtistFile();

    void readArtists();
    ArtistList *readBinaryArtists();

    void testBinaryArtistFile();
    void printStruct();

  private:
    string artistsFileLocation;
    string binaryFileLocation;

    int calculateColumn(string variableName);
    void readArtistLine(string line, ofstream *binaryFile);
    Artist* readBinaryArtistLine(ifstream *binaryFile);
    int calculateBinaryArtistPosition(string variableName, int currentLine);

    int calculateBinaryTrackPosition(string variableName, int currentLine);
    ArtistList *testReadBinaryArtists(int numberOfArtists);
    void createArtistsCSVFile(ArtistList *tracks);
};

#endif
