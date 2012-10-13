#include <stdexcept>


class calculator_error : public std::logic_error
{
	public:
	explicit calculator_error(const std::string& what_arg) noexcept
		: logic_error(what_arg) {}

};
