#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "../headers/ReadFile.h"

using namespace std;

class Menu {
	public:
		Menu(string tracksFileLocation, string artistsFileLocation);
		~Menu();

    void visible();

  private:
    ReadFile *readFile;

    void loadTrackFile();
    bool hasBinaryFile(string binaryFileName);
    // bool hasFileToRead(string fileLocation, string binaryFileName);
};

#endif
