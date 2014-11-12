
#include <iostream>
#include <memory>
#include <vector>
#include "vld.h"
#include "Ding.h"

int main()
{
	std::vector<Ding*> _rawVector;

	for (int i = 0; i < 10; i++) {
		std::unique_ptr<Ding> uPtr(new Ding());
		_rawVector.push_back(uPtr.get());
	}

	std::cin.get();
	return 0;
}