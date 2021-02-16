#include "../defs.hpp"

#include "node.hpp"

namespace staplerio
{
	namespace libcpp
	{
		namespace container
		{
			template<typename T>
			class Queue
			{
			public:
				// Get the first element in queue
				T head();

				// Get the last element in the queue
				T tail();

				// Make the element as the last element of the queue
				void push_tail(T element);

				// Remove the first element in the queue
				T pop_head();

				// As method name
				bool is_empty()
				{
					return count == 0;
				}

				// Get the number of elements in current queue
				size_t size();

				// Remove all elements in queue
				void clear();

			private:
				TwoWayNode<T> *elements = nullptr;
				size_t count = 0;
			};
		}
	}
}
