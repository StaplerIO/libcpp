#include <cstdio>

#include "../code/container/pair.hpp"

using namespace staplerio::libcpp;

int main(void)
{
	container::KeyValuePair<int, char> pair;
	pair.key = 2;
	pair.value = 'c';

	printf("%d%c\n", pair.key, pair.value);

	return 0;
}
