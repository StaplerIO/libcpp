#include <iostream>

#include "../src/container/array.hpp"

using namespace staplerio::libcpp::container;

int main()
{
	Array<int> array;
	for (int i = 1; i <= 1000; i++)
	{
		array.append(i * 2);
	}

	std::cout << array.contains(-1) << ", " << array.contains(1024) << std::endl;
	std::cout << array[2] << array.at_index(3) << std::endl;
	std::cout << array.size() << std::endl;
	std::cout << array.first_element() << ", " << array.last_element() << std::endl;
	std::cout << array.index_of(20) << std::endl;

	array.insert_after(5, 1);

	std::cout << array[2] << std::endl;

	array.remove_last();
	std::cout << array.first_element() << ", " << array.last_element() << std::endl;

	array.clear();
	std::cout << array.size() << std::endl;

	return 0;
}
