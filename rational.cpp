#include "rational.h"
#include "gcd_lcm.h"
#include <stdexcept>

namespace dima {
	
	rational::rational(bool is_non_negative, unsigned numerator, unsigned denominator) {
		if (denominator == 0) throw std::domain_error("Domain Error: Denominator can not be Zero");
		this->is_non_negative = is_non_negative;
		this->numerator = numerator;
		this->denominator = denominator;
		normalize();
	}
	
	void rational::normalize() {
		if (numerator == 0) {
			this->is_non_negative = true;
			this->numerator = 0;
			this->denominator = 1;
			return;
		}
		unsigned g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;
	}
	
	rational rational::operator+(const rational& rhs) const {
		rational result = *this;
		result+=rhs;
		return result;
	}
	
	rational rational::operator-(const rational& rhs) const {
		rational result = *this;
		result-=rhs;
		return result;
	}
	
	rational rational::operator*(const rational& rhs) const {
		rational result = *this;
		result*=rhs;
		return result;
	}
	
	rational rational::operator/(const rational& rhs) const {
		rational result = *this;
		result/=rhs;
		return result;
	}
	
	bool rational::operator==(const rational& rhs) const {
		return this->is_non_negative == rhs.is_non_negative && this->numerator == rhs.numerator && this->denominator == rhs.denominator;
	}
	
	bool rational::operator!=(const rational& rhs) const {
		return !(*this == rhs);
	}
	
	bool rational::operator<(const rational& rhs) const {
		if(this->is_non_negative == rhs.is_non_negative) {
			return this->is_non_negative ? this->numerator * rhs.denominator < rhs.numerator*(this->denominator) : this->numerator * rhs.denominator < rhs.numerator*(this->denominator);
		}
		return rhs.is_non_negative;
	}
	
	bool rational::operator<=(const rational& rhs) const {
		return *this == rhs || *this < rhs;
	}
	
	bool rational::operator>(const rational& rhs) const {
		return !(*this < rhs || *this == rhs); 
	}
	
	bool rational::operator>=(const rational& rhs) const {
		return !(*this < rhs);
	}
	
	rational rational::operator+() const { return *this; }
	
	rational rational::operator-() const {
		if (this->numerator == 0) return *this;
		return rational(!this->is_non_negative, this->numerator, this->denominator);
	}
	
	rational& rational::operator+=(const rational& rhs) {
		bool b = this->is_non_negative;
		unsigned n = this->numerator;
		unsigned d = this->denominator;
		this->denominator = d * rhs.denominator;
		
		if (b == rhs.is_non_negative) {
			this->numerator = n*rhs.denominator + rhs.numerator*d;
		} else {
			bool is_left_value_abs_larger = n*rhs.denominator > rhs.numerator*d;
			this->numerator = is_left_value_abs_larger ? n*rhs.denominator - rhs.numerator*d : rhs.numerator*d - n*rhs.denominator;
			this->is_non_negative = (is_left_value_abs_larger && b) || (!is_left_value_abs_larger && !b);
		}
		normalize();
		return *this;
	}
	
	rational& rational::operator-=(const rational& rhs) {
		*this += rational(!rhs.is_non_negative, rhs.numerator, rhs.denominator);
		return *this;
	}
	
	rational& rational::operator*=(const rational& rhs) {
		this->is_non_negative = this->is_non_negative == rhs.is_non_negative;
		this->numerator = this->numerator*rhs.numerator;
		this->denominator = this->denominator*rhs.denominator;
		normalize();
		return *this;
	}
	
	rational& rational::operator/=(const rational& rhs) {
		if (rhs.numerator == 0) throw std::overflow_error("Overflow Error: Divison by Zero");
		this->is_non_negative = this->is_non_negative == rhs.is_non_negative;
		this->numerator = this->numerator*rhs.denominator;
		this->denominator = this->denominator*rhs.numerator;
		normalize();
		return *this;
	}
	
	rational& rational::operator++() {
		if (this->is_non_negative) {
			this->numerator+=this->denominator;
			return *this;
		}
		if (this->numerator > this->denominator) {
			this->numerator -= this->denominator;
			return *this;
		}
		this->is_non_negative = true;
		this->numerator = this->denominator - this->numerator;
		return *this;
	}
	
	rational& rational::operator--() {
		if(!this->is_non_negative) {
			this->numerator+= this->denominator;
			return *this;
		}
		if (this->numerator >= this->denominator) {
			this->numerator-= this->denominator;
			return *this;
		}
		this->is_non_negative = false;
		this->numerator = this->denominator-this->numerator;
		return *this;
	}
	
	rational rational::operator++(int i) {
		rational result(*this);
		(*this)++;
		return result;
	}
	
	rational rational::operator--(int i) {
		rational result(*this);
		(*this)--;
		return result;
	}
	
	unsigned rational::getNumerator() const { return numerator; }
	
	unsigned rational::getDenominator() const { return denominator; }
	
	std::ostream& operator<< (std::ostream& os, const rational r) {
		if(r.denominator == 1) os<< (r.is_non_negative ? "" : "-") << r.numerator;
		else os << (r.is_non_negative ? "" : "-") << r.numerator << "/" << r.denominator;
		return os;
	}
	
}



