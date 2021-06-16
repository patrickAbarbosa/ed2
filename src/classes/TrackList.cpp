#include "../headers/TrackList.h"
#include <iostream>

using namespace std;

TrackList::TrackList() {
  first = NULL;
  last = NULL;
  size = 0;
}

TrackList::~TrackList() {
  while (first != NULL) {
    NodeTrack *nextTrack = first->getNext();
    delete first;
    first = nextTrack;
  }

  size = 0;
}

void TrackList::insertEnd(Track *track) {
  NodeTrack * node = new NodeTrack(track);
  size++;

  if (last == NULL) {
    first = node;
    last = node;

    return;
  }

  last->setNext(node);
  last = node;
}

void TrackList::insertInIndex(Track *track, int index) {
  if (index >= size) {
    cout << "ERROR: Insert in index." << endl;

    exit(1);
  }

  NodeTrack * node = new NodeTrack(track);

  for (NodeTrack *currentTrack = first; first != NULL && index >= 0; first = first->getNext()) {
    if (index == 1) {
      node->setNext(currentTrack->getNext());
      currentTrack->setNext(node);

      size++;
      return;
    }

    index--;
  }
}

void TrackList::printList() {
  if (first == NULL) {
    cout << "List Empty" << endl;
    return;
  }

  NodeTrack *node = first;

  while (node != NULL) {
    Track *track = node->getTrack();

    printf("id: %s, name: %s\n", track->id, track->name);

    node = node->getNext();
  }
}

NodeTrack *TrackList::getFirstTrack() {
  return first;
}
