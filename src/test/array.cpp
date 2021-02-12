#include <iostream>

#include "../code/container/array.hpp"

using namespace staplerio::libcpp::container;

int main(void)
{
	Array<int> array;
	array.append(1);
	array.append(2);

	std::cout << array[0] << array.at_index(1) << std::endl;
	std::cout << array.size() << std::endl;

	return 0;
}
