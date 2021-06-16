#ifndef NODELIST_H_INCLUDED
#define NODELIST_H_INCLUDED

#include "./NodeTrack.h"

class TrackList {
	public:
		TrackList();
		~TrackList();

    void insertEnd(Track *track);
    void insertInIndex(Track *track, int index);
    NodeTrack *getFirstTrack();
    void printList();

  private:
    NodeTrack *first;
    NodeTrack *last;
    int size;
};

#endif
