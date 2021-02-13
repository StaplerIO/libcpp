#include <cstdlib>

#include "../defs.hpp"

#include "array_element.hpp"

#define DECLARE_ARRAY_ELEMENT_POINTER (ArrayElement<T> *)malloc(sizeof(ArrayElement<T>))

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
				void insert_at(T item, size_t index);

				// Remove last element
				void remove_last();

				// Remove the element at specific index
				void remove_at(size_t index);

				// Remove elements between two index
				// example:
				// [0, 1, 2, 3, 4, 5] remove from [2] to [5] --> [0, 1]
				void remove_between(size_t from_index, size_t count);

				// Remove all elements [equal to remove_between(0, array.count())]
				void clear();

				// Get the first element of the array
				T first_element();

				// Get the last element of the array
				T last_element();

				// Get the element at specific index
				T at_index(size_t index);

				// Get array between 2 indexes
				void slice(size_t from_index, size_t count);

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
				ArrayElement<T> *elements;
				size_t count = 0;
			};

			template<typename T>
			void Array<T>::append(T element)
			{
				if (this->count == 0)
				{
					ArrayElement<T> *node = DECLARE_ARRAY_ELEMENT_POINTER;
					node->is_tail = true;
					node->node_content = element;
					node->next_node = nullptr;

					this->elements = node;
					this->count++;
				}
				else
				{
					ArrayElement<T> *node = this->elements;
					// Get last node
					while (!node->is_tail)
					{
						node = node->next_node;
					}

					this->count++;

					// Append new node after the last node
					ArrayElement<T> *new_node = DECLARE_ARRAY_ELEMENT_POINTER;
					new_node->next_node = nullptr;
					new_node->node_content = element;
					new_node->is_tail = true;

					// Append node
					node->next_node = new_node;

					// Remove Tail flag in previous node
					node->is_tail = false;
				}
			}

			template<typename T>
			T Array<T>::at_index(size_t index)
			{
				ArrayElement<T> *node = this->elements;
				for (size_t current_index = 0; current_index < index; current_index++)
				{
					node = node->next_node;
				}

				return node->node_content;
			}

			template<typename T>
			bool Array<T>::contains(T element)
			{
				ArrayElement<T> *node = this->elements;
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
		}
	}
}
