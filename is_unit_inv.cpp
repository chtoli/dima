#include "is_unit_inv.h"
#include "rational.h"

namespace dima {
	bool is_unit(const int& arg) { return (arg == 1 || arg == -1); }
	bool is_unit(const double& arg) { return arg != 0; }
	bool is_unit(const rational& arg) { return arg != 0; }
}
