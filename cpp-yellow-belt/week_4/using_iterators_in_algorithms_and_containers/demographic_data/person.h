#pragma once

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
    int age; 
    Gender gender; 
    bool is_employed; 
};
