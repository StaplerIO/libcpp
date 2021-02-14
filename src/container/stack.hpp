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
				Node<T> *elements = nullptr;
			};

			template<typename T>
			void Stack<T>::push(T element)
			{
				auto *new_node = DECLARE_NODE_POINTER;
				new_node->node_content = element;
				new_node->next_node = nullptr;

				if (this->count > 0)
				{
					auto *original_top = this->elements;
					new_node->next_node = original_top;
				}

				this->elements = new_node;
				this->count++;
			}

			template<typename T>
			T Stack<T>::pop()
			{
				auto top_element = this->top();

				if (count <= 1)
				{
					free(this->elements);
					this->elements = nullptr;
					this->count = 0;
				}
				else
				{
					auto next_node = this->elements->next_node;
					free(this->elements);
					this->elements = next_node;

					this->count--;
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
				return this->elements->node_content;
			}

			template<typename T>
			void Stack<T>::clear()
			{
				while (!this->is_empty())
				{
					this->pop();
				}
			}
		}
	}
}
