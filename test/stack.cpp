#include <iostream>

#include "../src/container/stack.hpp"

using namespace staplerio::libcpp::container;

int main()
{
	Stack<int> stack;

	for (int i = 1; i <= 20; i++)
	{
		stack.push(i);
	}

	std::cout << "count: " << stack.size() << std::endl;
	std::cout << "top: " << stack.top() << std::endl;

	std::cout << "pop: ";
	while(!stack.is_empty())
	{
		std::cout << stack.pop() << " ";
	}
	std::cout << std::endl;

	stack.push(0x3f3f3f3f);
	stack.clear();
	std::cout << stack.size() << std::endl;

	return 0;
}