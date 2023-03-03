#ifndef __SONG_H__
#define __SONG_H__

#include <string>

#include "name.hpp"
class Song {
 private:
  std::string name;
  Name author;
  Name player;
  int rank;
  std::string mp3File;

 public:
  Song();
  Song(const Song& other);

  std::string getName() const;
  Name getAuthor() const;
  Name getPlayer() const;
  int getRank() const;
  std::string getMp3File() const;

  void setName(const std::string&);
  void setAuthor(const Name&);
  void setPlayer(const Name&);
  void setRank(const int&);
  void setMp3File(const std::string&);

  std::string toString() const;

  Song& operator=(const Song&);
  bool operator==(const Song&) const;
  bool operator!=(const Song&) const;
  bool operator<(const Song&) const;
  bool operator<=(const Song&) const;
  bool operator>=(const Song&) const;
  bool operator>(const Song&) const;

  static int compareByAuthor(const Song&, const Song&);
  static int compareByName(const Song&, const Song&);
  static int compareByRank(const Song&, const Song&);
  static int compareByPlayer(const Song&, const Song&);
  static int compareByMp3File(const Song&, const Song&);

  friend std::ostream& operator<<(std::ostream&, const Song&);
  friend std::istream& operator>>(std::istream&, Song&);
};
#endif  // __SONG_H__