#include <iostream>

#include "../src/container/array.hpp"

using namespace staplerio::libcpp::container;

int main()
{
	Array<int> array;
	for (int i = 1; i <= 1000; i++)
	{
		array.append(i);
	}

	std::cout << array.contains(-1) << ", " << array.contains(1024) << std::endl;
	std::cout << array[2] << array.at_index(3) << std::endl;
	std::cout << array.size() << std::endl;

	return 0;
}
