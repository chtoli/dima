#include "matrix.h"

namespace dima {

	template<typename T>
	matrix<T>::matrix(std::size_t n): rows(n), columns(n) {
		mat.resize(rows*columns);
	}

	template<typename T>
	matrix<T>::matrix(std::size_t m, std::size_t n):	rows (m),	columns (n) {
		mat.resize(rows*columns);
		for (std::size_t i = 0; i < rows; i++)
			for (std::size_t j = 0; j < columns; j++)
				*this(i,j) = 0;
	}

	template<typename T>
	matrix<T>::matrix(const matrix<T>& m): rows (m.rows), columns (m.columns) {
		mat.resize(rows*columns);
		for (size_t i = 0; i < rows; i++)
			for (size_t j = 0; j < columns; j++)
				*this(i,j) = m(i,j);
	}

	/*template<typename T>
	matrix<T>::matrix(matrix<T> &&m): rows 		(m.rows), columns	(m.columns), mat (m.mat) {
		m.mat = nullptr;
		m.rows = m.columns = 0;
	}*/


	/**************************************
	*								Operators							*
	***************************************/
	//!binary bracket operator to access matrix A's entriy in i-th row and j-th column with A(i,j)
	template<typename T>
	const T& matrix<T>::operator()(const size_t i, const size_t j) const {
		return mat[j+i*columns];
	}

	template<typename T>
	T& matrix<T>::operator()(const size_t i, const size_t j) {
		return mat[j+i*columns];
	}

	//addition
	template<typename T>
	matrix<T>& matrix<T>::operator+=(const matrix<T>& rhs) {
		//std::copy(rhs.mat, rhs.mat + rhs.rows*rhs.columns, mat);
		for (size_t i = 0; i < rhs.rows; i++) {
			for (size_t j = 0; j < rhs.columns; j++) {
				*this(i,j) += rhs(i,j);
			}
		}
		return *this;
	}

	template<typename T>
	const matrix<T> matrix<T>::operator+(const matrix<T>& rhs) const {
		return matrix<T>(*this) += rhs;
	}

	//subtraction
	template<typename T>
	matrix<T>& matrix<T>::operator-=(const matrix<T>& rhs) {
		for (size_t i = 0; i < rhs.rows; i++) {
			for (size_t j = 0; j < rhs.columns; j++) {
				*this(i,j) -= rhs(i,j);
			}
		}
		return *this;
	}

	template<typename T>
	const matrix<T> matrix<T>::operator-(const matrix<T>& rhs) const {
		return matrix<T>(*this) -= rhs;
	}

	//multiplication
	template<typename T>
	matrix<T>& matrix<T>::operator*=(const matrix<T>& rhs) {
		if (columns != rhs.rows) throw std::invalid_argument("Dimensions do not match");
		for (size_t i = 0; i < rhs.rows; i++) {
			T sum = 0;
			for (size_t j = 0; j < rhs.columns; j++) {
				sum += (*this(i,j)*rhs(j,i));
				*this(i,j) *= rhs(i,j);
			}
		}
		return *this;
	}

	template<typename T>
	const matrix<T> matrix<T>::operator*(const matrix<T>& rhs) const {
		return matrix<T>(*this) *= rhs;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, matrix<T> m) {
		for (std::size_t i = 0; i < m.rows; i++) {
			for (std::size_t j = 0; j < m.columns; j++) {
				out << m(i,j) << " ";
			}
			out << std::endl;
		}
		return out;
	}
}
