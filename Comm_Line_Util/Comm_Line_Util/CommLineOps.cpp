#include "CommLineOps.h"

std::ostream &operator<<(std::ostream &os, CommLineOps &rhs) {
    if (rhs.both == false)
        os << "[ Argv: " << rhs.argv << " with " << rhs.argc << " args and prefix: " << rhs.prefix << " ]";
    else
        os << rhs.argv << " with " << rhs.argc << " args and both: " << rhs.both;
    return os;
}

void CommLineOps::get_command_line(int argc, char ** argv) {
        this->argv = argv; 
        this->argc = argc;
        this->args.clear();
        for(size_t i {0}; i < static_cast<size_t>(this->argc); i++) {
            this->args.emplace_back(std::string(argv[i]));
        }
        this->itr = args.begin();
}

void CommLineOps::print_command_line() {
    for (auto str: args) {
        std::cout << str << " ";
    }
}

void CommLineOps::set_prefix_single()
{
    this->prefix = '-';
    this->both = false;
    return;
}

void CommLineOps::set_prefix_double()
{
    this->prefix = "--";
    this->both = false;
    return;
}

void CommLineOps::set_prefix_both()
{
    this->both = true;
    return;
}

void CommLineOps::add_rule(std::string name)
{
    Rules.add_option(name);
    return;
}

void CommLineOps::display_full_structure()
{
    std::cout << *this << std::endl;
    this->print_command_line();
    std::cout << std::endl;
    Rules.recursive_display(0,10);
    return;
}
