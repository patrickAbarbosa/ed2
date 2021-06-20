#ifndef READFILE_H_INCLUDED
#define READFILE_H_INCLUDED

#include <iostream>
#include "./ReadArtistFile.h"
#include "./ReadTrackFile.h"

using namespace std;

class ReadFile {
	public:
		ReadFile(string tracksFileLocation, string artistsFileLocation);
		~ReadFile();

    void readTracksFile();
    void readArtistsFile();

    void printTrackStruct();
    void testBinaryTrackFile();

    void printArtistStruct();
    void testBinaryArtistFile();

  private:
    ReadTrackFile *readTracks;
    ReadArtistFile *readArtists;
};

#endif
