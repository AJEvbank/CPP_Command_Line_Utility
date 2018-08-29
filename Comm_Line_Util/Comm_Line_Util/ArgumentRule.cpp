#include "ArgumentRule.h"

std::ostream &operator<<(std::ostream &os, ArgumentRule &rhs)
{
    os << "[ Name: " << rhs.name << " Req: ";
    for (auto item: rhs.required_values)
        os << item << ",";
    os << " Opt: ";
    for (auto item: rhs.optional_values)
        os << item << ",";
    os << " ]";
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
    return;
}

void ArgumentRule::add_expected_value(unsigned quantity)
{
    // TODO: Cannot be called after add_optional_value().
    if (optional_values.size() > 0) {
        // throw exception
    }
    for(size_t i {0}; i < quantity; i++) {
        required_values.emplace_back(value_position++);
    }
    return;
}

void ArgumentRule::add_optional_value()
{
    size_t newValuePos {value_position};
    value_position++;
    optional_values.emplace_back(newValuePos);
    return;
}

void ArgumentRule::add_optional_value(unsigned quantity)
{
    for(size_t i {0}; i < quantity; i++) {
        optional_values.emplace_back(value_position++);
    }
    return;
}

bool ArgumentRule::operator<(ArgumentRule &rhs) 
{
    return (this->name < rhs.name);
}

bool ArgumentRule::operator==(ArgumentRule &rhs)
{
    return (this->name == rhs.name);
}

void ArgumentRule::add_option(std::string name)
{
    options.emplace(std::make_pair(name,ArgumentRule(name)));
//    ArgumentRule temp = ArgumentRule(name);
//    options.insert(std::pair<std::string,ArgumentRule>(name,ArgumentRule(name)));
    return;
}

ArgumentRule &ArgumentRule::get_option(std::string name)
{   
    std::map<std::string,ArgumentRule>::iterator test = options.find(name);
    if (test != options.end())        
        return (*test).second;
    else 
        // TODO: Make special exception type.
        throw std::exception();
}

void ArgumentRule::print_all_arguments()
{
    std::cout << "Required values: ";
    for (auto item: required_values)
        std::cout << item << ", ";
    std::cout << std::endl;
    std::cout << "Optional values: ";
    for (auto item: optional_values)
        std::cout << item << ", ";
    std::cout << std::endl;
    std::map<std::string,ArgumentRule>::iterator itr_temp {options.begin()};
    for (;itr_temp != options.end();itr_temp++)
        std::cout << (*itr_temp).first << "[ "<< (*itr_temp).second << " ], ";
    std::cout << std::endl;
}

void ArgumentRule::recursive_display(unsigned level, unsigned field_width)
{
    std::cout << std::setfill(' ') << std::setw(field_width * level) << "" << *this << std::endl;
    std::cout << std::endl;
    std::map<std::string, ArgumentRule>::iterator walker{ this->options.begin() };
    for(; walker != this->options.end(); walker++)
        (*walker).second.recursive_display(level + 1, field_width);
    return;
}
