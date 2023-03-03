#include "list.hpp"

#include "menu.hpp"
#include "song.hpp"
int main() {
  List<Song> list;
  Menu interface(&list);
  interface.start();
  return 0;
}
