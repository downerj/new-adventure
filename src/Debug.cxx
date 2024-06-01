#include "Debug.hxx"

#ifdef DEBUG
using namespace std;

namespace debug {
ostream& colorize(ostream& out, const char* const code) {
  out << "\x1b[" << code << "m";
  return out;
}

ostream& colorize(ostream& out, initializer_list<const char*> codes) {
  out << "\x1b[";
  auto it{ codes.begin() };
  out << *it;
  it++;
  for (; it != codes.end(); ++it) {
    out << ";" << *it;
  }
  out << "m";
  return out;
}

ostream& reset(ostream& out) {
  out << "\x1b[0m";
  return out;
}

ostream& clear(ostream& out) {
  out << "\x1b" << "c" << "\x1b[3J";
  return out;
}
} // namespace debug
#endif // DEBUG
