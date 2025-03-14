#include "recipebook.h"

void RecipeBook::addRecipe(const Recipe &recipe)
{
    recipes.push_back(recipe);
}

std::vector<Recipe> RecipeBook::getRecipes() const
{
    return recipes;
}

// ✅ Fix: Implemented `loadRecipes()`
void RecipeBook::loadRecipes()
{
    // Dummy implementation - replace with actual file reading logic
    Recipe sample;
    sample.name = "Pasta";
    sample.ingredients = "Tomato Sauce, Pasta, Cheese";
    sample.instructions = "Boil pasta, add sauce, mix cheese";

    recipes.push_back(sample);
}
