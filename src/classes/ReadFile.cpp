#include "../headers/ReadFile.h"
#include "../headers/Track.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

/**
 * ReadFile
 *
 * atribui valores iniciais a todas variáveis necessárias
 *
 * @param {string} tracksFileLocation Endereço do local do arquivos de Tracks
 * @param {string} artistsFileLocation Endereço do local do arquivos de Artists
 */
ReadFile::ReadFile(string tracksFileLocation, string artistsFileLocation) {
  readTracks = new ReadTrackFile(tracksFileLocation);
  readArtists = new ReadArtistFile(artistsFileLocation);
}

/**
 * ~ReadFile
 *
 * Deleta todas as variáveis dinâmicas
 */
ReadFile::~ReadFile() {
  delete readTracks;
  delete readArtists;
}

/**
 * testBinaryTrackFile
 *
 * Chama o método de teste de ReadTrackFile
 */
void ReadFile::readTracksFile() {
  if (readTracks) {
    readTracks->readTracks();
  }
}

/**
 * testBinaryTrackFile
 *
 * Chama o método de teste de ReadTrackFile
 */
void ReadFile::readArtistsFile() {
  if (readArtists) {
    readArtists->readArtists();
  }
}

/**
 * printTrackStruct
 *
 * Imprime no console a estrutura Track
 */
void ReadFile::printTrackStruct() {
  readTracks->printStruct();
}

/**
 * testBinaryTrackFile
 *
 * Chama o método de teste de ReadTrackFile
 */
void ReadFile::testBinaryTrackFile() {
  if (readTracks) {
    readTracks->testBinaryTrackFile();
  }
}

/**
 * printArtistStruct
 *
 * Imprime no console a estrutura Artists
 */
void ReadFile::printArtistStruct() {
  readArtists->printStruct();
}

/**
 * testBinaryArtistFile
 *
 * chama o método de teste de ReadArtistFile
 */
void ReadFile::testBinaryArtistFile() {
  if (readArtists) {
    readArtists->testBinaryArtistFile();
  }
}
