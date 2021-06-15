#ifndef ARTIST_H
#define ARTIST_H

struct Artist {
  char id[22];
  float followers;
  char genres[255];
  char name[255];
  int popularity;
};

#endif
