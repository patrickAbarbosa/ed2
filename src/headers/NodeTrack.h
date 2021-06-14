#ifndef NODETRACK_H_INCLUDED
#define NODETRACK_H_INCLUDED

#include <iostream>
#include "./Track.h"

class NodeTrack {
	public:
		NodeTrack(Track *track) { this->track = track; nextTrack = NULL; };
		~NodeTrack() { delete track; };

    Track *getTrack() { return track; };
    NodeTrack *getNext() { return nextTrack; };
    void setNext(NodeTrack *nextTrack) { this->nextTrack = nextTrack; };

  private:
    Track *track;
    NodeTrack *nextTrack;
};

#endif
