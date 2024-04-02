#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>
#include <sstream>
#include "ingredient.h"

class Recipe {
public:
    std::string name;
    std::vector<Ingredient> ingredients;
    Recipe(const std::string& _name, const std::vector<Ingredient>& _ingredients)
        : name(_name), ingredients(_ingredients) {}

    std::string getIngredientsAsString() const;
};

#endif
