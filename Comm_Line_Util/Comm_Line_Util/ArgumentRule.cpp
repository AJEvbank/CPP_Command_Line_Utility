#include "ArgumentRule.h"

std::ostream &operator<<(std::ostream &os, ArgumentRule &rhs)
{
    os << "[ Name: " << rhs.name << " value_position=" << rhs.value_position << " ]";
    return os;
}

void ArgumentRule::add_expected_value()
{
    // TODO: Cannot be called after add_optional_value().
    if (optional_values.size() > 0) {
        // throw exception
    }
    size_t newValuePos {value_position};
    value_position++;
    required_values.emplace_back(newValuePos);
}

void ArgumentRule::add_optional_value()
{
    size_t newValuePos {value_position};
    value_position++;
    optional_values.emplace_back(newValuePos);
}

bool ArgumentRule::operator<(ArgumentRule &rhs) 
{
    return (this->name < rhs.name);
}

bool ArgumentRule::operator==(ArgumentRule &rhs)
{
    return (this->name == rhs.name);
}
ArgumentRule::add_option(_GLIBCXX_STD::string name)
{
}
ArgumentRule& ArgumentRule::get_option(_GLIBCXX_STD::string name)
{
}
