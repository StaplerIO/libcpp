#include "node.hpp"

#include "../defs.hpp"

namespace staplerio
{
	namespace libcpp
	{
		namespace container
		{
			template<typename T>
			class Array
			{
			public:
				// Append element aster last element
				void append(T element);

				// Insert a new element at specific position
				void insert_after(T item, size_t target_index);

				// Remove last element
				void remove_last();

				// Remove the element at specific target_index
				void remove_at(size_t target_index);

				// Remove elements between two index
				// example:
				// [0, 1, 2, 3, 4, 5] remove from [2] to [5] --> [0, 1]
				void range_remove(size_t from_index, size_t length);

				// Remove all elements [equal to range_remove(0, array.count())]
				void clear();

				// Get the first element of the array
				T first_element();

				// Get the last element of the array
				T last_element();

				// Get the element at specific index
				T at_index(size_t index);

				// Get array between 2 indexes
				// void slice(size_t from_index, size_t length);

				// Get the index of the specific element (first appear)
				size_t index_of(T element);

				// Check if the array has the specific element
				bool contains(T element);

				// Check if the array is empty
				bool is_empty()
				{
					return count == 0;
				}

				// Get the element count (size) of the array
				size_t size()
				{
					return count;
				}

				// Redirect operator [i] to at_index(i)
				T operator[](size_t index)
				{
					return at_index(index);
				}

			private:
				OneWayNode<T> *elements;
				size_t count = 0;
			};

			template<typename T>
			void Array<T>::append(T element)
			{
				if (count == 0)
				{
					auto *node = DECLARE_ONE_WAY_NODE_POINTER;
					node->is_tail = true;
					node->node_content = element;
					node->next_node = nullptr;

					elements = node;
					count++;
				}
				else
				{
					OneWayNode<T> *node = elements;
					// Get last node
					while (!node->is_tail)
					{
						node = node->next_node;
					}

					// Append new node after the last node
					auto *new_node = DECLARE_ONE_WAY_NODE_POINTER;
					new_node->next_node = nullptr;
					new_node->node_content = element;
					new_node->is_tail = true;

					// Append node
					node->next_node = new_node;

					// Remove Tail flag in previous node
					node->is_tail = false;

					// Add counter
					count++;
				}
			}

			template<typename T>
			T Array<T>::at_index(size_t index)
			{
				OneWayNode<T> *node = elements;
				for (size_t current_index = 0; current_index < index; current_index++)
				{
					node = node->next_node;
				}

				return node->node_content;
			}

			template<typename T>
			bool Array<T>::contains(T element)
			{
				OneWayNode<T> *node = elements;
				do
				{
					if (node->node_content == element)
					{
						return true;
					}
				}
				while (!node->is_tail, node = node->next_node);

				return false;
			}

			// Equal to get element at index [count-1]
			template<typename T>
			T Array<T>::last_element()
			{
				return at_index(count - 1);
			}

			template<typename T>
			T Array<T>::first_element()
			{
				return at_index(0);
			}

			// Return 0x3f3f3f3f if not found
			template<typename T>
			size_t Array<T>::index_of(T element)
			{
				size_t counter = 0;
				OneWayNode<T> *node = elements;
				do
				{
					if (node->node_content == element)
					{
						return counter;
					}

					counter++;
					node = node->next_node;
				}
				while (!node->is_tail);

				return 0x3f3f3f3f;
			}

			// Remove the last element
			template<typename T>
			void Array<T>::remove_last()
			{
				OneWayNode<T> *node = elements;
				if (size() > 1)
				{
					// Get the node which its next node is the last node
					while (!node->next_node->is_tail)
					{
						node = node->next_node;
					}
				}

				// Remove last node from memory
				free(node->next_node);
				node->next_node = nullptr;
				node->is_tail = true;

				// Decrease array size by 1
				count--;
			}

			// Remove last element recursively, until it remains none
			// Warning: low efficient
			template<typename T>
			void Array<T>::clear()
			{
				while (size() > 0)
				{
					remove_last();
				}
			}

			// Use Array<T>::append if you insert after tail
			template<typename T>
			void Array<T>::insert_after(T item, size_t target_index)
			{
				auto *new_node = DECLARE_ONE_WAY_NODE_POINTER;
				new_node->node_content = item;
				new_node->is_tail = false;

				OneWayNode<T> *current_node = elements;

				for (size_t current_index = 0; current_index < target_index; current_index++)
				{
					current_node = current_node->next_node;
				}

				OneWayNode<T> *next_node = current_node->next_node;
				current_node->next_node = new_node;
				new_node->next_node = next_node;

				count++;
			}

			// Use Array<T>::remove_last if you remove tail
			template<typename T>
			void Array<T>::remove_at(size_t target_index)
			{
				OneWayNode<T> *node = elements;
				// Locate to the node which is 1 node before target node
				for (size_t current_index = 0; current_index < target_index - 1; current_index++)
				{
					node = node->next_node;
				}

				// Here: node->next_node == index_of(target_index)

				// Remove next node, connect the next after next node
				auto next_node = node->next_node->next_node;

				// Remove node from memory
				free(node->next_node);
				node->next_node = next_node;
				count--;
			}

			template<typename T>

			void Array<T>::range_remove(size_t from_index, size_t length)
			{
				for (size_t counter = 0; counter < length; counter++)
				{
					remove_at(from_index);
					count--;
				}
			}
		}
	}
}
