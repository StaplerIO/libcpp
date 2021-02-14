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
				void slice(size_t from_index, size_t length);

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
				Node<T> *elements;
				size_t count = 0;
			};

			template<typename T>
			void Array<T>::append(T element)
			{
				if (this->count == 0)
				{
					auto *node = DECLARE_NODE_POINTER;
					node->is_tail = true;
					node->node_content = element;
					node->next_node = nullptr;

					this->elements = node;
					this->count++;
				}
				else
				{
					Node<T> *node = this->elements;
					// Get last node
					while (!node->is_tail)
					{
						node = node->next_node;
					}

					// Append new node after the last node
					auto *new_node = DECLARE_NODE_POINTER;
					new_node->next_node = nullptr;
					new_node->node_content = element;
					new_node->is_tail = true;

					// Append node
					node->next_node = new_node;

					// Remove Tail flag in previous node
					node->is_tail = false;

					// Add counter
					this->count++;
				}
			}

			template<typename T>
			T Array<T>::at_index(size_t index)
			{
				Node<T> *node = this->elements;
				for (size_t current_index = 0; current_index < index; current_index++)
				{
					node = node->next_node;
				}

				return node->node_content;
			}

			template<typename T>
			bool Array<T>::contains(T element)
			{
				Node<T> *node = this->elements;
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
				return this->at_index(this->count - 1);
			}

			template<typename T>
			T Array<T>::first_element()
			{
				return this->at_index(0);
			}

			// Return 0x3f3f3f3f if not found
			template<typename T>
			size_t Array<T>::index_of(T element)
			{
				size_t counter = 0;
				Node<T> *node = this->elements;
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
				Node<T> *node = this->elements;
				if (this->size() > 1)
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
				this->count--;
			}

			// Remove last element recursively, until it remains none
			// Warning: low efficient
			template<typename T>
			void Array<T>::clear()
			{
				while (this->size() > 0)
				{
					this->remove_last();
				}
			}

			// Use Array<T>::append if you insert after tail
			template<typename T>
			void Array<T>::insert_after(T item, size_t target_index)
			{
				auto *new_node = DECLARE_NODE_POINTER;
				new_node->node_content = item;
				new_node->is_tail = false;

				Node<T> *current_node = this->elements;

				for (size_t current_index = 0; current_index < target_index; current_index++)
				{
					current_node = current_node->next_node;
				}

				Node<T> *next_node = current_node->next_node;
				current_node->next_node = new_node;
				new_node->next_node = next_node;

				this->count++;
			}

			// Use Array<T>::remove_last if you remove tail
			template<typename T>
			void Array<T>::remove_at(size_t target_index)
			{
				Node<T> *node = this->elements;
				// Locate to the node which is 1 node before target node
				for (size_t current_index = 0; current_index < target_index - 1; current_index++)
				{
					node = node->next_node;
				}

				// Here: node->next_node == this->index_of(target_index)

				// Remove next node, connect the next after next node
				auto next_node = node->next_node->next_node;

				// Remove node from memory
				free(node->next_node);
				node->next_node = next_node;
				this->count--;
			}

			template<typename T>

			void Array<T>::range_remove(size_t from_index, size_t length)
			{
				for (size_t counter = 0; counter < length; counter++)
				{
					this->remove_at(from_index);
					this->count--;
				}
			}

			template<typename T>
			void Array<T>::slice(size_t from_index, size_t length)
			{
				Node<T> *current_node = this->elements;

			}
		}
	}
}
