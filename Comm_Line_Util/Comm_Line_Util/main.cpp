#include <iostream>
#include "CommLineOps.h"
#include "ArgumentRule.h"

int main(int argc, char** argv) {
    
    std::cout << "Hello, world!" << std::endl;
    
    CommLineOps clo;
    clo.get_command_line(argc,argv);
    clo.display_full_structure();
    
    std::cout << std::endl << std::endl;
    
    clo.get_rules().add_option("test_rule1");
    clo.get_rules().add_option("test_rule2");
    clo.get_rules().add_option("test_rule3");
    clo.get_rules().add_expected_value();
    clo.get_rules().add_optional_value();
    clo.get_rules().get_option(std::string("test_rule1")).add_option(std::string("test_rule4"));
    clo.get_rules().get_option(std::string("test_rule1")).add_option(std::string("test_rule5"));
    clo.get_rules().get_option(std::string("test_rule2")).add_option(std::string("test_rule6"));
    clo.get_rules().get_option(std::string("test_rule3")).add_option(std::string("test_rule7"));
    ArgumentRule& top = clo.get_rules();
    ArgumentRule& next_level = top.get_option(std::string("test_rule3"));
    ArgumentRule& final_level = next_level.get_option(std::string("test_rule7"));
    final_level.add_option(std::string("test_rule8"));
    ArgumentRule& test = clo.get_rules().get_option(std::string("test_rule3")).get_option(std::string("test_rule7")).get_option(std::string("test_rule8"));
    test.add_expected_value();
    test.add_optional_value();
    clo.get_rules().get_option(std::string("test_rule3")).get_option(std::string("test_rule7")).get_option(std::string("test_rule8")).add_option("test_rule9");
    clo.display_full_structure();
    
    
    
    std::cout << std::endl << std::endl;
    return 0;
}