#include "name.hpp"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Name::Name() {
  first = "";
  last = "";
}

Name::Name(const Name& other) : first(other.first), last(other.last) {}

string Name::getFirst() const { return first; }

string Name::getLast() const { return last; }

void Name::setFirst(const string& f) { first = f; }

void Name::setLast(const string& l) { last = l; }

string Name::toString() const {
  string result;
  result += first;
  result += " ";
  result += last;
  return result;
}

Name& Name::operator=(const Name& other) {
  first = other.first;
  last = other.last;
  return *this;
}

bool Name::operator==(const Name& other) const {
  return this->toString().compare(other.toString()) == 0;
}

bool Name::operator!=(const Name& other) const { return !(*this == other); }

bool Name::operator<(const Name& other) const {
  return this->toString().compare(other.toString()) < 0;
}

bool Name::operator>(const Name& other) const {
  return !(*this < other) and (*this != other);
}

bool Name::operator<=(const Name& other) const { return !(*this > other); }

bool Name::operator>=(const Name& other) const { return !(*this < other); }

istream& operator>>(std::istream& in, Name& name) {
  string myStr;
  getline(in, myStr, '|');
  istringstream i(myStr);
  i >> name.first >> name.last;
  return in;
}

ostream& operator<<(std::ostream& out, const Name& name) {
  out << name.toString() << endl;
  return out;
}
