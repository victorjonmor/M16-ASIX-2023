#include "recipebook.h"

void RecipeBook::addRecipe(const Recipe& recipe) {
    recipes.push_back(recipe);
}

std::vector<Recipe> RecipeBook::findRecipesWithIngredients(const std::vector<Ingredient>& availableIngredients) const {
    std::vector<Recipe> matchingRecipes;
    for (const auto& recipe : recipes) {
        bool allIngredientsAvailable = true;
        for (const auto& ingredient : recipe.ingredients) {
            bool found = false;
            for (const auto& availableIngredient : availableIngredients) {
                if (ingredient.name == availableIngredient.name) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                allIngredientsAvailable = false;
                break;
            }
        }
        if (allIngredientsAvailable) {
            matchingRecipes.push_back(recipe);
        }
    }
    return matchingRecipes;
}
