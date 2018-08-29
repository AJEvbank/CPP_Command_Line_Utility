#ifndef _ARGUMENT_RULE_
#define _ARGUMENT_RULE_

#include <iostream>
#include <iomanip>
#include <exception>
#include <list>
#include <set>
#include <string>
#include <map>

class ArgumentRule
{
    friend std::ostream &operator<<(std::ostream &os, ArgumentRule &rhs);
private:
    std::string name;
    size_t value_position;
    std::list<size_t> required_values;
    std::list<size_t> optional_values;
    std::multimap<std::string, ArgumentRule> options;
    
public:
    ArgumentRule(std::string name) : name {name}, value_position {1} {}
    virtual ~ArgumentRule() = default;
    
    virtual void add_expected_value();
    virtual void add_expected_value(unsigned quantity);
    virtual void add_optional_value();
    virtual void add_optional_value(unsigned quantity);
    
    virtual bool operator<(ArgumentRule &rhs);
    virtual bool operator==(ArgumentRule &rhs);
    
    virtual void add_option(std::string name);
    virtual std::multimap<std::string,ArgumentRule>::iterator get_option(std::string name);
    
    virtual void print_all_arguments();
    virtual void recursive_display(unsigned level, unsigned field_width);

};

#endif // _ARGUMENT_RULE_
