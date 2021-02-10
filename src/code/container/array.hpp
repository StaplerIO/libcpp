namespace staplerio
{
	namespace libcpp
	{
		namespace container
		{
			template <typename T>
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
				// Swap 2 elements at position a and b
				void swap(size_t index_a, size_t index_b);

				// Get the index of the specific element (first appear)
				size_t index_of(T element);

				// Check if the array has the specific element
				bool contains(T element);

				// Get the element count (size) of the array
				size_t count();

				// Redirect operator [i] to at_index(i)
				T operator[](size_t index)
				{
					return at_index(index);
				}

			private:
				ArrayElement<T> elements;
			};

			template <typename T>
			class ArrayElement
			{
				T node;
				T *next_node;
				bool is_tail;
			};
		} // namespace container
	}	  // namespace libcpp
} // namespace staplerio
