#include "menu.hpp"

#include <iostream>
#include <string>
using namespace std;
Menu::Menu() {}

Menu::Menu(List<Song>* l) { list = l; }

void Menu::printList() {
  system("cls");
  string title;
  title.resize(70, ' ');
  title += "LISTA DE CANCIONES\n";
  cout << title << endl;
  if (!list->isEmpty()) {
    cout << list->toString() << endl;
  }
}

void Menu::start() {
  char option;
  string title;
  title.resize(15, ' ');
  title += "MENU";
  do {
    printList();
    cout << title << endl;
    cout << "\t[A]gregar cancion." << endl;
    cout << "\t[E]liminar cancion." << endl;
    cout << "\t[B]uscar cancion." << endl;
    cout << "\t[O]rdenar lista" << endl;
    cout << "\t[S]alir del programa." << endl;

    cin >> option;

    switch (option) {
      case 'A':
      case 'a':
        insertData();
        break;

      case 'E':
      case 'e':
        removeData();
        break;

      case 'B':
      case 'b':
        findElement();
        break;

      case 'O':
      case 'o':
        sortList();
        break;
      case 'S':
      case 's':
        break;

      default:
        cout << "Opcion invalida..." << endl;
        system("pause");
        break;
    }
  } while (option != 'S' && option != 's');
  system("cls");
  cout << "Fin del programa." << endl;
  system("pause");
}

void Menu::insertData() {
  Song data;
  int index;
  printList();
  cout << "\n-INGRESE UNA NUEVA CANCION-" << endl;
  cin.ignore();
  cin >> data;

  cout << "-INGRESE LA POSICION DE LA INSERCION" << endl;
  cin >> index;
  list->insert(data, index);
  cout << "ELEMENTO AGREGADO CON EXITO..." << endl;
}

void Menu::removeData() {
  int index;
  char option;
  printList();
  cout << "\n-INGRESE EL INDICE DE LA CANCION QUE ELIMINARA-" << endl;
  cin >> index;
  cout << list->getElement(index).toString() << endl;
  cout << "DESEA BORRAR ESTA CANCION [Y/N]?" << endl;
  cin >> option;
  list->remove(index);
  cout << "ELEMENTO ELIMINADO CON EXITO..." << endl;
  system("pause");
}

void Menu::findElement() {
  Song mySong;
  string myStr;
  Name myName;
  int option, result;
  system("cls");
  cout << "ELIJA EL PARAMETRO DE BUSQUEDA: " << endl;
  cout << "1. NOMBRE DE LA CANCION" << endl;
  cout << "2. NOMBRE DEL INTERPRETE" << endl;
  cin >> option;
  switch (option) {
    case 1:
      cout << "INTRODUZCA EL NOMBRE DE LA CANCION: " << endl;
      cin.ignore();
      getline(cin, myStr);
      mySong.setName(myStr);
      result = chooseSearchMethod(mySong, Song::compareByName);
      break;
    case 2:
      cout << "INTRODUZCA EL NOMBRE DEL INTERPRETE DE: ";
      cin >> myName;
      mySong.setPlayer(myName);
      result = chooseSearchMethod(mySong, Song::compareByPlayer);
      break;
    default:
      break;
  }
  if (result != -1) {
    cout << "LA CANCION BUSCADA SE ENCUENTRA EN EL INDICE " << result << endl;
    cout << "ARCHIVO MP3: " << list->getElement(result).getMp3File() << ".mp3"
         << endl;
  } else {
    cout << "CANCION NO ENCONTRADA" << endl;
  }
  system("pause");
}

void Menu::sortList() {
  char option;
  system("cls");
  cout << "ELIJA EL PARAMETRO DE ORDENACION\n" << endl;
  cout << "[N]ombre de la cancion" << endl;
  cout << "[A]utor de la cancion" << endl;
  cout << "[I]nterprete de la cancion" << endl;
  cout << "[R]anking de la cancion" << endl;
  cin >> option;
  switch (option) {
    case 'N':
    case 'n':
      chooseSortMethod(Song::compareByName);
      break;
    case 'A':
    case 'a':
      chooseSortMethod(Song::compareByAuthor);
      break;
    case 'I':
    case 'i':
      chooseSortMethod(Song::compareByPlayer);
      break;
    case 'R':
    case 'r':
      chooseSortMethod(Song::compareByRank);
      break;
  }
}

int Menu::chooseSearchMethod(const Song& mySong,
                             int cmp(const Song&, const Song&)) {
  int option;
  cout << "ELIJA EL METODO DE BUSQUEDA: " << endl;
  cout << "1. BUSQUEDA LINEAL" << endl;
  cout << "2. BUSQUEDA BINARIA" << endl;
  cin >> option;
  switch (option) {
    case 1:
      return list->findElementLin(mySong, cmp);
      break;
    case 2:
      return list->findElementBin(mySong, cmp);
      break;
  }
}

void Menu::chooseSortMethod(int cmp(const Song&, const Song&)) {
  int option;
  cout << "ELIJA EL METODO DE ORDENAMIENTO: " << endl;
  cout << "1. BUBBLE SORT" << endl;
  cout << "2. INSERT SORT" << endl;
  cout << "3. SELECT SORT" << endl;
  cout << "4. SHELL SORT" << endl;
  cin >> option;
  switch (option) {
    case 1:
      list->bubbleSort(cmp);
      break;
    case 2:
      list->insertSort(cmp);
      break;
    case 3:
      list->selectSort(cmp);
      break;
    case 4:
      list->shellSort(cmp);
      break;
  }
}
