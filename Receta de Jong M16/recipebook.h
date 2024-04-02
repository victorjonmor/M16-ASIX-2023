#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include "recipe.h"

class RecipeBook {
private:
    std::vector<Recipe> recipes;
public:
    void addRecipe(const Recipe& recipe);
    std::vector<Recipe> findRecipesWithIngredients(const std::vector<Ingredient>& availableIngredients) const;
};

#endif
