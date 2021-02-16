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
				size_t size()
				{
					return count;
				}

				// Remove all elements in queue
				void clear();

			private:
				TwoWayNode<T> *head_element = nullptr;
				TwoWayNode<T> *tail_element = nullptr;
				size_t count = 0;
			};

			template<typename T>
			void Queue<T>::push_tail(T element)
			{
				auto *node = DECLARE_TWO_WAY_NODE_POINTER;
				node->next_node = nullptr;
				node->previous_node = nullptr;
				node->node_content = element;

				if (count == 0)
				{
					head_element = tail_element = node;
				}
				else
				{
					tail_element->next_node = node;
					node->previous_node = tail_element;
					tail_element = node;
				}

				count++;
			}

			template<typename T>
			T Queue<T>::head()
			{
				return head_element->node_content;
			}

			template<typename T>
			T Queue<T>::tail()
			{
				return tail_element->node_content;
			}

			template<typename T>
			T Queue<T>::pop_head()
			{
				// Get content first
				auto content = head();

				auto head_node = head_element;

				// Bind head to next node
				head_element = head_element->next_node;

				// Free head from memory
				free(head_node);

				count--;

				return content;
			}

			template<typename T>
			void Queue<T>::clear()
			{
				while(count > 0)
				{
					pop_head();
				}
			}
		}
	}
}
