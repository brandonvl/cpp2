
#include "Array3D.h"
#include "vld.h"
#include <iostream>

int main()
{
	Array3D<int, 3> obj(1,2,3);
	obj.put(1, 1, 1, 5);
	obj.put(1, 1, 2, 10);
	int value = obj.get(1, 1, 1);
	std::cout << "result obj: " << obj.get(1, 1, 1) << std::endl;
	std::cout << "result obj: " << obj.get(1, 1, 2) << std::endl;

	/*
	// test copy constructor
	Array3D<int, 3> obj2(obj);
	std::cout << "result obj2: " << obj2.get(1, 1, 1) << std::endl;
	std::cout << "result obj: " << obj.get(1, 1, 1) << std::endl;

	// test move constructor
	Array3D<int, 3> obj3 = std::move(obj);
	std::cout << "result obj3: " << obj3.get(1, 1, 1) << std::endl;
	std::cout << "result obj: " << obj.get(1, 1, 1) << std::endl;

	// test copy assignment
	Array3D<int, 3> obj4;
	obj4 = obj3;
	std::cout << "result obj4: " << obj4.get(1, 1, 1) << std::endl;
	std::cout << "result obj3: " << obj3.get(1, 1, 1) << std::endl;

	// test move assignment
	Array3D<int, 3> obj5;
	obj5 = std::move(obj3);
	std::cout << "result obj5: " << obj5.get(1, 1, 1) << std::endl;
	std::cout << "result obj3: " << obj3.get(1, 1, 1) << std::endl;
	*/
	std::cin.get();
	return 0;
}