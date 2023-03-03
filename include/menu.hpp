#ifndef __MENU_H__
#define __MENU_H__
#include "list.hpp"
#include "song.hpp"
class Menu {
 private:
  List<Song>* list;

 public:
  Menu();
  Menu(List<Song>*);
  void printList();
  void start();
  void insertData();
  void removeData();
  void findElement();
  void sortList();
  int chooseSearchMethod(const Song&, int cmp(const Song&, const Song&));
  void chooseSortMethod(int cmp(const Song&, const Song&));
};

#endif  // __MENU_H__