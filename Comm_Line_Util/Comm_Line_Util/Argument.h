#ifndef _ARGUMENT_
#define _ARGUMENT_

#include <string>
#include <list>
#include <set>

class Argument
{
private:
    std::string name;
    std::list<Argument> required_values;
    std::set<Argument> args;
public:
    Argument(std::string name);
    virtual ~Argument() = default;

};

#endif // _ARGUMENT_
