#include "matrix.h"

namespace {
 
 template<typename T>
 matrix<T>::matrix(std::size_t n): rows(n), columns(n) {
 	mat.resize(rows*columns);
 }
 
 template<typename T>
 matrix<T>::matrix(std::size_t m, std::size_t n):	rows		(m), columns (n) {
 	mat.resize(rows*columns);
 	for (std::size_t i = 0; i < rows; i++)
 		for (std::size_t j = 0; j < columns; j++)
 			mat[j+i*columns] = 0;
 }
 
 template<typename T>
 matrix<T>::matrix(const matrix<T>& m): rows (m.rows), columns (m.columns) {
 	mat.resize(rows*columns);
 	for (size_t i = 0; i < rows; i++)
 		for (size_t j = 0; j < columns; j++)
 			mat[j + i*columns] = m.mat[j+i*columns];
 }
 
 /*template<typename T>
 matrix<T>::matrix(matrix<T> &&m): rows 		(m.rows),
 															 		columns	(m.columns), 
 															 		mat			(m.mat) {
 	m.mat = nullptr;
 	m.rows = m.columns = 0;
 }*/
 
 
 /**************************************
 *								Operators							*
 ***************************************/
 //!binary bracket operator to access matrix A's entriy in i-th row and j-th column with A(i,j)
 /*template<typename T>
 T& matrix<T>::operator()(const size_t i, const size_t j) const {
 	return mat[j+i*columns];
 }*/
 
 //addition
 template<typename T>
 matrix<T>& matrix<T>::operator+=(const matrix<T>& rhs) {
 	//std::copy(rhs.mat, rhs.mat + rhs.rows*rhs.columns, mat);
 	for (size_t i = 0; i < rhs.rows; i++) {
 		for (size_t j = 0; j < rhs.columns; j++) {
 			mat[i][j] += rhs.mat[i][j];
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
 			mat[i][j] -= rhs.mat[i][j];
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
 	if (columns < rhs.columns) {
 		//allocate more memory
 	}
 	for (size_t i = 0; i < rhs.rows; i++) {
 		for (size_t j = 0; j < rhs.columns; j++) {
 			mat[i][j] *= rhs.mat[j][i];
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
 			out << m.mat[j+i*m.columns] << " ";
 		}
 		out << std::endl;
 	}
 	return out;
 }
}
