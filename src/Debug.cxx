#include "Debug.hxx"

#ifdef DEBUG
namespace debug {
std::ostream& colorize(std::ostream& out, const char* const code) {
  out << "\x1b[" << code << "m";
  return out;
}

std::ostream& colorize(std::ostream& out, std::initializer_list<const char*> codes) {
  out << "\x1b[";
  std::initializer_list<const char*>::iterator it = codes.begin();
  out << *it;
  it++;
  for (; it != codes.end(); ++it) {
    out << ";" << *it;
  }
  out << "m";
  return out;
}

std::ostream& reset(std::ostream& out) {
  out << "\x1b[0m";
  return out;
}

std::ostream& clear(std::ostream& out) {
  out << "\x1b" << "c" << "\x1b[3J";
  return out;
}
} // namespace debug
#endif // DEBUG
