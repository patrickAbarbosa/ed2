#ifndef ARTISTLIST_H_INCLUDED
#define ARTISTLIST_H_INCLUDED

#include "./NodeArtist.h"

class ArtistList {
	public:
		ArtistList();
		~ArtistList();

    void insertEnd(Artist *artist);
    void insertInIndex(Artist *artist, int index);
    NodeArtist* getFirstArtist();
    void printList();

  private:
    NodeArtist *first;
    NodeArtist *last;
    int size;
};

#endif
