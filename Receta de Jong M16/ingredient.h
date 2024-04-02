#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

struct Ingredient {
    std::string name;
    Ingredient(const std::string& _name) : name(_name) {}
};

#endif
