#ifndef NODEARTIST_H_INCLUDED
#define NODEARTIST_H_INCLUDED

#include <iostream>
#include "./Artist.h"

class NodeArtist {
	public:
		NodeArtist(Artist *artist) { this->artist = artist; nextArtist = NULL; };
		~NodeArtist() { delete artist; };

    Artist* getArtist() { return artist; };
    NodeArtist *getNext() { return nextArtist; };
    void setNext(NodeArtist *nextArtist) { this->nextArtist = nextArtist; };

  private:
    Artist *artist;
    NodeArtist *nextArtist;
};

#endif
