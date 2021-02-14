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

	array.insert_after(5, 12);

	std::cout << array[13] << std::endl;

	array.remove_last();
	std::cout << array.first_element() << ", " << array.last_element() << std::endl;

	array.remove_at(2);
	std::cout << array[0] << array[1] << array[2] << array[3] << array[4] << std::endl;
	std::cout << array.size() << std::endl;

	array.clear();
	std::cout << array.size() << std::endl;

	for (int i = 1; i <= 40; i++)
	{
		array.append(i * 2);
	}

	array.range_remove(10, 10);
	std::cout << array[9] << ", " << array[10] << std::endl;
	std::cout << array.size();

	return 0;
}
