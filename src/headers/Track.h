#ifndef TRACK_H
#define TRACK_H

struct Track {
  char id[22];
  char name[255];
  int popularity;
  int duration_ms;
  bool isExplicit;
  char artists[1000];
  char id_artists[440];
  char release_date[10];
  float danceability;
  float energy;
  int key;
  float loudness;
  bool mode;
  float speechiness;
  float acousticness;
  float instrumentalness;
  float liveness;
  float valence;
  float tempo;
  int time_signature;
};

#endif
