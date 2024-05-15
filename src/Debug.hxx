#ifndef DEBUG_HXX
#define DEBUG_HXX

#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG

#ifdef DEBUG
#include <iostream>
#define DEBUG_LOG(x) do { std::cout << x; } while (false);
#define DEBUG_LINE(x) do { std::cout << x << std::endl; } while (false);
#define DEBUG_NEWLINE(x) do { std::cout << std::endl; } while (false);
#else
#define DEBUG_LOG(x)
#define DEBUG_LINE(x)
#define DEBUG_NEWLINE(x)
#endif // DEBUG

#endif // DEBUG_HXX
