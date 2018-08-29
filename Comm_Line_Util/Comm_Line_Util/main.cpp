#include <iostream>
#include "CommLineOps.h"
#include "ArgumentRule.h"

int main(int argc, char** argv) {
    
    std::cout << "Hello, world!" << std::endl;
    
    CommLineOps clo {argc,argv};
    clo.display_full_structure();
    
    clo.add_rule(name);
    
    
    
    std::cout << std::endl << std::endl;
    return 0;
}