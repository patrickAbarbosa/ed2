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

string ReadFile::readValue(stringstream *line) {
  string str;
  getline(*line, str, ',');

  if (str[0] != '[' && str[0] != 39 && str[0] != '"') {
    return str;
  }

  string remainingValue = "";
  char endCharacter;

  if (str[0] == '[') {
    endCharacter = ']';
  } else if (str[0] == '"') {
    endCharacter = '"';
  } else {
    endCharacter = 39;
  }

  getline(*line, remainingValue, endCharacter);
  string value = str.substr(1, str.length()) + ',' +  remainingValue;
  return value;
}

Track* ReadFile::readTrackLine(string line) {
  stringstream _line(line);

  Track *track = new Track;
  string str;
  int count = 0;

  str = readValue(&_line);
  strcpy(track->id, str.c_str());
  str = readValue(&_line);
  strcpy(track->name, str.c_str());
  str = readValue(&_line);
  track->popularity = atoi(str.c_str());
  str = readValue(&_line);
  track->duration_ms = atoi(str.c_str());
  str = readValue(&_line);
  track->isExplicit = atoi(str.c_str());
  str = readValue(&_line);
  strcpy(track->artists, str.c_str());
  str = readValue(&_line);
  strcpy(track->id_artists, str.c_str());
  str = readValue(&_line);
  strcpy(track->release_date, str.c_str());
  str = readValue(&_line);
  track->danceability = atoi(str.c_str());
  str = readValue(&_line);
  track->energy = atoi(str.c_str());
  str = readValue(&_line);
  track->key = atoi(str.c_str());
  str = readValue(&_line);
  track->loudness = atoi(str.c_str());
  str = readValue(&_line);
  track->speechiness = atoi(str.c_str());
  str = readValue(&_line);
  track->acousticness = atoi(str.c_str());
  str = readValue(&_line);
  track->instrumentalness = atoi(str.c_str());
  str = readValue(&_line);
  track->liveness = atoi(str.c_str());
  str = readValue(&_line);
  track->valence = atoi(str.c_str());
  str = readValue(&_line);
  track->tempo = atoi(str.c_str());
  str = readValue(&_line);
  track->time_signature = atoi(str.c_str());

  return track;
}

TrackList *ReadFile::readTracks() {
  string fullFileLocation = "../../tracks_example.csv" + fileLocation;
  fstream file(fullFileLocation, fstream::in);

  if (!file.is_open()) {
    cout << "Could not open the file" << endl;

    exit(1);
  }

  ofstream tracksFile("bin/tracks.bin", ofstream::out);
  string currentLine;
  TrackList *list = new TrackList();
  getline(file, currentLine); // Remove first line csv

  while (!file.eof()) {
    getline(file, currentLine);

    if (currentLine.length() > 0) {
      Track *currentTrack = readTrackLine(currentLine);
      list->insertEnd(currentTrack);
    }
  }

  return list;
}
