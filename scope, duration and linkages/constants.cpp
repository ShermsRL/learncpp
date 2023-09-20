#include "constants.h"

namespace constants
{
	extern const double pi{ 3.14159 };
	extern const double earthGravity{ 9.2 };
}
// prefer defining constants in header file, if its value is changing alot, move to cpp file instead