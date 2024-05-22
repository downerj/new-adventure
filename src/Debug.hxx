#ifndef DEBUG_HXX
#define DEBUG_HXX

#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG

#ifdef DEBUG
#include <initializer_list>
#include <iostream>

#define QUOTE(x) #x
#define STRINGIFY(x) QUOTE(x)

namespace debug {
namespace fg {
  namespace dark {
  constexpr const char* black = "30";
  constexpr const char* red = "31";
  constexpr const char* green = "32";
  constexpr const char* yellow = "33";
  constexpr const char* blue = "34";
  constexpr const char* magenta = "35";
  constexpr const char* cyan = "36";
  constexpr const char* white = "37";
  constexpr const char* def = "39";
  } // namespace dark
  namespace light {
  constexpr const char* black = "90";
  constexpr const char* red = "91";
  constexpr const char* green = "92";
  constexpr const char* yellow = "93";
  constexpr const char* blue = "94";
  constexpr const char* magenta = "95";
  constexpr const char* cyan = "96";
  constexpr const char* white = "97";
  constexpr const char* def = "99";
  } // namespace light
  constexpr const char* bold = "1";
  constexpr const char* bit8 = "38;5";
  constexpr const char* bit24 = "38;2";
} // namespace fg
namespace bg {
  namespace dark {
  constexpr const char* black = "40";
  constexpr const char* red = "41";
  constexpr const char* green = "42";
  constexpr const char* yellow = "43";
  constexpr const char* blue = "44";
  constexpr const char* magenta = "45";
  constexpr const char* cyan = "46";
  constexpr const char* white = "47";
  constexpr const char* def = "49";
  } // namespace dark
  namespace light {
  constexpr const char* black = "100";
  constexpr const char* red = "101";
  constexpr const char* green = "102";
  constexpr const char* yellow = "103";
  constexpr const char* blue = "104";
  constexpr const char* magenta = "105";
  constexpr const char* cyan = "106";
  constexpr const char* white = "107";
  constexpr const char* def = "109";
  } // namespace light
  constexpr const char* bit8 = "48;5";
  constexpr const char* bit24 = "48;2";
} // namespace bg

std::ostream& colorize(std::ostream&, const char* const);
std::ostream& colorize(std::ostream&, std::initializer_list<const char*>);
std::ostream& reset(std::ostream&);
std::ostream& clear(std::ostream&);
} // namespace debug

#define LOG(tag, color, x) do {\
  std::cout << "[";\
  debug::colorize(std::cout, color) << QUOTE(tag);\
  debug::reset(std::cout) << "] " << x << std::endl;\
} while (false);
#define LOG_PART(tag, color, x) do {\
  std::cout << "[";\
  debug::colorize(std::cout, color) << QUOTE(tag);\
  debug::reset(std::cout) << "] " << x;\
} while (false);
#define LOG_CONTINUE(x) do {\
  std::cout << x;\
} while (false);
#define LOG_NEWLINE() do {\
  std::cout << std::endl;\
} while (false);
#else
#define LOG(tag, color, x)
#define LOG_PART(tag, color, x)
#define LOG_CONTINUE(x)
#define LOG_NEWLINE()
#endif // DEBUG

#endif // DEBUG_HXX
