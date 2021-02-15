#include <iostream>

#include "animal.h"

Animal::Animal(const std::string& name): 
    Name(name) {  }

Dog::Dog(const std::string& name): 
    Animal(name) {  }

void Dog::Bark() {
    std::cout << Name << " barks: woof!"  << std::endl;
}
