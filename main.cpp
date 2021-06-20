#include <iostream>
#include "./src/headers/Menu.h"

using namespace std;

/**
 * main
 *
 * @param {int} argc Número de argumentos passados no terminal
 * @param {char*[]} argv Argumentos passados po no terminal
 */
int main (int argc, char *argv[]) {
  string trackFileLocation = "";
  string artistFileLocation = "";

  if (argc >= 2) {
    trackFileLocation = argv[1];
  }
  if (argc >= 3) {
    artistFileLocation = argv[2];
  }

  Menu menuInterface(trackFileLocation, artistFileLocation);
  menuInterface.visible();

  return 0;
}
