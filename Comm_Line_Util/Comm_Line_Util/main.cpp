#include <iostream>
#include "CommLineOps.h"
#include "ArgumentRule.h"

int main(int argc, char** argv) {
    
    std::cout << "Hello, world!" << std::endl;
    
    CommLineOps clo {argc,argv};
    clo.display_full_structure();
    
    std::cout << std::endl << std::endl;
    
    clo.get_rules().add_option("test_rule1");
    clo.get_rules().add_option("test_rule2");
    clo.get_rules().add_option("test_rule3");
    clo.get_rules().add_expected_value();
    clo.get_rules().add_optional_value();
    clo.get_rules().get_option("test_rule1").add_option("test_rule4");
    clo.get_rules().get_option("test_rule1").add_option("test_rule5");
    clo.get_rules().get_option("test_rule2").add_option("test_rule6");
    clo.get_rules().get_option("test_rule3").add_option("test_rule7");
    clo.get_rules().get_option("test_rule3").get_option("test_rule7").add_option("test_rule1");
    clo.display_full_structure();
    
    
    
    std::cout << std::endl << std::endl;
    return 0;
}