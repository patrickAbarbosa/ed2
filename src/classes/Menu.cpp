#include <iostream>
#include "../headers/Menu.h"
#include "../headers/ReadFile.h"

using namespace std;

Menu::Menu() {
  cout << "Menu starting" << endl;
  char menuItem;


  loadTrackFile();
}

Menu::~Menu() {
  cout << "Stop Menu" << endl;
}

void Menu::loadTrackFile(){
  string fileLocation;
  cout << "Digite o local do arquivo tracks: ";
  cin >> fileLocation;

  ReadFile * file;
  file = new ReadFile(fileLocation);

  TrackList *list = file->readTracks();

  list->printList();
}
