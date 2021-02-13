namespace staplerio
{
	namespace libcpp
	{
		namespace container
		{
			template<typename T>
			class ArrayElement
			{
			public:
				T node_content;
				ArrayElement<T> *next_node;
				bool is_tail;
			};
		}
	}
}
