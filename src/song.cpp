#include <iostream>
#include <string>
using namespace std;
#include "song.hpp"
Song::Song() {}

Song::Song(const Song& other)
    : name(other.name),
      author(other.author),
      player(other.player),
      rank(other.rank),
      mp3File(other.mp3File) {}

std::string Song::getName() const { return name; }

Name Song::getAuthor() const { return author; }

Name Song::getPlayer() const { return player; }

int Song::getRank() const { return rank; }

std::string Song::getMp3File() const { return mp3File; }

void Song::setName(const string& n) { name = n; }

void Song::setAuthor(const Name& a) { author = a; }

void Song::setPlayer(const Name& p) { player = p; }

void Song::setRank(const int& r) { rank = r; }

void Song::setMp3File(const std::string& f) { mp3File = f + ".mp3"; }

string Song::toString() const {
  string result;

  result += "|Nombre: " + name;
  result.resize(33, ' ');
  result += "|Autor: " + author.toString();
  result.resize(56, ' ');
  result += "|Interprete: " + player.toString();
  result.resize(85, ' ');
  result += "|Ranking: " + std::to_string(rank);
  result.resize(98, ' ');
  result += "|Archivo MP3: " + mp3File + ".mp3";
  result.resize(147, ' ');
  result += " |";
  return result;
}

Song& Song::operator=(const Song& other) {
  name = other.name;
  author = other.author;
  player = other.player;
  rank = other.rank;
  mp3File = other.mp3File;

  return *this;
}

bool Song::operator==(const Song& other) const {
  return this->rank == other.rank;
}

bool Song::operator!=(const Song& other) const { return !(*this == other); }

bool Song::operator<(const Song& other) const {
  return this->rank < other.rank;
}

bool Song::operator<=(const Song& other) const { return !(*this > other); }

bool Song::operator>=(const Song& other) const { return !(*this < other); }

bool Song::operator>(const Song& other) const {
  return !(*this < other) and (*this != other);
}

int Song::compareByAuthor(const Song& a, const Song& b) {
  if (a.author == b.author)
    return 0;
  else if (a.author < b.author)
    return -1;
  else
    return 1;
}

int Song::compareByName(const Song& a, const Song& b) {
  return a.name.compare(b.name);
}

int Song::compareByRank(const Song& a, const Song& b) {
  if (a.rank == b.rank)
    return 0;
  else if (a.rank < b.rank)
    return -1;
  else
    return 1;
}

int Song::compareByPlayer(const Song& a, const Song& b) {
  if (a.player == b.player)
    return 0;
  else if (a.player < b.player)
    return -1;
  else
    return 1;
}

int Song::compareByMp3File(const Song& a, const Song& b) {
  return a.name.compare(b.name);
}

istream& operator>>(istream& in, Song& song) {
  getline(in, song.name, '|');
  in >> song.author;
  in >> song.player;
  in >> song.rank;
  in.ignore();
  getline(in, song.mp3File, '|');
  return in;
}

ostream& operator<<(ostream& out, const Song& song) {
  out << song.name;
  out << song.author;
  out << song.player;
  out << song.rank;
  out << song.mp3File;
  return out;
}
