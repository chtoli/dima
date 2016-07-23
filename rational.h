#ifndef RATIONAL_H
#define RATIONAL_H

#include <ostream>

namespace dima {
	
	//! This Class represents rational numbers.
	/*!
	* Internally a bool is used for storing the sign and two unsigned for storing numerator and denominator.
	* Numerator and denominator are stored in a way, s.t. they are realtive prime to each other.
	*/ 
	class rational {
	private:
		bool is_non_negative;
		unsigned numerator, denominator;
		
		//! Makes numerator and denominator relative prime
		void normalize();
		
	public:
		//! Constructs a Zero
		rational() : is_non_negative(true), numerator(0), denominator(1) {}
		
		//! Constructs a new rational numbers
		/*!
		 * Constructs a new rational number and normalize the representation, 
		 * i.e. makes numerator and denominator relative prime
		 * \param b specifies the sign of the rational number, where true means + and false -
		 * \param n is the numerator of the rational number
		 * \param d is the denominator of the rational number. if this paramter is zero, 
		 * an std::domain_error exception is thrown
		 */ 
		rational(bool b, unsigned n, unsigned d);
		//! Constructs a non negative rational number with denominator 1
		/*!
		 * \param n is the numerator of the rational number
		 */ 
		//rational(unsigned numerator n) : is_non_negative(true), numerator(n), denominator(1) {}
		//! Constructs a rational number with denominator 1
		/*!
		 * \param b specifies the sign of the rational number, where true means + and false -
		 * \param n is the numerator of the rational number
		 */
		rational(bool b, unsigned n) : is_non_negative(b), numerator(n), denominator(1) {}
		//! Constructs a rational number
		/*!
		 * \param n is the numerator of the rational number
		 * \param d is the denominator of the rational number. if this paramter is zero, 
		 * an std::domain_error exception is thrown
		 */
		rational(int n, int d) : rational((n>=0 && d >= 0) || (n < 0 && d < 0), n>= 0 ? n : -n, d >= 0 ? d : -d) {}
		//! Constructs a rational number with denominator 1
		/*!
		 * \param n is the numerator of the rational number
		 */
		rational(int n) : is_non_negative(n>=0), numerator(n>=0 ? n : -n), denominator(1) {}
		
		//! Returns the numerator
		/*!
		 * \return the numerator of this rational number
		 */ 
		unsigned getNumerator() const;
		//! Returns the denominator
		/*!
		 * \return the denominator of this rational number
		 */ 
		unsigned getDenominator() const;
		
		//! Addition between two rational numbers
		/*!
		 * \param rhs right hand side of the Operation
		 * \return the result of this+rhs
		 */
		rational operator+(const rational& rhs) const;
		//! Subtraction between two rational numbers
		/*!
		 * \param rhs right hand side of the Operation
		 * \return the result of this-rhs
		 */
		rational operator-(const rational& rhs) const;
		//! Multiplication between two rational numbers
		/*!
		 * \param rhs right hand side of the Operation
		 * \return the result of this*rhs
		 */
		rational operator*(const rational& rhs) const;
		//! Division between two rational numbers
		/*!
		 * \param rhs right hand side of the Operation. Throws an std::overflow_error if rhs is zero
		 * \return the result of this/rhs
		 */
		rational operator/(const rational& rhs) const;
		//! Unary + operator. Returns this rational number
		/*!
		 * \return *this
		 */ 
		rational operator+() const;
		//! Unary + operator. Returns the additive inverse 
		/*!
		 * \return the additive inverse of *this
		 */ 
		rational operator-() const;
		//! Prefix increment operator
		rational& operator++();
		//! Prefix decrement operator
		rational& operator--();
		//! Posfix increment operator
		rational operator++(int);
		//! Postfix decrement operator
		rational operator--(int);
		//! Assignment operator
		/*!
		 * \param rhs the value, which is added to *this
		 * \return *this
		 */ 
		rational& operator+=(const rational& rhs);
		//! Assignment operator
		/*!
		 * \param rhs the value, which is subtracted from *this
		 * \return *this
		 */ 
		rational& operator-=(const rational& rhs);
		//! Assignment operator
		/*!
		 * \param rhs the factor by which *this is multiplied
		 * \return *this
		 */ 
		rational& operator*=(const rational& rhs);
		//! Assignment operator
		/*!
		 * \param rhs the value by which *this is divided
		 * \return *this
		 */ 
		rational& operator/=(const rational& rhs);
		
		//! Comparison operator
		/*!
		 * \param rhs right hand side of the comparison
		 * \return true if *this and rhs are equal (as rational numbers), false otherwise
		 */
		bool operator==(const rational& rhs) const;
		//! Comparison operator
		/*!
		 * \param rhs right hand side of the comparison
		 * \return true if *this and rhs are unequal (as rational numbers), false otherwise
		 */
		bool operator!=(const rational& rhs) const;
		//! Comparison operator
		/*!
		 * \param rhs right hand side of the comparison
		 * \return true if *this is smaller as rhs, false otherwise
		 */
		bool operator<(const rational& rhs) const;
		//! Comparison operator
		/*!
		 * \param rhs true if *this is smaller as rhs, false otherwise
		 * \return true if *this is smaller or equal as rhs, false otherwise
		 */
		bool operator<=(const rational& rhs) const;
		//! Comparison operator
		/*!
		 * \param rhs right hand side of the comparison
		 * \return true if *this is greater as rhs, false otherwise
		 */
		bool operator>(const rational& rhs) const;
		//! Comparison operator
		/*!
		 * \param rhs right hand side of the comparison
		 * \return true if *this is greater or equal as rhs, false otherwise
		 */
		bool operator>=(const rational& rhs) const;
		
		//! Outputstream operator
		/*!
		 * Writes the given rational number to the stream. If the given number is also an integer,
		 * then its integer representation is written to the stream.
		 * \param os the stream 
		 * \param r the rational number
		 * \return the modified stream
		 */ 
		friend std::ostream& operator<< (std::ostream& os, const rational r);
	};

}

#endif // RAIONAL_H