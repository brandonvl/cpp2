#pragma once
#include <cstdarg>

template <typename T, int n>
class Array3D
{
private:
	T *_data;
	int _sizes[n];
	size_t _size;
	unsigned int index(int params...) { 
		if (sizeof(&params) >= n) {
			int result = 0;
			for (int i = 0; i < n; i++) {
				int iResult = 1;
				for (int j = 0; j < i; j++) iResult *= _sizes[j];
				int b = (&params)[i];
				result += iResult * b;
			}
			return result;
		}
		throw;
	};

public:
	Array3D<T, n>() : Array3D<T, n>(0, 0, 0) { }; // default constructor

	// prefered constructor
	Array3D<T, n>(const int params...) {
		int a = n;
		if (sizeof(&params) >= a) {
			_size = 1;
			for (int i = 0; i < a; i++) {
				const int b = (&params)[i];
				_sizes[i] = b;
				_size *= b;
			}
			_data = new T[_size];
		}
		else throw;
	}; 
	
	// move constructor
	Array3D<T, n>(Array3D<T, n> &&instance) {
		_data = instance._data;
		_size = instance._size;
		_sizes = instance._sizes;
		instance._data = nullptr;
		instance._size = 0;
		instance._sizes = int[n];
	}

	// copy constructor
	Array3D<T, n>(const Array3D<T, n> &instance) {
		_data = new T[instance._size];
		for (int i = 0; i < instance._size; i++) {
			_data[i] = instance._data[i];
		}

		_size = instance._size;
		_sizes = instance._sizes;
	}

	// copy assignment
	Array3D<T, n> &operator=(Array3D<T, n> &instance) {
		if (&instance == this)
			return *this;

		if (instance._size != _size) 
			_data = new T[instance._size];

		for (int i = 0; i < instance._size; i++) {
			_data[i] = instance._data[i];
		}

		_size = instance._size;
		_sizes = instance._sizes;

		return *this;
	} 

	// move assignment
	Array3D<T, n> operator=(Array3D<T, n> &&instance) {
		if (&instance == this)
			return *this;

		_data = instance._data;
		_size = instance._size;
		_sizes = instance._sizes;
		instance._data = nullptr;
		instance._size = 0;
		instance._sizes = int[n];

		return *this;
	}

	inline bool operator==(const Array3D<T, n> &instance) {
		if (instance._size != _size) return false;

		for (int i = 0; i < _size; i++) {
			if (_data[i] != instance._data[i])
				return false;
		}

		return true;
	}

	virtual ~Array3D<T, n>() {
		delete[] _data;
	};
	void put(const int &x, const int &y, const int &z, const T value) {
		unsigned int indexP = index(x, y, z);
		
		if (indexP < _size)
			_data[indexP] = value;
	}
	T get(const int &x, const int &y, const int &z) {
		unsigned int indexP = index(x, y, z);

		if (indexP < _size)
			return _data[index(x, y, z)];
		else
			return -1;
	}
};

