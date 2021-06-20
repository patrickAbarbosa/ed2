#include "../headers/Menu.h"
#include "../headers/ReadFile.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * hasBinaryFile
 *
 * Verifica se existe arquivo binário no diretório <projectFolder>/bin
 *
 * @param {string} binaryFileName
 *
 * @return {bool}
 */
bool Menu::hasBinaryFile (string binaryFileName) {
  string _binaryFileLocation = "../bin/" + binaryFileName;

  ifstream binaryFile(_binaryFileLocation, ifstream::in | ifstream::binary);

  if (binaryFile.is_open()) {
    binaryFile.close();

    return true;
  }

  return false;
}

/**
 * Menu
 *
 * Inicia variáveis necessárias e verifica previamente
 * se é necessário leitura de arquivos .csv
 *
 * @param {string} tracksFileLocation
 * @param {string} artistsFileLocation
 */
Menu::Menu(string tracksFileLocation, string artistsFileLocation) {
  readFile = new ReadFile(tracksFileLocation, artistsFileLocation);

  char optionMenu;

  if (hasBinaryFile("Tracks.bin")) {
    cout << "Existe um arquivo binario de Tracks." << endl;
    cout << "Deseja ler novamente um arquivo .csv? (s/n): ";
    cin >> optionMenu;

    bool isValidOption = optionMenu == 's' || optionMenu == 'S' || optionMenu == 'n' || optionMenu == 'N';

    while (!isValidOption) {
      cout << "Digite uma opcao valida!" << endl;
      cout << "Deseja ler novamente um arquivo .csv? (s/n): ";
      cin >> optionMenu;
    }

    if (optionMenu == 's' || optionMenu == 'S') {
      readFile->readTracksFile();
    }
  } else if (tracksFileLocation.empty()) {
    cout << "Arquivo Tracks invalido!" << endl;
    exit(1);
  }

if (hasBinaryFile("Artists.bin")) {
    cout << "Existe um arquivo binario de Artists." << endl;
    cout << "Deseja ler novamente um arquivo .csv? (s/n): ";
    cin >> optionMenu;

    bool isValidOption = optionMenu == 's' || optionMenu == 'S' || optionMenu == 'n' || optionMenu == 'N';

    while (!isValidOption) {
      cout << "Digite uma opcao valida!" << endl;
      cout << "Deseja ler novamente um arquivo .csv? (s/n): ";
      cin >> optionMenu;
    }

    if (optionMenu == 's' || optionMenu == 'S') {
      readFile->readArtistsFile();
    }
  } else if (artistsFileLocation.empty()) {
    cout << "Arquivo Artists invalido!" << endl;
    exit(1);
  }
}

Menu::~Menu() {}

/**
 * visible
 *
 * Interface do usuário. Exibe opções opções possíveis.
 */
void Menu::visible() {
  int menuOption = -1;

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
    // [0] - Exibir estrutura Track
    case 0:
      cout << "Print estrutura Track" << endl;
      readFile->printTrackStruct();
      break;
    // [1] - Exibir estrutura Artists
    case 1:
      cout << "Print estrutura Artist" << endl;
      break;
    // [2] - Testar Tracks
    case 2:
      readFile->testBinaryTrackFile();
      break;
    // [3] - Testar Artists
    case 3:
      cout << "Testar Artists" << endl;
      break;

    // [9] - Sair
    case 9:
      cout << "Bye =)" << endl;
      break;
    default:
      cout << "Erro: Digite uma opcao valida!" << endl;
      break;
    }
  }
}
