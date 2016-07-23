#ifndef matrix_H
#define matrix_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

namespace dima {

	
	template<typename T>
	class matrix {
	using size_t = typename std::vector<T>::size_type;
	using Vector = std::vector<T>;
	private:
		std::vector<T> data;
		size_t rows, columns;
	public:
		matrix<T>() : rows(1), columns(1) {data.resize(1);}
		//! Constructs a square zero matrix of size n x n;
		matrix<T>(size_t n);
		//! Constructs a zero matrix of size m x n;
		matrix<T>(size_t m, size_t n);
		//! Constructs a matrix by array initialization;
		matrix<T>(std::initializer_list<std::initializer_list<T>> init_list)
			: rows(init_list.size()), columns(init_list.size() ? init_list.begin()->size() : 0)
		 {
		 	data.resize(columns*rows);
			int i = 0, j = 0;
			for (const auto& l : init_list) {
				for (const auto& v : l)
				{
					(*this)(i,j) = v;
					++j;
				}
				j = 0;
				++i;
			}
		}
		
		//! Copy Constructor
		matrix<T>(const matrix<T>& m);
		//! Copy assignment operator
		matrix<T>& operator=(const matrix<T>& rhs);
		//! Move Constructor
		matrix<T>(matrix<T>&& m);
		//! Move assignment operator
		matrix<T>& operator=(matrix<T>&& m);
		//! Destructor
		~matrix<T>();
		
		//getters
		const size_t get_rows() const {return rows;}
		const size_t get_columns() const {return columns;}
		
	
	
	
		/******************************//*******
		*								Operators							 *
		***************************************/
		matrix<T> operator-();
		const T& operator()(const size_t i, const size_t j) const;
		T& operator()(const size_t i, const size_t j);
	
		//! Addition
		matrix<T>& operator+=(const matrix<T>& rhs);
		const matrix<T> operator+(const matrix<T>& rhs) const;
	
		//! Subtraction
		matrix<T>& operator-=(const matrix<T>& rhs);
		const matrix<T> operator-(const matrix<T>& rhs) const;
	
		//! Multiplication
		matrix<T>& operator*=(const matrix<T>& rhs);
		const matrix<T> operator*(const matrix<T>& rhs) const;
		
		//! Comparison
		bool operator==(const matrix<T>& other) const;
		bool operator!=(const matrix<T>& other) const;
	
		//! Output
		template<typename S>
		friend std::ostream& operator<<(std::ostream& out, matrix<S>);
		
	
		/******************************//*******
		*		        Functions              *
		***************************************/
		//! Removes the i-th row
		void remove_row(const size_t& i);
		//! Removes the j-th column
		void remove_column(const size_t& j);
		//! Removes i-th row and j-th column
		void remove(const size_t& i, const size_t& j);
		//! Returns a new matrix without the i-th row and j-th column
		template<typename S>
		friend matrix<S> submatrix(const matrix<S>& m, const size_t& i, const size_t& j);
		//! invert the matrix
		void invert();
		//! transpose the matrix
		void transpose();
		//! returns the adjunct matrix
		// adjunct();
	};	
	
	//Constructor
	template<typename T>
	matrix<T>::matrix(size_t n): rows(n), columns(n) {
		data.resize(rows*columns);
	}
	
	//Constructor
	template<typename T>
	matrix<T>::matrix(size_t m, size_t n):	rows (m),	columns (n) {
		data.resize(rows*columns);
		std::fill(data.begin(), data.end(), 0);
	}
	
	//Copy constructor
	template<typename T>
	matrix<T>::matrix(const matrix<T>& other)
		: rows(other.rows), columns(other.columns) {
		data = other.data;
	}
	
	//Copy assignment operator
	template<typename T>
	matrix<T>& matrix<T>::operator=(const matrix<T>& other) {
		if (this != &other) {
			rows = other.rows;
			columns = other.columns;
			data = other.data;	
		}
		return *this;
	}

	//Move Constructor
	template<typename T>
	matrix<T>::matrix(matrix<T>&& other)
	: rows(other.rows)
	, columns(other.columns) {
		std::cout << "MC called" << std::endl;
		data.resize(rows*columns);
		data = std::move(other.data);
	}
	
	//Move assignment operator
	template<typename T>
	matrix<T>& matrix<T>::operator=(matrix<T>&& other) {
		if (this != &other) {
			rows = other.rows;
			columns = other.columns;
			data.resize(rows*columns);
			data = std::move(other.data);
		}
		return *this;
	}
	
	//Destructor
	template<typename T>
	matrix<T>::~matrix() {}

	/**************************************
	*		        Operators   	      *
	***************************************/
	
	//!binary bracket operator to access matrix A's entry in i-th row and j-th column with A(i,j)
	template<typename T>
	const T& matrix<T>::operator()(const size_t i, const size_t j) const {
		return data[j+i*columns];
	}

	template<typename T>
	T& matrix<T>::operator()(const size_t i, const size_t j) {
		return data[j+i*columns];
	}

	//addition
	template<typename T>
	matrix<T>& matrix<T>::operator+=(const matrix<T>& rhs) {
		//std::copy(rhs.data, rhs.data + rhs.rows*rhs.columns, data);
		for (size_t i = 0; i < rhs.rows; i++) {
			for (size_t j = 0; j < rhs.columns; j++) {
				(*this)(i,j) += rhs(i,j);
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
				(*this)(i,j) -= rhs(i,j);
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
		matrix<T> tmp(*this);
		columns = rhs.columns;
		data.resize(rows*columns);
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < rhs.columns; j++) {
				T sum = 0;
				for (size_t k = 0; k < rhs.rows; k++) {
					sum += (tmp)(i,k) * rhs(k,j);
				}
				(*this)(i,j) = sum;
			}
		}
		return *this;
	}

	template<typename T>
	const matrix<T> matrix<T>::operator*(const matrix<T>& rhs) const {
		return matrix<T>(*this) *= rhs;
	}
	
	//comparison
	template<typename T>
	bool matrix<T>::operator==(const matrix<T>& other) const {
		if (rows != other.rows || columns != other.columns) return false;
		for (size_t i = 0; i < rows; i++)
			for (size_t j = 0; j < columns; j++)
				if (*this(i,j) != other(i,j)) return false;
	}
	
	template<typename T>
	bool matrix<T>::operator!=(const matrix<T>& other) const {
		return !(*this == other);
	}
	
	//output
	template<typename T>
	std::ostream& operator<<(std::ostream& out, matrix<T> m) {
		for (size_t i = 0; i < m.rows; i++) {
			for (size_t j = 0; j < m.columns; j++) {
				out << m(i,j) << " ";
			}
			out << std::endl;
		}
		return out;
	}
	
	/******************************//*******
	*		Functions	       *
	***************************************/
	//removes the given index's column
	template<typename T>
	void matrix<T>::remove_column(const size_t& deleted_column) {
		size_t new_size = rows*(columns-1);
		for (size_t i = deleted_column; i < new_size; i++) {
			int di = 1+(i-deleted_column)/(columns-1);
			data[i] = data[i+di];
		}
		--columns;
		data.resize(new_size);
	}
	
	//removes the given index's row	
	template<typename T>
	void matrix<T>::remove_row(const size_t& deleted_row) {
		size_t new_size = (rows-1)*columns;
		for (size_t i = deleted_row*columns; i < new_size; i++) {
			data[i] = data[i+columns];
		}
		--rows;
		data.resize(new_size);
	}
	
	//removes the given index's row and column;	
	template<typename T>
	void matrix<T>::remove(const size_t& i, const size_t& j) {
		this->remove_row(i);
		this->remove_column(j);
	}
	
	//returns the submatrix with i-th row and j-th column deleted (needed for det)
	template<typename T>
	matrix<T> submatrix(const matrix<T>& m, const size_t& i, const size_t& j) {
		matrix<T> result(m);
		result.remove(i,j);
		return result;
	}
}
#endif //matrix_H
