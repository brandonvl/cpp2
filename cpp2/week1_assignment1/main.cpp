
#include "Array3D.h"
#include "vld.h"

int main()
{
	Array3D<int> obj(1,2,3);
	obj.put(1, 1, 1, 5);
	obj.put(1, 1, 2, 10);
	int value = obj.get(1, 1, 1);

	return 0;
}