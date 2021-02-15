#pragma once 
#include <string>

class Animal {
public:
    Animal(const std::string& name);
    
    const std::string Name; 
};

class Dog : public Animal {
public:
    Dog(const std::string& name);

    void Bark();
};
