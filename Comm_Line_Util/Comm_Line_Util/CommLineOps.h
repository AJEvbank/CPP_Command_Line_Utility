#ifndef _COMMAND_LINE_OPS_
#define _COMMAND_LINE_OPS_

#include <iostream>
#include <exception>
#include <list>
#include <string>
#include "ArgumentRule.h"

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
    ArgumentRule Rules;
    

public:
    CommLineOps() : argv {nullptr}, argc {0}, prefix {"-"}, both {false}, Rules {"__Rules__"} {};
    CommLineOps(int argc, char ** argv) : argv {argv}, argc {argc}, prefix {"-"}, both {false}, Rules {"__Rules__"} {
        for(size_t i {0}; i < static_cast<size_t>(this->argc); i++) {
            this->args.emplace_back(std::string(argv[i]));
        }
        this->itr = args.begin();
    }
    virtual ~CommLineOps() = default;
    
    virtual void get_command_line(int argc, char ** argv);
    virtual void set_prefix_single();
    virtual void set_prefix_double();
    virtual void set_prefix_both();
    
    virtual void add_required_value();
    virtual void add_optional_value();
    virtual ArgumentRule &get_rules();
    
    virtual void print_command_line();
    virtual void display_full_structure(); // This will progress as the structures are built.

};

#endif // _COMMAND_LINE_OPS_
