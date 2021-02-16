namespace staplerio
{
	namespace libcpp
	{
		namespace container
		{
			template<typename T>
			class OneWayNode
			{
			public:
				T node_content;
				OneWayNode<T> *next_node;
				bool is_tail;
			};

			template<typename T>
			class TwoWayNode
			{
				T node_content;
				TwoWayNode<T> *next_node;
				TwoWayNode<T> *previous_node;
			};
		}
	}
}
