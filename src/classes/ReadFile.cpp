#include "../headers/ReadFile.h"
#include "../headers/Track.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

ReadFile::ReadFile(string fileLocation) {
  this->fileLocation = fileLocation;
}

ReadFile::~ReadFile() {
  cout << "End Read File" << endl;
}

/**
 * readValue
 *
 * Retorna o primeiro valor de um stringstream
 *
 * @param line
*/
string ReadFile::readValue(stringstream *line) {
  string str;
  bool hasFirstCharacter = false;
  char firstCharacter = line->get();
  char endCharacter;

  if (firstCharacter == '[') {
    endCharacter = ']';
  } else if (firstCharacter == '"') {
    endCharacter = '"';
  } else if (firstCharacter == 39) {
    endCharacter = 39;
  } else {
    endCharacter = ',';
    hasFirstCharacter = true;
  }

  getline(*line, str, endCharacter);

  if (endCharacter != ',') {
    string lixo;

    getline(*line, lixo, ',');
  }

  return hasFirstCharacter ? firstCharacter + str : str;
}

/**
 * calculateColumn
 *
 * Retorna a coluna em bytes que o elemento se encontra
 *
 * @param variableName
*/
int calculateColumn(string variableName) {
  Track track;
  int column = 0;

  if (variableName == "id"){
    return column;
  }
  column += sizeof(track.id);

  if (variableName == "name"){
    return column;
  }
  column += sizeof(track.name);

  if (variableName == "popularity"){
    return column;
  }
  column += sizeof(track.popularity);

  if (variableName == "duration_ms"){
    return column;
  }
  column += sizeof(track.duration_ms);

  if (variableName == "isExplicit"){
    return column;
  }
  column += sizeof(track.isExplicit);

  if (variableName == "artists"){
    return column;
  }
  column += sizeof(track.artists);

  if (variableName == "id_artists"){
    return column;
  }
  column += sizeof(track.id_artists);

  if (variableName == "release_date"){
    return column;
  }
  column += sizeof(track.release_date);

  if (variableName == "danceability"){
    return column;
  }
  column += sizeof(track.danceability);

  if (variableName == "energy"){
    return column;
  }
  column += sizeof(track.energy);

  if (variableName == "key"){
    return column;
  }
  column += sizeof(track.key);

  if (variableName == "loydness"){
    return column;
  }
  column += sizeof(track.loudness);

  if (variableName == "speechiness"){
    return column;
  }
  column += sizeof(track.speechiness);

  if (variableName == "acousticness"){
    return column;
  }
  column += sizeof(track.acousticness);

  if (variableName == "instrumentalness"){
    return column;
  }
  column += sizeof(track.instrumentalness);

  if (variableName == "liveness"){
    return column;
  }
  column += sizeof(track.liveness);

  if (variableName == "valence"){
    return column;
  }
  column += sizeof(track.valence);

  if (variableName == "tempo"){
    return column;
  }
  column += sizeof(track.tempo);

  if (variableName == "tempo"){
    return column;
  }
  column += sizeof(track.time_signature);

  return column;
}

/**
 * calculateBinaryPosition
 *
 * Retorna a posição binaria de uma variável em determinada "linha"
 *
 * @param variableName
 * @param currentLine
 */
int calculateBinaryPosition(string variableName, int currentLine) {
  int _linearLine = calculateColumn("") * currentLine;

  return _linearLine + calculateColumn(variableName);
}

Track* ReadFile::readTrackLine(string line, ofstream *binaryFile) {
  stringstream _line(line);

  Track *track = new Track;
  string str;
  int count = 0;

  str = readValue(&_line);
  strcpy(track->id, str.c_str());
  *binaryFile << track->id;

  str = readValue(&_line);
  strcpy(track->name, str.c_str());
  *binaryFile << track->name;

  str = readValue(&_line);
  track->popularity = atoi(str.c_str());
  *binaryFile << track->popularity;

  str = readValue(&_line);
  track->duration_ms = atoi(str.c_str());
  *binaryFile << track->duration_ms;

  str = readValue(&_line);
  track->isExplicit = atoi(str.c_str());
  *binaryFile << track->isExplicit;

  str = readValue(&_line);
  strcpy(track->artists, str.c_str());
  *binaryFile << track->artists;

  str = readValue(&_line);
  strcpy(track->id_artists, str.c_str());
  *binaryFile << track->id_artists;

  str = readValue(&_line);
  strcpy(track->release_date, str.c_str());
  *binaryFile << track->release_date;

  str = readValue(&_line);
  track->danceability = atoi(str.c_str());
  *binaryFile << track->danceability;

  str = readValue(&_line);
  track->energy = atoi(str.c_str());
  *binaryFile << track->energy;

  str = readValue(&_line);
  track->key = atoi(str.c_str());
  *binaryFile << track->key;

  str = readValue(&_line);
  track->loudness = atoi(str.c_str());
  *binaryFile << track->loudness;

  str = readValue(&_line);
  track->speechiness = atoi(str.c_str());
  *binaryFile << track->speechiness;

  str = readValue(&_line);
  track->acousticness = atoi(str.c_str());
  *binaryFile << track->acousticness;

  str = readValue(&_line);
  track->instrumentalness = atoi(str.c_str());
  *binaryFile << track->instrumentalness;

  str = readValue(&_line);
  track->liveness = atoi(str.c_str());
  *binaryFile << track->liveness;

  str = readValue(&_line);
  track->valence = atoi(str.c_str());
  *binaryFile << track->valence;

  str = readValue(&_line);
  track->tempo = atoi(str.c_str());
  *binaryFile << track->tempo;

  str = readValue(&_line);
  track->time_signature = atoi(str.c_str());
  *binaryFile << track->time_signature;

  return track;
}

TrackList *ReadFile::readTracks() {
  string fullFileLocation = "../../tracks_example.csv"; // + fileLocation;
  fstream file(fullFileLocation, fstream::in);

  if (!file.is_open()) {
    cout << "Erro ao abrir arquivo." << endl;

    exit(1);
  }

  ofstream binaryFile("../bin/tracks.bin", ofstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario" << endl;

    exit(1);
  }

  string currentLine;
  TrackList *list = new TrackList();
  getline(file, currentLine); // Remove first line csv

  while (!file.eof()) {
    getline(file, currentLine);

    if (currentLine.length() > 0) {
      Track *currentTrack = readTrackLine(currentLine, &binaryFile);
      list->insertEnd(currentTrack);
    }
  }

  file.close();
  binaryFile.close();

  return list;
}
