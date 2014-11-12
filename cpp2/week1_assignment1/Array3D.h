#pragma once

template <typename T>
class Array3D
{
private:
	T *_data;
	int _x_size;
	int _y_size;
	int _z_size;
	size_t _size;
	unsigned int index(int x, int y, int z) const { return _y_size * _x_size * z + _x_size * y + x; };

public:
	Array3D<T>() : Array3D<T>(0,0,0) { }; // default constructor
	Array3D<T>(const int &x_size, const int &y_size, const int &z_size) : _x_size(x_size), _y_size(y_size), _z_size(z_size), _size(x_size*y_size*z_size) { _data = new T[_size]; }; // prefered constructor
	Array3D<T>(Array3D<T> &&instance) {

	}// move constructor
	Array3D<T>(const Array3D<T> &instance) {

	} // copy
	Array3D<T> &operator=(Array3D<T> &instance) {

	} // copy assignment
	Array3D<T> operator=(Array3D<T> &&instance) {

	}// move assignment
	virtual ~Array3D<T>() {
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

