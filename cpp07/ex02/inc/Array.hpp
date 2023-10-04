#pragma once

#include <iostream>

/**
 * @brief 
 * 
 * @tparam T is used to dynamically allocate an array into it
 * @param size The size of the array
 */

using std::cout;
using std::endl;

template <typename T> class Array {
	private:
		T*						_data;
		unsigned int	_size;
	public:
		Array() : _data(nullptr), _size(0) {};
		Array(unsigned int n) : _size(n) {
			_data = new T[_size]; // The () behind the [] fills the arr with 0's

			for (unsigned int i = 0; i < _size; i++)
				_data[i] = i;
		}
		Array(const Array &src) : _size(src._size) {
			_data = new T[src._size];

			for (uint32_t i = 0; i < _size; i++)
				_data[i] = src._data[i];
		};
		~Array() {delete[] _data;}
		Array& operator=(const Array& src) {
			if (this == &src)
				return (*this);

			// The copy assignment operator is used to assign the value of one already-existing object
			// to another already-existing object.
			delete[] _data;

			_size = src._size;
			_data = new T[_size];

			for (uint32_t i = 0; i < _size; i++)
				_data[i] = src._data[i];
			return (*this);
		}
		T& operator[](uint32_t idx)  const {
			if (idx >= _size)
				throw (std::out_of_range("Index is out of bounds"));
			return _data[idx];
		}
		void	print( void ) const {
			for (uint32_t i = 0; i < _size; i++)
				cout << _data[i] << " ";
			cout << endl;
		}
		unsigned int size() const {return _size; }
};


