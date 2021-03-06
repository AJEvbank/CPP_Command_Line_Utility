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
    const std::string reserved_name {"__Rules__"};
    size_t value_position;
    std::string prefix;
    bool both;
    std::list<size_t> required_values;
    std::list<size_t> optional_values;
    std::map<std::string, ArgumentRule> options;
//    ArgumentRule& temp;
    
public:
    ArgumentRule(std::string name) : name {name}, value_position {1},  prefix {"-"}, both {false} {}
    ArgumentRule(std::string name, std::string prefix) : name {name}, value_position {1}, prefix {prefix}, both {false} {}
    virtual ~ArgumentRule() = default;
    
    virtual void add_expected_value();
    virtual void add_expected_value(unsigned quantity);
    virtual void add_optional_value();
    virtual void add_optional_value(unsigned quantity);
    
    virtual void set_prefix_single();
    virtual void set_prefix_double();
    virtual void set_prefix_both();
    
    virtual bool operator<(ArgumentRule &rhs);
    virtual bool operator==(ArgumentRule &rhs);
    
    virtual void add_option(std::string name);
    virtual void add_option(const char name []);
    virtual ArgumentRule &get_option(std::string name);
    
    virtual void print_all_arguments();
    virtual void recursive_display(unsigned level, unsigned field_width);

};

#endif // _ARGUMENT_RULE_
