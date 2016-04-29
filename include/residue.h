#ifndef __RESIDUE__
#define __RESIDUE__

#include <iostream>
#include <string>

//! This Class represents numbers of a quotient ring Z/mZ (modulo arithmetik)
/*!
* Internally an unsigned template parameter m is used to set the module
* and unsigned value is used to store the residue modulo m (the residuum).
* The residuum is stored in a way, s.t. it always returns the least positive
* residue modulo m.
*/
namespace dima {

	template<unsigned m>
	class residue {
	private: 
		unsigned residuum;
		void normalize();
	public:
		//C'tor
		//! Constructs a Zero modulo m
		residue<m>() : residuum(0) {};
		//! Constructs a new number modulo m.
		residue<m>(unsigned n);
		//getter
		unsigned get() const;
		//setter
		void set(unsigned n);
		//unary operators
		residue<m> operator-() const;
		residue<m> operator-();
		//assignment operators
		residue<m>& operator=(const unsigned& n);
		residue<m>& operator=(const residue<m>& rhs);
	
		residue<m>& operator+=(const unsigned& n);
		residue<m> operator+(unsigned n);
		residue<m>& operator+=(const residue<m>& rhs);
		residue<m> operator+(residue<m> rhs);
		template<unsigned _m>
		friend residue<_m> operator+(unsigned n, residue<_m> r);
	
		residue<m>& operator-=(const unsigned& n);
		residue<m> operator-(unsigned n);
		residue<m>& operator-=(const residue<m>& rhs);
		residue<m> operator-(residue<m> rhs);
		template<unsigned _m>
		friend residue<_m> operator-(unsigned n, residue<_m> r);
	
		residue<m>& operator*=(const unsigned& n);
		residue<m> operator*(unsigned n);
		residue<m>& operator*=(const residue<m>& rhs);
		residue<m> operator*(residue<m> rhs);
		template<unsigned _m>
		friend residue<_m> operator*(const unsigned& n, const residue<_m>& r);
	
		template<unsigned _m>
		friend std::ostream& operator<<(std::ostream& out, residue<_m>);
	};
	
	template<unsigned m>
	residue<m>::residue(unsigned n) {
		residuum = (n%m + m) % m;
	}
	
	//functions
	//normalize
	template<unsigned m>
	void residue<m>::normalize() {
		residuum = ((residuum % m) + m) % m;
	}

	//getter
	template<unsigned m>
	unsigned residue<m>::get() const {
		return residuum;
	}

	//setter
	template<unsigned m>
	void residue<m>::set(unsigned n) {
		residuum = n;
		this->normalize();
	}

	/*******************************************
	 *								Operators								 *
	 *******************************************/

	//unary operators
	template<unsigned m>
	residue<m> residue<m>::operator-() const {
		return residue<m>(m-this->get());
	}

	template<unsigned m>
	residue<m> residue<m>::operator-() {
		return residue<m>(m-this->get());
	}

	//assignment operator
	template<unsigned m> 
	residue<m>& residue<m>::operator=(const unsigned& n) {
		if (residuum != n) {
			this->set(n);
			return *this;
		}
		return *this;
	}

	template<unsigned m>
	residue<m>& residue<m>::operator=(const residue<m>& rhs) {
		*this = rhs.get();
		return *this;
	}

	template<unsigned m>
	residue<m>& residue<m>::operator+=(const unsigned& n) {
		this->set(this->get() + n);
		return *this;
	}

	template<unsigned m>
	residue<m> residue<m>::operator+(unsigned n) {
		return residue<m>(*this) += n;
	}

	template<unsigned m>
	residue<m>& residue<m>::operator+=(const residue<m>& rhs) {
		*this += rhs.get();
		return *this;
	}

	template<unsigned m>
	residue<m> residue<m>::operator+(residue<m> rhs) {
		return residue<m>(*this) += rhs;
	}


	template<unsigned m>
	residue<m> operator+(unsigned n, residue<m> r) {
		return r + n;
	}

	//subtraction
	template<unsigned m>
	residue<m>& residue<m>::operator-=(const unsigned& n) {
		unsigned rhsPos = (n%m+m)%m;
		if (this->get() > rhsPos) {
			this->set(this->get() - rhsPos);
			return *this;
		}
		else {
			this->set(m - (rhsPos - this->get()));
			return *this;
		}
	}

	template<unsigned m>
	residue<m> residue<m>::operator-(unsigned n) {
		return residue<m>(*this) -= n;
	}

	template<unsigned m>
	residue<m>& residue<m>::operator-=(const residue<m>& rhs) {
		*this -= rhs.get();
		return *this;
	}

	template<unsigned m>
	residue<m> residue<m>::operator-(residue<m> rhs) {
		return residue<m>(*this) -= rhs;
	}



	template<unsigned m>
	residue<m> operator-(unsigned n, residue<m> r) {
		return -(r - n);
	}

	//multiplication
	template<unsigned m>
	residue<m>& residue<m>::operator*=(const unsigned& n) {

	}

	template<unsigned m>
	residue<m> residue<m>::operator*(unsigned n) {
		return residue<m>(*this) *= n;
	}

	template<unsigned m>
	residue<m>& residue<m>::operator*=(const residue<m>& rhs) {

	}

	template<unsigned m>
	residue<m> residue<m>::operator*(residue<m> rhs) {
		return residue<m>(*this) *= rhs;
	}

	template<unsigned m>
	residue<m> operator*(unsigned n, residue<m> r) {
		return r*n;
	}

	//output stream
    template<unsigned m>
	std::ostream& operator<<(std::ostream& out, residue<m> r) {
		out << r.get();
		return out;
    }

    //to_string override
    template<unsigned m>
    std::string to_string(const residue<m>& r) {
        return std::to_string(r.get());
    }
}
#endif
