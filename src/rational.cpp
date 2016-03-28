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
		rational result;
		result.denominator = this->denominator * rhs.denominator;
		
		if (this->is_non_negative == rhs.is_non_negative) {
			result.is_non_negative = this->is_non_negative;
			result.numerator = this->numerator*rhs.denominator+rhs.numerator*(this->denominator);
		} else {
			bool is_left_value_abs_larger = this->numerator*rhs.denominator > rhs.numerator*(this->denominator);
			unsigned num = is_left_value_abs_larger ? this->numerator*rhs.denominator-rhs.numerator*(this->denominator) : -this->numerator*rhs.denominator+rhs.numerator*(this->denominator);
			result.numerator = num;
			result.is_non_negative = (is_left_value_abs_larger && this->is_non_negative) || (!is_left_value_abs_larger && !(this->is_non_negative));
		}
		result.normalize();
		return result;
	}
	
	rational rational::operator-(const rational& rhs) const {
		return (*this)+rational(!rhs.is_non_negative, rhs.numerator, rhs.denominator);
	}
	
	rational rational::operator*(const rational& rhs) const {
		return rational(this->is_non_negative == rhs.is_non_negative, this->numerator*rhs.numerator, this->denominator*rhs.denominator);
	}
	
	rational rational::operator/(const rational& rhs) const {
		if (rhs.numerator == 0) throw std::overflow_error("Overflow Error: Divison by Zero");
		return (*this)*rational(rhs.is_non_negative, rhs.denominator, rhs.numerator);
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
		*this = *this + rhs;
		return *this;
	}
	
	rational& rational::operator-=(const rational& rhs) {
		*this = *this - rhs;
		return *this;
	}
	
	rational& rational::operator*=(const rational& rhs) {
		*this = *this * rhs;
		return *this;
	}
	
	rational& rational::operator/=(const rational& rhs) {
		*this = *this / rhs;
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



