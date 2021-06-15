#include "../headers/ArtistList.h"
#include <iostream>

using namespace std;

ArtistList::ArtistList() {
  first = NULL;
  last = NULL;
  size = 0;
}

ArtistList::~ArtistList() {
  while (first != NULL) {
    NodeArtist *nextArtist = first->getNext();
    delete first;
    first = nextArtist;
  }

  size = 0;
}

void ArtistList::insertEnd(Artist *artist) {
  NodeArtist * node = new NodeArtist(artist);
  size++;

  if (last == NULL) {
    first = node;
    last = node;

    return;
  }

  last->setNext(node);
  last = node;
}

void ArtistList::insertInIndex(Artist *artist, int index) {
  if (index >= size) {
    cout << "ERROR: Insert in index." << endl;

    exit(1);
  }

  NodeArtist * node = new NodeArtist(artist);

  for (NodeArtist *currentArtist = first; first != NULL && index >= 0; first = first->getNext()) {
    if (index == 1) {
      node->setNext(currentArtist->getNext());
      currentArtist->setNext(node);

      size++;
      return;
    }

    index--;
  }
}

void printChar(char *str, int size) {
  for (int index = 0; index < size; index++) {
    cout << str[index];
  }
}

void ArtistList::printList() {
  if (first == NULL) {
    cout << "Lista vazia" << endl;
    return;
  }

  NodeArtist *node = first;

  while (node != NULL) {
    Artist *artist = node->getArtist();
    printf("id: %s, name: %s\n", artist->id, artist->name);

    node = node->getNext();
  }
}
