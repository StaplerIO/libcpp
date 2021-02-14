namespace staplerio
{
	namespace libcpp
	{
		namespace container
		{
			template<typename T>
			class Node
			{
			public:
				T node_content;
				Node<T> *next_node;
				bool is_tail;
			};
		}
	}
}
