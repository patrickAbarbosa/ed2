#ifndef READARTISTFILE_H_INCLUDED
#define READARTISTFILE_H_INCLUDED

#include <iostream>
#include "./ArtistList.h"

using namespace std;

class ReadArtistFile {
	public:
		ReadArtistFile(string artistsFileLocation);
		~ReadArtistFile();

    ArtistList *readArtists();
    ArtistList *readBinaryArtists();

    void testBinaryArtistFile();

  private:
    string artistsFileLocation;
    string binaryFileLocation;

    Artist *readArtistLine(string line, ofstream *binaryFile);
    Artist* readBinaryArtistLine(ifstream *binaryFile, int index);
    int calculateBinaryArtistPosition(string variableName, int currentLine);

    ArtistList *testReadBinaryArtists(int numberOfArtists);
    void createArtistsCSVFile(ArtistList *tracks);
};

#endif
