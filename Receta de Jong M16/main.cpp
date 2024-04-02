#include <iostream>
#include <sstream>
#include "recipebook.h"

int main() {
    RecipeBook recipeBook;

    recipeBook.addRecipe(Recipe("Ensalada César", { Ingredient("Lechuga"), Ingredient("Pollo"), Ingredient("Queso Parmesano"), Ingredient("Salsa César") }));
    recipeBook.addRecipe(Recipe("Espaguetis a la boloñesa", { Ingredient("Espaguetis"), Ingredient("Carne picada"), Ingredient("Tomate"), Ingredient("Cebolla") }));
    recipeBook.addRecipe(Recipe("Tarta de manzana", { Ingredient("Manzana"), Ingredient("Harina"), Ingredient("Azúcar"), Ingredient("Mantequilla") }));

    std::cout << "Ingrese los ingredientes que tiene, separados por espacios (sin acentos ni caracteres especiales): ";
    std::string ingredientInput;
    std::getline(std::cin, ingredientInput);

    std::vector<Ingredient> availableIngredients;
    std::istringstream iss(ingredientInput);
    std::string ingredientName;
    while (iss >> ingredientName) {
        availableIngredients.push_back(Ingredient(ingredientName));
    }

    std::vector<Recipe> matchingRecipes = recipeBook.findRecipesWithIngredients(availableIngredients);

    if (matchingRecipes.empty()) {
        std::cout << "Lo siento, no se encontraron recetas con esos ingredientes.\n";
    }
    else {
        std::cout << "Recetas que puedes preparar:\n";
        for (const auto& recipe : matchingRecipes) {
            std::cout << "- " << recipe.name << ": " << recipe.getIngredientsAsString() << std::endl;
        }
    }

    return 0;
}
