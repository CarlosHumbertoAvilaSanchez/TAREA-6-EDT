#ifndef __LIST_H__
#define __LIST_H__
#define SIZE 3000

#include <string>
using namespace std;
template <class T>
class List {  // List definition
 private:
  T data[SIZE];
  int last;
  void copyAll(const List&);

 public:
  List();
  List(const List&);
  bool isEmpty() const;
  bool isFull() const;
  bool validIndex(const int&) const;
  void insert(const T&, const int&);
  void remove(const int&);
  int getFirst() const;
  int getLast() const;
  int previous(const int&) const;
  int next(const int&) const;
  void reset();
  T getElement(const int&) const;
  List& operator=(const List&);

  // Metodos de busqueda
  int findElementLin(const T&, int cmp(const T&, const T&)) const;
  int findElementBin(const T&, int cmp(const T&, const T&)) const;

  void swapData(const int&, const int&);

  // Metodos de ordenamiento
  void bubbleSort(int cmp(const T&, const T&));
  void insertSort(int cmp(const T&, const T&));
  void selectSort(int cmp(const T&, const T&));
  void shellSort(int cmp(const T&, const T&));

  std::string toString() const;
};

// List implementation
template <class T>
void List<T>::copyAll(const List& other) {
  int counter = 0;
  while (counter < this->last) {
    this->data[counter] = other.data[counter];
    counter++;
  }
}

template <class T>
List<T>::List() {
  last = -1;
}

template <class T>
List<T>::List(const List<T>& other) : last(other.last) {
  copyAll(other);
}

template <class T>
bool List<T>::isEmpty() const {
  return last == -1;
}

template <class T>
bool List<T>::isFull() const {
  return last > SIZE;
}

template <class T>
bool List<T>::validIndex(const int& index) const {
  if (index > -1 and index < last + 1) {
    return true;
  }
  return false;
}

template <class T>
void List<T>::insert(const T& element, const int& index) {
  if (!isFull() or index >= -1 or index < (last + 1)) {
    int counter = last++;
    while (counter > index) {
      data[counter + 1] = data[counter];
      counter--;
    }
    data[index + 1] = element;
  }
}

template <class T>
void List<T>::remove(const int& index) {
  if (!isEmpty() and validIndex(index)) {
    int counter = index;
    while (counter < last) {
      data[counter] = data[counter + 1];
      counter++;
    }
    last--;
  }
}

template <class T>
int List<T>::getFirst() const {
  if (isEmpty()) {
    return -1;
  }
  return 0;
}

template <class T>
int List<T>::getLast() const {
  if (isEmpty()) {
    return -1;
  }
  return last;
}

template <class T>
int List<T>::previous(const int& index) const {
  if (!isEmpty() and validIndex(index)) return index - 1;
}

template <class T>
int List<T>::next(const int& index) const {
  if (!isEmpty() and validIndex(index)) return index + 1;
}

template <class T>
void List<T>::reset() {
  last = -1;
}

template <class T>
T List<T>::getElement(const int& index) const {
  if (!isEmpty() and validIndex(index)) return data[index];
}

template <class T>
List<T>& List<T>::operator=(const List& other) {
  last = other.last;
  copyAll(other);
  return *this;
}

template <class T>
int List<T>::findElementLin(const T& a, int cmp(const T&, const T&)) const {
  int index = 0;
  while (index <= last) {
    if (cmp(a, data[index]) == 0) {
      return index;
    }
    index++;
  }
  return -1;
}

template <class T>
int List<T>::findElementBin(const T& a, int cmp(const T&, const T&)) const {
  int index = 0, j = last, middle;
  while (index <= j) {
    middle = (index + j) / 2;
    if (cmp(data[middle], a) == 0) {
      return middle;
    }
    if (cmp(a, data[middle]) < 0) {
      j = middle - 1;
    } else {
      index = middle + 1;
    }
  }
  return -1;
}

template <class T>
void List<T>::swapData(const int& a, const int& b) {
  T aux = data[a];
  data[a] = data[b];
  data[b] = aux;
}

template <class T>
void List<T>::bubbleSort(int cmp(const T&, const T&)) {
  int index = last, j, flag;
  do {
    j = 0;
    flag = 0;
    while (j < index) {
      if (cmp(data[j], data[j + 1]) > 0) {
        swapData(j, j + 1);
        flag = 1;
      }
      j++;
    }
    index--;
  } while (flag == 1);
}

template <class T>
void List<T>::insertSort(int cmp(const T&, const T&)) {
  int index = 1, j;
  T aux;
  while (index <= last) {
    aux = data[index];
    j = index;
    while (j > 0 and cmp(aux, data[j - 1]) < 0) {
      data[j] = data[j - 1];
      j--;
    }
    if (index != j) {
      data[j] = aux;
    }
    index++;
  }
}

template <class T>
void List<T>::selectSort(int cmp(const T&, const T&)) {
  int index = 0, minor, j;
  while (index < last) {
    minor = index;
    j = index + 1;
    while (j <= last) {
      if (cmp(data[j], data[minor]) < 1) {
        minor = j;
      }
      j++;
    }
    if (minor != index) {
      swapData(index, minor);
    }
    index++;
  }
}

template <class T>
void List<T>::shellSort(int cmp(const T&, const T&)) {
  double factor( 1.0/2.0);
  int dif((last + 1) * factor);
  int index, j;

  while (dif > 0) {
    index = dif;
    while (index <= last) {
      j = index;
      while (j >= dif and cmp(data[j - dif], data[j]) > 0) {
        swapData(j - dif, j);
        j = j - dif;
      }
      index++;
    }
    dif *= factor;
  }
}
template <class T>
std::string List<T>::toString() const {
  std::string result;
  int counter = 0;
  while (counter <= last) {
    
    result += "\t"+data[counter].toString() + "\n";
    counter++;
  }
  return result;
}
#endif  // __LIST_H__