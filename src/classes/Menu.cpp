#include <iostream>
#include <fstream>
#include "../headers/Menu.h"
#include "../headers/ReadFile.h"

using namespace std;

Menu::Menu() {
  cout << "Menu starting" << endl;

  loadTrackFile();
}

Menu::~Menu() {
  cout << "Stop Menu" << endl;
}

void Menu::loadTrackFile(){
  string fileLocation;
  // ifstream binaryFile("../bin/tracks.bin", ifstream::in | ifstream::binary);

  cout << "Digite o local do arquivo tracks: ";
  cin >> fileLocation;

  ReadFile * file;
  file = new ReadFile(fileLocation);

  TrackList *list = file->readBinaryTracks();

  list->printList();
}
