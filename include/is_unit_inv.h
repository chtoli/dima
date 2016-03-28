#ifndef IS_UNIT_INV_H
#define IS_UNIT_INV_H

#include "rational.h"

namespace dima {
	
	
	//! Checks if the given integer is a unit
	/*!
	 * \param arg the argument
	 * \return true if arg is +-1, false otherwise
	 */ 
	bool is_unit(const int& arg);
	//! Checks if the given double is a unit (viewed as a real number)
	/*!
	 * \param arg the argument
	 * \return true if arg is nonzero, false otherwise
	 */ 
	bool is_unit(const double& arg);
	//! Checks if the given rational number is a unit
	/*!
	 * \param arg the argument
	 * \return true if arg is nonzero, false otherwise
	 */ 
	bool is_unit(const rational& arg);
	
}

#endif
