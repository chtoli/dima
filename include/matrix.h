#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <exception>
#include <vector>

namespace dima {
 
 template<typename T>
 class matrix {
 private:
 	std::vector<T> mat;
 public:
 	const size_t rows, columns;
 	
 	matrix<T>() : rows(1), columns(1) {mat.resize(1);}
 	//! Constructs a square zero matrix of size n x n;
 	matrix<T>(std::size_t n);
 	//! Constructs a zero matrix of size m x n;
 	matrix<T>(std::size_t m, std::size_t n);
 	//! Copy Constructor
 	matrix<T>(const matrix<T>& m);
 	//! Move Constructor
 	matrix<T>(matrix<T>&& m);
 	//! Destructor
 	~matrix<T>();
 	
 	
 	
 	/******************************//*******
 	*								Operators							 *
 	***************************************/
 	matrix<T> operator-();
 	const T& operator()(const size_t i, const size_t j) const;
 	T& operator()(const size_t i, const size_t j);
 	
 	matrix<T>& operator+=(const matrix<T>& rhs);
 	const matrix<T> operator+(const matrix<T>& rhs) const;
 	
 	matrix<T>& operator-=(const matrix<T>& rhs);
 	const matrix<T> operator-(const matrix<T>& rhs) const;
 	
 	matrix<T>& operator*=(const matrix<T>& rhs);
 	const matrix<T> operator*(const matrix<T>& rhs) const;
 	
 	template<typename S>
 	friend std::ostream& operator<<(std::ostream& out, matrix<S>);
 	
 	/******************************//*******
 	*								Functions							 *
 	***************************************/
 	//! returns the inverse of a square matrix
 	matrix<T> invert();
 	//! returns the transposed matrix
 	matrix<T> transpose();
 	//! returns the adjunct matrix
 	matrix<T> adjunct();
 };
}
#endif //MATRIX_H
