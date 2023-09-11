#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>

template <typename T>
class Array {
	public:
		Array(void)
			: _size(0)
		{}

		Array(unsigned int n)
			: _array(new T[n]), _size(n)
		{}

		Array(Array const &other)
			: _size(0)
		{
			*this = other;
		}

		Array &operator=(Array const &other)
		{
			if (_size > 0)
				delete[] _array;

			_size = other._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
			return *this;
		}

		int &operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::exception();
			return _array[i];
		}

		~Array()
		{
			if (_size > 0)
				delete[] _array;
		}

		unsigned int size() const
		{
			return _size;
		}


	private:
		T *_array;
		unsigned int _size;
};

#endif  // ARRAY_HPP_
