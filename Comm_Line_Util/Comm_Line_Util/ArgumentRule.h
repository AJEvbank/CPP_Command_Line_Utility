#ifndef _ARGUMENT_RULE_
#define _ARGUMENT_RULE_

#include <iostream>
#include <exception>
#include <list>
#include <set>
#include <string>

class ArgumentRule
{
    friend std::ostream &operator<<(std::ostream &os, ArgumentRule &rhs);
private:
    std::string name;
    size_t value_position;
    std::list<size_t> required_values;
    std::list<size_t> optional_values;
    std::set<ArgumentRule> options;
    
public:
    ArgumentRule(std::string name) : name {name}, value_position {1} {}
    virtual ~ArgumentRule() = default;
    void add_expected_value();
    void add_optional_value();
    virtual bool operator<(ArgumentRule &rhs);
    virtual bool operator==(ArgumentRule &rhs);
    
    // TODO: implement these
    virtual add_option(std::string name);
    virtual ArgumentRule &get_option(std::string name);

};

#endif // _ARGUMENT_RULE_
