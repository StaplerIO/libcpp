#include "node.hpp"

#include "../defs.hpp"

/**
 * Ignore property node->is_tail
 * It's no use in Stack
 */

namespace staplerio
{
	namespace libcpp
	{
		namespace container
		{
			template<typename T>
			class Stack
			{
			public:
				void push(T element);

				T pop();

				void clear();

				T top();

				bool is_empty();

				size_t size();

			private:
				size_t count = 0;
				OneWayNode<T> *elements = nullptr;
			};

			template<typename T>
			void Stack<T>::push(T element)
			{
				auto *new_node = DECLARE_ONE_WAY_NODE_POINTER;
				new_node->node_content = element;
				new_node->next_node = nullptr;

				if (count > 0)
				{
					auto *original_top = elements;
					new_node->next_node = original_top;
				}

				elements = new_node;
				count++;
			}

			template<typename T>
			T Stack<T>::pop()
			{
				auto top_element = top();

				if (count <= 1)
				{
					free(elements);
					elements = nullptr;
					count = 0;
				}
				else
				{
					auto next_node = elements->next_node;
					free(elements);
					elements = next_node;

					count--;
				}

				return top_element;
			}

			template<typename T>
			size_t Stack<T>::size()
			{
				return count;
			}

			template<typename T>
			bool Stack<T>::is_empty()
			{
				return count == 0;
			}

			template<typename T>
			T Stack<T>::top()
			{
				return elements->node_content;
			}

			template<typename T>
			void Stack<T>::clear()
			{
				while (!is_empty())
				{
					pop();
				}
			}
		}
	}
}
