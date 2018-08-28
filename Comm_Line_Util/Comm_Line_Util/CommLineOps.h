#ifndef _COMMAND_LINE_OPS_
#define _COMMAND_LINE_OPS_

#include <iostream>
#include <exception>
#include <list>
#include <set>
#include <string>

class CommLineOps {
    friend std::ostream &operator<<(std::ostream &os, CommLineOps &rhs);
private: 
    char ** argv;
    int argc;
    std::list<std::string> args;
    std::list<std::string>::iterator itr;
    std::string prefix;
    bool both;
//    std::set<Argument> Arguments;
//    std::set<Rules> Rules;
    

public:
    CommLineOps() : argv {nullptr}, argc {0}, prefix {"-"}, both {false} {};
    CommLineOps(int argc, char ** argv) : argv {argv}, argc {argc}, prefix {"-"}, both {false} {
        for(size_t i {0}; i < static_cast<size_t>(this->argc); i++) {
            this->args.emplace_back(std::string(argv[i]));
        }
        this->itr = args.begin();
    }
    virtual ~CommLineOps() = default;
    
    virtual void get_command_line(int argc, char ** argv);
    virtual void print_command_line();
    virtual void set_prefix_single();
    virtual void set_prefix_double();
    virtual void set_prefix_both();
    
    

};

#endif // _COMMAND_LINE_OPS_
