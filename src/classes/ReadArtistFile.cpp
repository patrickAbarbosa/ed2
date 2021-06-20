#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "../headers/ReadArtistFile.h"
#include "../headers/Helpers.h"

using namespace std;

ReadArtistFile::ReadArtistFile(string artistsFileLocation) {
  this->artistsFileLocation = artistsFileLocation;
  this->binaryFileLocation = "../bin/Artists.bin";
}

ReadArtistFile::~ReadArtistFile() {}

/**
 * readBinaryArtistLine
 *
 * @param {ifstream*} binaryFile endereço do ifstream
 * @param {int} index
 */
Artist *ReadArtistFile::readBinaryArtistLine(ifstream *binaryFile) {
  Artist *artist = new Artist;
  char *str;
  int length;

  binaryFile->read(artist->id, sizeof(artist->id));

  length = sizeof(artist->followers);
  str = new char[length];
  binaryFile->read(str, length);
  artist->followers = atoi(str);
  delete [] str;

  binaryFile->read(artist->genres, sizeof(artist->genres));

  binaryFile->read(artist->name, sizeof(artist->name));

  length = sizeof(artist->popularity);
  str = new char[length];
  binaryFile->read(str, length);
  artist->popularity = atoi(str);
  delete [] str;

  return artist;
}

/**
 * readArtistLine
 *
 * @param line
 * @param *binaryFile
 */
void ReadArtistFile::readArtistLine(string line, ofstream *binaryFile) {
  cout << ".";
  Helpers helper;
  stringstream _line(line);

  Artist artist;
  string str;

  str = helper.readValue(&_line);
  strcpy(artist.id, str.c_str());
  binaryFile->write(artist.id, sizeof(artist.id));

  str = helper.readValue(&_line);
  artist.followers = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(artist.followers));

  str = helper.readValue(&_line);
  strcpy(artist.genres, str.c_str());
  binaryFile->write(artist.genres, sizeof(artist.genres));

  str = helper.readValue(&_line);
  strcpy(artist.name, str.c_str());
  binaryFile->write(artist.name, sizeof(artist.name));

  str = helper.readValue(&_line);
  artist.popularity = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(artist.popularity));

  cout << line << endl;
}


/**
 * readArtists
 *
 * le .csv de Artists e grava no arquivo binário Artists.bin
 */
void ReadArtistFile::readArtists() {
  fstream file(artistsFileLocation, fstream::in);

  if (!file.is_open()) {
    cout << "Erro ao abrir arquivo artists." << endl;
    exit(1);
  }

  ofstream binaryFile(binaryFileLocation, ofstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario." << endl;

    exit(1);
  }

  string currentLine;
  getline(file, currentLine); // Remove primeira linha do csv

  while (!file.eof()) {
    getline(file, currentLine);

    if (currentLine.length() > 0) {
      readArtistLine(currentLine, &binaryFile);
    }
  }

  cout << endl;

  file.close();
  binaryFile.close();
}

/**
 * readBinaryArtist
 *
 * le o arquivo binário de artistas e retorna um vetor de artistas
 *
 * @return *ArtistList
 */
ArtistList *ReadArtistFile::readBinaryArtists() {
  ifstream binaryFile("../bin/artists.bin", ifstream::in | ifstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario de artistas" << endl;

    exit(1);
  }

  string currentLine;
  ArtistList *list = new ArtistList();

  binaryFile.seekg (0, binaryFile.end);
  int fileSize = binaryFile.tellg();
  binaryFile.seekg (0, binaryFile.beg);

  for (int index = 0; !binaryFile.eof() && binaryFile.tellg() < fileSize; index++) {
    Artist *artist = readBinaryArtistLine(&binaryFile);

    list->insertEnd(artist);
  }

  binaryFile.close();

  return list;
}

/**
 * calculateColumn
 *
 * Retorna a coluna em bytes que o valor se encontra
 *
 * @param {string} variableName Nome da variável a ser lida
 *
 * @return {int} posição inicial da variável
*/
int ReadArtistFile::calculateColumn(string variableName) {
  Artist artist;
  int column = 0;

  if (variableName == "id"){
    return column;
  }
  column += sizeof(artist.id);

  if (variableName == "followers"){
    return column;
  }
  column += sizeof(artist.followers);

  if (variableName == "genres"){
    return column;
  }
  column += sizeof(artist.genres);

  if (variableName == "name"){
    return column;
  }
  column += sizeof(artist.name);

  if (variableName == "popularity"){
    return column;
  }
  column += sizeof(artist.popularity);

  return column;
}

/**
 * calculateBinaryPosition
 *
 * Retorna a posição binaria de uma variável em determinada "linha"
 *
 * @param {string} variableName
 * @return {int} currentLine retorna a posição da variável dentro do arquivo binário
 */
int ReadArtistFile::calculateBinaryTrackPosition(string variableName, int currentLine) {
  int _linearLine = calculateColumn("") * currentLine;

  return _linearLine;
}

/**
 * testReadBinaryArtists
 *
 * lê um determinado número de artists do arquivo Artists.bin
 *
 * @param {int} numberOfTracks número de artistas a ser lido
 * @return {ArtistList}
 */
ArtistList *ReadArtistFile::testReadBinaryArtists(int numberOfArtists) {
  ifstream binaryFile("../bin/Artists.bin", ifstream::in | ifstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario de Artists" << endl;
    exit(1);
  }

  ArtistList *list = new ArtistList;

  binaryFile.seekg (0, binaryFile.end);
  int fileSize = binaryFile.tellg();
  binaryFile.seekg (0, binaryFile.beg);
  int totalTracks = ceil(float(float(fileSize) / calculateColumn("")));

  printf("Tamanho do arquivo: %d bytes\n", fileSize);
  srand(time(NULL));

  for (;numberOfArtists > 0; numberOfArtists--) {
    binaryFile.clear();

    int currentIndex = (int (rand() % totalTracks)) ;
    int position = calculateBinaryTrackPosition("", currentIndex);
    binaryFile.seekg(position, binaryFile.beg);
    Artist *artist = readBinaryArtistLine(&binaryFile);

    list->insertEnd(artist);
  }

  return list;
}

/**
 * createTracksCSVFile
 *
 * cria um arquivo tracks_test.csv na pasta principal do projeto
 *
 * @param {TrackList*} tracks Uma lista de Tracks a ser inseridas no arquivo
 */
void ReadArtistFile::createArtistsCSVFile(ArtistList *artists) {
  ofstream csvFile("../artists_test.csv");

  if (!csvFile.is_open()) {
    cout << "Nao foi possivel abrir o arquivo tracks_test.csv" << endl;
    exit(1);
  }

  csvFile << "id,followers,genres,name,popularity" << endl;

  NodeArtist *artist = artists->getFirstArtist();

  while (artist != NULL) {
    Artist *_artist = artist->getArtist();

    if (_artist) {
      csvFile
      << _artist->id << ','
      << _artist->followers << ','
      << '"' << _artist->genres << '"' << ','
      << '"' << _artist->name << '"' << ','
      << _artist->popularity << endl;
    }

    artist = artist->getNext();
  }

  cout << "artists_test.csv criado com sucesso!\n\n";

  csvFile.close();
}

void ReadArtistFile::printStruct() {
  cout << "------ Artist Struct -------" << endl;
  cout << "char id[22]" << endl;
  cout << "float followers" << endl;
  cout << "char genres[255]" << endl;
  cout << "char name[255]" << endl;
  cout << "int popularity" << endl;
  cout << endl;
}


void ReadArtistFile::testBinaryArtistFile() {
  int menuOption = -1;
  ArtistList *artists = NULL;

  while (menuOption != 9) {
    cout << "------- Teste Artists ------\n";
    cout << "[0] - Exibir em tela\n";
    cout << "[1] - Arquivo .csv\n";
    cout << "[8] - Voltar menu principal\n";
    cout << "[9] - Sair\n";
    cout << "\nDigite uma opcao: ";
    cin >> menuOption;

    switch (menuOption) {
    //[0] - Exibir em tela
    case 0:
      artists = testReadBinaryArtists(10);
      artists->printList();
      delete artists;
      break;

    //[1] - Arquivo .csv
    case 1:
      artists = testReadBinaryArtists(100);
      createArtistsCSVFile(artists);
      delete artists;
      break;

    //[8] - Voltar menu principal
    case 8:
      return;

    //[9] - Sair
    case 9:
      cout << "bye\n";
      exit(1);
      break;

    default:
      cout << "Erro: Digite uma opcao valida.\n";
      break;
    }
  }
}
