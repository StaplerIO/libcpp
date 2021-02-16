#include <iostream>

#include "../src/container/queue.hpp"

using namespace staplerio::libcpp::container;

int main()
{
	Queue<int> queue;

	std::cout << queue.is_empty() << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		queue.push_tail(i);
	}

	std::cout << queue.size() << std::endl;

	std::cout << queue.head() << ", " << queue.tail() << std::endl;

	std::cout << queue.pop_head() << ", " << queue.head() << ", " << queue.size() << std::endl;

	queue.clear();
	std::cout << queue.size() << std::endl;

	return 0;
}