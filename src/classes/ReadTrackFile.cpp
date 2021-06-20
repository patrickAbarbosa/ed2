#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "../headers/ReadTrackFile.h"
#include "../headers/Helpers.h"

using namespace std;

/**
 * ReadTracksFile
 *
 * inicia variáveis da classe
 */
ReadTrackFile::ReadTrackFile(string tracksFileLocation) {
  this->tracksFileLocation = tracksFileLocation;
  this->binaryFileLocation = "../bin/Tracks.bin";
}

ReadTrackFile::~ReadTrackFile() {}

/**
 * calculateColumn
 *
 * Retorna a coluna em bytes que o valor se encontra
 *
 * @param {string} variableName Nome da variável a ser lida
 *
 * @return {int} posição inicial da variável
*/
int ReadTrackFile::calculateColumn(string variableName) {
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
 * @param {string} variableName
 * @return {int} currentLine retorna a posição da variável dentro do arquivo binário
 *
 */
int ReadTrackFile::calculateBinaryTrackPosition(string variableName, int currentLine) {
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
void ReadTrackFile::readTrackLine(string line, ofstream *binaryFile) {
  printf(".");
  Helpers helper;
  stringstream _line(line);

  Track track;
  string str;

  str = helper.readValue(&_line);
  strcpy(track.id, str.c_str());
  binaryFile->write(track.id, sizeof(track.id));

  str = helper.readValue(&_line);
  strcpy(track.name, str.c_str());
  binaryFile->write(track.name, sizeof(track.name));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.popularity));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.duration_ms));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.isExplicit));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.artists));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.id_artists));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.release_date));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.danceability));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.energy));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.key));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.loudness));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.mode));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.speechiness));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.acousticness));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.instrumentalness));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.liveness));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.valence));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.tempo));

  str = helper.readValue(&_line);
  binaryFile->write(str.c_str(), sizeof(track.time_signature));
}

Track* ReadTrackFile::readBinaryTrackLine(ifstream *binaryFile) {
  Track auxliaryTrack;
  Track *track = new Track;
  char *str;
  int length;

  binaryFile->read(track->id, 22);
  binaryFile->read(track->name, 255);

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

/**
 * readTracks
 *
 * le arquivo .csv de Tracks e retorna uma lista de tracks
 *
 * @return {TrackList*}
 */
void ReadTrackFile::readTracks() {
  fstream file(tracksFileLocation, fstream::in);

  if (!file.is_open()) {
    cout << "Erro ao abrir arquivo." << endl;

    exit(1);
  }

  ofstream binaryFile(binaryFileLocation, ofstream::binary);

  if (!binaryFile.is_open()) {
    cout << "Erro ao abrir arquivo binario" << endl;

    exit(1);
  }

  string currentLine;
  getline(file, currentLine); // Remove primeira linha do csv

  while (!file.eof()) {
    getline(file, currentLine);

    if (currentLine.length() > 0) {
      readTrackLine(currentLine, &binaryFile);
    }
  }

  cout << endl;

  file.close();
  binaryFile.close();
}

/**
 * readBinaryTracks
 *
 * Lê arquivo binário de tracks e retorna uma lista encadeada de Tracks
 *
 * @return {TrackList*}
 */
TrackList *ReadTrackFile::readBinaryTracks() {
  ifstream binaryFile(binaryFileLocation, ifstream::in | ifstream::binary);

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
 * createTracksCSVFile
 *
 * cria um arquivo tracks_test.csv na pasta principal do projeto
 *
 * @param {TrackList*} tracks Uma lista de Tracks a ser inseridas no arquivo
 */
void ReadTrackFile::createTracksCSVFile(TrackList *tracks) {
  ofstream csvFile("../tracks_test.csv");

  if (!csvFile.is_open()) {
    cout << "Nao foi possivel abrir o arquivo tracks_test.csv" << endl;
    exit(1);
  }

  csvFile << "id,name,popularity,duration_ms,explicit,artists,id_artists,release_date,danceability,energy,key,loudness,mode,speechiness,acousticness,instrumentalness,liveness,valence,tempo,time_signature" << endl;

  NodeTrack *track = tracks->getFirstTrack();

  while (track != NULL) {
    Track *_track = track->getTrack();

    if (_track) {
      csvFile
      << _track->id << ','
      << '"'<< _track->name << '"' << ','
      << to_string(_track->popularity) << ","
      << _track->duration_ms << ','
      << _track->isExplicit << ','
      << "[" << _track->artists << "],"
      << "[" << _track->id_artists << "],"
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

    track = track->getNext();
  }

  cout << "tracks_test.csv criado com sucesso!\n\n";

  csvFile.close();
}

TrackList *ReadTrackFile::testReadBinaryTracks(int numberOfTracks) {
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

  printf("Tamanho do arquivo: %d bytes\n", fileSize);
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

/**
 * printStruct
 *
 * imprime na tela a estrutura de Tracks
 */
void ReadTrackFile::printStruct() {
  cout << "------ Track Struct -------" << endl;
    cout << "char id[22]\n";
    cout << "char name[255]\n";
    cout << "int popularity\n";
    cout << "int duration_ms\n";
    cout << "bool isExplicit\n";
    cout << "char artists[1000]\n";
    cout << "char id_artists[440]\n";
    cout << "char release_date[10]\n";
    cout << "float danceability\n";
    cout << "float energy\n";
    cout << "int key\n";
    cout << "float loudness\n";
    cout << "bool mode\n";
    cout << "float speechiness\n";
    cout << "float acousticness\n";
    cout << "float instrumentalness\n";
    cout << "float liveness\n";
    cout << "float valence\n";
    cout << "float tempo\n";
    cout << "int time_signature\n";

    cout << endl;
}

void ReadTrackFile::testBinaryTrackFile() {
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
    //[0] - Exibir em tela
    case 0:
      tracks = testReadBinaryTracks(10);
      tracks->printList();
      delete tracks;
      break;

    //[1] - Arquivo .csv
    case 1:
      tracks = testReadBinaryTracks(1);
      createTracksCSVFile(tracks);
      delete tracks;
      break;

    //[8] - Voltar menu principal
    case 8:
      cout << "Retornando ao menu anterior\n\n";
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
