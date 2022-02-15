namespace staplerio
{
	namespace libcpp
	{
		namespace condition
		{
			template<typename okType, typename errorType>
			class ActionResult
			{
			public:
				ActionResult(okType ok) : ok(ok), is_ok(true)
				{ }

				ActionResult(errorType error) : error(error), is_ok(false)
				{ }

				bool isOk() const
				{
					return is_ok;
				}

				okType getOk() const
				{
					return ok;
				}

				errorType getError() const
				{
					return error;
				}

			private:

				bool is_ok;

				okType ok;
				errorType error;
			};
		}
	}
}
