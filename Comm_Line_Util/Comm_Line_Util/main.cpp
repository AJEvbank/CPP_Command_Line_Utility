#include <iostream>
#include "CommLineOps.h"
#include "ArgumentRule.h"

int main(int argc, char** argv) {
    
    std::cout << "Hello, world!" << std::endl;
    
    CommLineOps clo {argc,argv};
    std::cout << clo << std::endl;
    clo.print_command_line();
    
    ArgumentRule newArgRule {"jump"};
    std::cout << newArgRule << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}