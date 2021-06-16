#include "../headers/Menu.h"
#include "../headers/ReadFile.h"
#include <fstream>
#include <iostream>

using namespace std;

Menu::Menu() {
  int menuOption = -1;
  ReadFile * file;
  file = new ReadFile("");
  // loadTrackFile();
  while (menuOption != 9) {
    cout << "---------- MENU -----------\n";
    cout << "[0] - Exibir estrutura Track\n";
    cout << "[1] - Exibir estrutura Artists\n";
    cout << "[2] - Testar Tracks\n";
    cout << "[3] - Testar Artists\n";
    cout << "[9] - Sair\n";

    cout << "\nDigite uma opcao: ";
    cin >> menuOption;

    cout << endl;
    switch (menuOption)
    {
    case 0:
      cout << "Print estrutura Track" << endl;
      break;
    case 1:
      cout << "Print estrutura Artist" << endl;
      break;
    case 2:
      file->testBinaryTrackFile();
      break;

    case 3:
      cout << "Testar Artists" << endl;
      break;
    case 9:
      cout << "Bye =)" << endl;
      break;
    default:
      cout << "Erro: Digite uma opcao válida!" << endl;
      break;
    }
  }
}

Menu::~Menu() { cout << "Encerrando Menu" << endl; }

void Menu::loadTrackFile(){
  string fileLocation;
  // ifstream binaryFile("../bin/tracks.bin", ifstream::in | ifstream::binary);

  cout << "Digite o local do arquivo tracks: ";
  cin >> fileLocation;

  ReadFile * file;
  file = new ReadFile(fileLocation);

  TrackList * list = file->readTracks();
  // TrackList *list = file->readBinaryTracks();

  // ArtistList *list = file->readBinaryArtists();

  // list->printList();
}
