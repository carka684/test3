#include <stdexcept>


class expression_error : public std::logic_error
{
	public:
	explicit expression_error(const std::string& what_arg) noexcept
		: logic_error(what_arg) {}

};
