#include <stdexcept>


class variable_table_error : public std::logic_error
{
	public:
	explicit variable_table_error(const std::string& what_arg) noexcept
		: logic_error(what_arg) {}

};
