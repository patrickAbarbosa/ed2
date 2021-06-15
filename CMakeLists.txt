cmake_minimum_required(VERSION 3.12)
project(TrabalhoED2 VERSION 0.0.1)

set(DIRECTORY src)
include_directories(${DIRECTORY})

set(SOURCES
  ./main.cpp
  ${DIRECTORY}/classes/Menu.cpp
  ${DIRECTORY}/headers/Menu.h
  ${DIRECTORY}/classes/ReadFile.cpp
  ${DIRECTORY}/headers/ReadFile.h
  ${DIRECTORY}/classes/TrackList.cpp
  ${DIRECTORY}/headers/TrackList.h
  ${DIRECTORY}/headers/Track.h
  ${DIRECTORY}/headers/NodeTrack.h
  ${DIRECTORY}/classes/ArtistList.cpp
  ${DIRECTORY}/headers/ArtistList.h
  ${DIRECTORY}/headers/Artist.h
  ${DIRECTORY}/headers/NodeArtist.h
)
add_executable(cmake-good ${SOURCES})
