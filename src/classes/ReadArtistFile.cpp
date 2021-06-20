#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "../headers/ReadArtistFile.h"
#include "../headers/Helpers.h"

using namespace std;

ReadArtistFile::ReadArtistFile(string artistsFileLocation) {
  this->artistsFileLocation = artistsFileLocation;
  this->binaryFileLocation = "../../bin/Artists.bin";
}

ReadArtistFile::~ReadArtistFile() {}

/**
 * readBinaryArtistLine
 *
 * @param {ifstream*} binaryFile endereço do ifstream
 * @param {int} index
 */
Artist *ReadArtistFile::readBinaryArtistLine(ifstream *binaryFile, int index) {
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
 * readArtists
 *
 * le .csv de Artists e retorna uma lista encadeada de Artists
 *
 * @return *ArtistList
 */
ArtistList *ReadArtistFile::readArtists() {
  fstream file(artistsFileLocation, fstream::in);

  if (!file.is_open()) {
    cout << "Erro ao abrir arquivo artists." << endl;
    cout << file.fail() << endl;
    exit(1);
  }

  ofstream binaryFile(binaryFileLocation, ofstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario." << endl;
    cout << "Diretorio: " <<binaryFileLocation << endl;

    exit(1);
  }

  string currentLine;
  ArtistList *list = new ArtistList();

  getline(file, currentLine); // Remove primeira linha do csv

  while (!file.eof()) {
    getline(file, currentLine);

    if (currentLine.length() > 0) {
      Artist *currentArtist = readArtistLine(currentLine, &binaryFile);
      list->insertEnd(currentArtist);
    }
  }

  file.close();
  binaryFile.close();

  return list;
}

/**
 * readArtistLine
 *
 * Retorna um objeto Artist
 *
 * @param line
 * @param *binaryFile
 *
 */
Artist* ReadArtistFile::readArtistLine(string line, ofstream *binaryFile) {
  Helpers helper;
  stringstream _line(line);

  Artist *artist = new Artist;
  string str;

  str = helper.readValue(&_line);
  strcpy(artist->id, str.c_str());
  binaryFile->write(artist->id, sizeof(artist->id));

  str = helper.readValue(&_line);
  artist->followers = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(artist->followers));

  str = helper.readValue(&_line);
  strcpy(artist->genres, str.c_str());
  binaryFile->write(artist->genres, sizeof(artist->genres));

  str = helper.readValue(&_line);
  strcpy(artist->name, str.c_str());
  binaryFile->write(artist->name, sizeof(artist->name));

  str = helper.readValue(&_line);
  artist->popularity = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(artist->popularity));

  return artist;
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
    Artist *artist = readBinaryArtistLine(&binaryFile, index);

    list->insertEnd(artist);
  }

  binaryFile.close();

  return list;
}
