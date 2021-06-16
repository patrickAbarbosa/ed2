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

  if (variableName == "mode"){
    return column;
  }
  column += sizeof(track.mode);

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

  if (variableName == "time_signature"){
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
int ReadFile::calculateBinaryTrackPosition(string variableName, int currentLine) {
  int _linearLine = calculateColumn("") * currentLine;

  return _linearLine;
}

/**
 * readTrackLine
 *
 * Retorna um objeto Track
 *
 * @param line
 * @param *binaryFile
 */
Track* ReadFile::readTrackLine(string line, ofstream *binaryFile) {
  stringstream _line(line);

  Track *track = new Track;
  string str;

  str = readValue(&_line);
  strcpy(track->id, str.c_str());
  binaryFile->write(track->id, sizeof(track->id));

  str = readValue(&_line);
  strcpy(track->name, str.c_str());
  binaryFile->write(track->name, sizeof(track->name));

  str = readValue(&_line);
  track->popularity = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->popularity));

  str = readValue(&_line);
  track->duration_ms = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->duration_ms));

  str = readValue(&_line);
  track->isExplicit = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->isExplicit));

  str = readValue(&_line);
  strcpy(track->artists, str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->artists));

  str = readValue(&_line);
  strcpy(track->id_artists, str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->id_artists));

  str = readValue(&_line);
  strcpy(track->release_date, str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->release_date));

  str = readValue(&_line);
  track->danceability = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->danceability));

  str = readValue(&_line);
  track->energy = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->energy));

  str = readValue(&_line);
  track->key = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->key));

  str = readValue(&_line);
  track->loudness = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->loudness));

  str = readValue(&_line);
  track->mode = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->mode));

  str = readValue(&_line);
  track->speechiness = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->speechiness));

  str = readValue(&_line);
  track->acousticness = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->acousticness));

  str = readValue(&_line);
  track->instrumentalness = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->instrumentalness));

  str = readValue(&_line);
  track->liveness = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->liveness));

  str = readValue(&_line);
  track->valence = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->valence));

  str = readValue(&_line);
  track->tempo = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->tempo));

  str = readValue(&_line);
  track->time_signature = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(track->time_signature));

  return track;
}

TrackList *ReadFile::readTracks() {
  string fullFileLocation = "../../" + fileLocation;
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

Track* ReadFile::readBinaryTrackLine(ifstream *binaryFile) {
  Track auxliaryTrack;
  Track *track = new Track;
  char *str;
  int length;

  binaryFile->read(track->id, sizeof(auxliaryTrack.id));

  binaryFile->read(track->name, sizeof(auxliaryTrack.name));

  length = sizeof(auxliaryTrack.popularity);
  str = new char[length];
  binaryFile->read(str, length);
  track->popularity = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.duration_ms);
  str = new char[length];
  binaryFile->read(str, length);
  track->duration_ms = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.isExplicit);
  str = new char[length];
  binaryFile->read(str, length);
  track->isExplicit = atoi(str);
  delete [] str;

  binaryFile->read(track->artists, sizeof(auxliaryTrack.artists));

  binaryFile->read(track->id_artists, sizeof(auxliaryTrack.id_artists));

  binaryFile->read(track->release_date, sizeof(auxliaryTrack.release_date));

  length = sizeof(auxliaryTrack.danceability);
  str = new char[length];
  binaryFile->read(str, length);
  track->danceability = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.energy);
  str = new char[length];
  binaryFile->read(str, length);
  track->energy = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.key);
  str = new char[length];
  binaryFile->read(str, length);
  track->key = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.loudness);
  str = new char[length];
  binaryFile->read(str, length);
  track->loudness = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.speechiness);
  str = new char[length];
  binaryFile->read(str, length);
  track->speechiness = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.acousticness);
  str = new char[length];
  binaryFile->read(str, length);
  track->acousticness = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.instrumentalness);
  str = new char[length];
  binaryFile->read(str, length);
  track->instrumentalness = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.liveness);
  str = new char[length];
  binaryFile->read(str, length);
  track->liveness = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.valence);
  str = new char[length];
  binaryFile->read(str, length);
  track->valence = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.tempo);
  str = new char[length];
  binaryFile->read(str, length);
  track->tempo = atoi(str);
  delete [] str;

  length = sizeof(auxliaryTrack.time_signature);
  str = new char[length];
  binaryFile->read(str, length);
  track->time_signature = atoi(str);
  delete [] str;

  return track;
}

TrackList *ReadFile::readBinaryTracks() {
  ifstream binaryFile("../bin/tracks.bin", ifstream::in | ifstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario" << endl;

    exit(1);
  }

  string currentLine;
  TrackList *list = new TrackList();

  binaryFile.seekg (0, binaryFile.end);
  int fileSize = binaryFile.tellg();
  binaryFile.seekg (0, binaryFile.beg);
  for (int index = 0; !binaryFile.eof() && binaryFile.tellg() < fileSize; index++) {
    Track *track = readBinaryTrackLine(&binaryFile);

    list->insertEnd(track);
  }

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
Artist* ReadFile::readArtistLine(string line, ofstream *binaryFile) {
  stringstream _line(line);

  Artist *artist = new Artist;
  string str;

  str = readValue(&_line);
  strcpy(artist->id, str.c_str());
  binaryFile->write(artist->id, sizeof(artist->id));

  str = readValue(&_line);
  artist->followers = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(artist->followers));

  str = readValue(&_line);
  strcpy(artist->genres, str.c_str());
  binaryFile->write(artist->genres, sizeof(artist->genres));

  str = readValue(&_line);
  strcpy(artist->name, str.c_str());
  binaryFile->write(artist->name, sizeof(artist->name));

  str = readValue(&_line);
  artist->popularity = atoi(str.c_str());
  binaryFile->write(str.c_str(), sizeof(artist->popularity));

  return artist;
}

ArtistList *ReadFile::readArtists() {
  string fullFileLocation = "../artists_example.csv"; //+ fileLocation;
  fstream file(fullFileLocation, fstream::in);

  if (!file.is_open()) {
    cout << "Erro ao abrir arquivo artists." << endl;
    cout << file.fail() << endl;
    exit(1);
  }

  ofstream binaryFile("../bin/artists.bin", ofstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario." << endl;
    cout << "Diretorio: <projectFolder>/bin/artists.bin" << endl;

    exit(1);
  }

  string currentLine;
  ArtistList *list = new ArtistList();
  getline(file, currentLine); // Remove first line csv

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

Artist *ReadFile::readBinaryArtistLine(ifstream *binaryFile, int index) {
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

ArtistList *ReadFile::readBinaryArtists() {
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

TrackList *ReadFile::testReadBinaryTracks(int numberOfTracks) {
  ifstream binaryFile("../bin/tracks.bin", ifstream::in | ifstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario de Tracks" << endl;
    exit(1);
  }

  TrackList *list = new TrackList;

  binaryFile.seekg (0, binaryFile.end);
  int fileSize = binaryFile.tellg();
  binaryFile.seekg (0, binaryFile.beg);
  int totalTracks = ceil(float(float(fileSize) / calculateColumn("")));

  printf("Total: %d\n", fileSize);
  srand(time(NULL));
  for (;numberOfTracks > 0; numberOfTracks--) {
    binaryFile.clear();

    int currentIndex = (int (rand() % totalTracks)) ;
    int position = calculateBinaryTrackPosition("", currentIndex);
    binaryFile.seekg(position, binaryFile.beg);
    Track *track = readBinaryTrackLine(&binaryFile);

    list->insertEnd(track);
  }

  return list;
}

void ReadFile::createTracksCSVFile(TrackList *tracks) {
  ofstream csvFile("../tracks_test.csv");

  if (!csvFile.is_open()) {
    cout << "Nao foi possivel abrir o arquivo tracks_test_csv" << endl;
    exit(1);
  }

  csvFile << "id,name,popularity,duration_ms,explicit,artists,id_artists,release_date,danceability,energy,key,loudness,mode,speechiness,acousticness,instrumentalness,liveness,valence,tempo,time_signature" << endl;

  NodeTrack *track = tracks->getFirstTrack();

  while (track !== NULL) {
    Track *_track = track->getTrack();

    csvFile
    << _track->id
    << _track->name
    << _track->popularity << ','
    << _track->duration_ms << ','
    << _track->isExplicit << ','
    << _track->artists << ','
    << _track->id_artists << ','
    << _track->release_date << ','
    << _track->danceability << ','
    << _track->energy << ','
    << _track->key << ','
    << _track->loudness << ','
    << _track->mode << ','
    << _track->speechiness << ','
    << _track->acousticness << ','
    << _track->instrumentalness << ','
    << _track->liveness << ','
    << _track->valence << ','
    << _track->tempo << ','
    << _track->time_signature << endl;
  }
}

void ReadFile::testBinaryTrackFile() {
  int menuOption = -1;
  TrackList *tracks = NULL;

  while (menuOption != 9) {
    cout << "------- Teste Tracks ------\n";
    cout << "[0] - Exibir em tela\n";
    cout << "[1] - Arquivo .csv\n";
    cout << "[8] - Voltar menu principal\n";
    cout << "[9] - Sair\n";
    cout << "\nDigite uma opcao: ";
    cin >> menuOption;

    switch (menuOption) {
    case 0:
      tracks = testReadBinaryTracks(10);
      tracks->printList();
      delete tracks;
      break;

    case 1:
      cout << "Exibir em tela 100 resultados\n";
      break;

    case 8:
      cout << "Retornando ao menu anterior\n\n";
      return;
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
