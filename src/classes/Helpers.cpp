#include "../headers/Helpers.h"
#include <iostream>
#include <sstream>

Helpers::Helpers(){};
Helpers::~Helpers(){};

/**
 * readValue
 *
 * Retorna o primeiro valor de um stringstream
 *
 * @param line
*/
string Helpers::readValue(stringstream *line) {
  if (line == NULL) {
    return "undefined";
  }

  string str;
  bool hasFirstCharacter = false;
  char firstCharacter = line->get();
  char endCharacter;

  if (firstCharacter == '[') {
    endCharacter = ']';
  } else if (firstCharacter == '"') {
    int occurrence = 0;
    char aux = '"';
    string _str = "";

    while(aux == '"') {
      getline(*line, str, '"');
      _str += str;
      aux = line->get();

      if (aux == ',') {
        break;
      } else {
        if(aux == '"') {
          occurrence = occurrence == 1 ? 0 : 1;
          str += '"';
        }

        _str += aux;
      }
    }

    return _str;
  } else if (firstCharacter == 39) {
    endCharacter = 39;
  } else {
    endCharacter = ',';
    hasFirstCharacter = true;
  }

  getline(*line, str, endCharacter);

  if (endCharacter != ',') {
    string lixo;

    getline(*line, lixo, ',');
  }

  if (hasFirstCharacter) {
    str = firstCharacter + str;
  }

  return str;
}
