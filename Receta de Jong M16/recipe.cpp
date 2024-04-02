#include "recipe.h"

std::string Recipe::getIngredientsAsString() const {
    std::ostringstream oss;
    for (size_t i = 0; i < ingredients.size(); ++i) {
        oss << ingredients[i].name;
        if (i != ingredients.size() - 1) {
            oss << ", ";
        }
    }
    return oss.str();
}
