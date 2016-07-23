#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <ostream>
#include <vector>

namespace dima {
	//! This Class represents Polynomials over an commutative unitary ring 
	/*!
	* Internally an std::vector is used for storaging the leading coefficients. The first entry is the constant coefficient, the second the coefficient of x^1 and so on.
	* A normalize method is used, s.t. the last entry is always nonzero (except for the zero polynomial)
	*/
	template <typename T>
	class polynomial {
	using size_t = typename std::vector<T>::size_type;
	private:
		std::vector<T> data;
		//! Removes all zeros in data after the leading coefficient
		void normalize();
		char c = 'X';
	public:
		//! Constructs the Zero Polynomial
		polynomial() { data.push_back(0); }
		//! Constructs a Polynomial from a vector
		/*!
		* \param v the first entry of v represents the constant coefficient, the second the linear coefficient and so on.
		*/ 
		polynomial(const std::vector<T>& v) : data(v) { normalize(); }
		
		//! Comparison operator
		/*!
		* \param rhs right hand side of the comparison
		* \return true if *this and rhs are equal (as polynomials), false otherwise
		*/
		bool operator==(const polynomial& rhs) const;
		//! Comparison operator
		/*!
		* \param rhs right hand side of the comparison
		* \return true if *this and rhs are unequal (as polynomials), false otherwise
		*/
		bool operator!=(const polynomial& rhs) const;
		
		//! Unary + operator. Returns this polynomial
		/*!
		* \return *this
		*/ 
		polynomial operator+() const;
		//! Unary + operator. Returns the additive inverse 
		/*!
		* \return the additive inverse of *this
		*/ 
		polynomial operator-() const;
		//! Prefix increment operator
		polynomial& operator++();
		//! Prefix decrement operator
		polynomial& operator--();
		//! Posfix increment operator
		polynomial operator++(int);
		//! Postfix decrement operator
		polynomial operator--(int);
		
		//! Addition between two polynomials
		/*!
		 * \param rhs right hand side of the Operation
		 * \return this+rhs
		*/
		polynomial operator+(const polynomial& rhs) const;
		
		//! Subtraction between two polynomials
		/*!
		 * \param rhs right hand side of the Operation
		 * \return this-rhs
		*/
		polynomial operator-(const polynomial& rhs) const;
		//! Multiplikation between two polynomials
		/*!
		 * \param rhs right hand side of the Operation
		 * \return this*rhs
		*/
		polynomial operator*(const polynomial& rhs);
		//! Divison between two polynomials
		/*!
		 * \param rhs right hand side of the Operation
		 * \return the quotient q, if this = q*rhs+r with deg(r) < deg(q)
		*/
		polynomial operator/(const polynomial& rhs) const;
		
		//! Modulo Operation
		/*!
		 * \param rhs right hand side of the Operation
		 * \return the remainder r of divison by rhs
		*/
		polynomial operator%(const polynomial& rhs) const;
		
		//Assignment Operator
		/*!
		 * \param rhs the value, which is added to *this
		 * \return *this
		*/
		polynomial& operator+=(const polynomial& rhs);
		
		//Assignment Operator
		/*!
		 * \param rhs the value, which is subtracted from *this
		 * \return *this
		*/
		polynomial& operator-=(const polynomial& rhs);
		
		//Assignment Operator
		/*!
		 * \param rhs the value, by which *this is multiplied
		 * \return *this
		*/
		polynomial& operator*=(const polynomial& rhs);
		
		//Assignment Operator
		/*!
		 * \param rhs the value, by which *this is divided
		 * \return *this
		*/
		polynomial& operator/=(const polynomial& rhs);
		
		//Assignment Operator
		/*!
		 * \param rhs the value, by which *this is reduced
		 * \return *this
		*/
		polynomial& operator%=(const polynomial& rhs);
		
		//! Sets the displayed variable for this polynomial (default: X)
		void setC(char);
		
		//! Outputstream operator
		/*!
		* Writes the given polynomial to the stream.
		* \param os the stream 
		* \param p the polynomial
		* \return the modified stream
		*/ 
		template <typename S>
		friend std::ostream& operator<< (std::ostream& os, const polynomial<S> p);
		
		//! degree function
		/*!
		 * \param p the polynomial
		 * \return degree of p
		 */ 
		template <typename S>
		friend int deg( const polynomial<S> p);
	};

	template <typename T>
	std::ostream& operator<< (std::ostream& os, const polynomial<T> p) {
		os << p.data[0] << p.c;
		for (size_t i = 1; i < p.data.size(); i++) {
			if (p.data[i] >= 0) os << '+';
			os << p.data[i] << p.c << "^(" << i << ")";
		}
		return os;
	}
	
	template <typename T>
	int deg( const polynomial<T> p) { 
		if (p.data.size() == 1 && p.data[0] == 0) return -1;
		return  p.data.size()-1;
	}
	
	template <typename T>
	void polynomial<T>::normalize() {
		for (size_t i = data.size(); i > 1; i++) {
			if (data[i] != 0) break;
			data.pop_back();
		}
	}
	
	template <typename T>
	polynomial<T> polynomial<T>::operator+() const {
		return *this;
	}
	
	template <typename T>
	polynomial<T> polynomial<T>::operator-() const {
		std::vector<T> p(deg(*this)+1);
		for (size_t i = 0; i < p.size(); i++) p[i] = -(this->data[i]);
		return p;
	}
	
	template <typename T>
	polynomial<T> polynomial<T>::operator*(const polynomial& rhs) const {
		std::vector<T> productCoef;
		if(this->deg() <= rhs.deg()){
	        	for(int i = (rhs.deg() + this->deg() + 1); i > -1; i--){
	        		T coef = 0;
	                    	for(int j = 0; j < rhs.deg() + 1; j++){
	                		for(int k = 0; k < this->deg() + 1; k++){
	                       			if(i == k + j){
		                     			coef += rhs(j) + this(k);
	                       			}
	                      		}
                   		}
	                    	productCoef.push_back(coef);
	                	}
		} else {
			return rhs * this;
		}
		return new polynomial(productCoef);	
	}
}
#endif
