#include "recipebook.h"
#include <fstream>
#include <sstream>

// Constructor: Load recipes from file when object is created
RecipeBook::RecipeBook()
{
    loadRecipes();
}

// Add a recipe and save it to file
void RecipeBook::addRecipe(const Recipe &recipe)
{
    recipes.push_back(recipe);
    saveRecipes(); // Save after adding
}

// Return all recipes
std::vector<Recipe> RecipeBook::getRecipes() const
{
    return recipes;
}

// Save recipes to "recipes.txt"
void RecipeBook::saveRecipes() const
{
    std::ofstream file("recipes.txt");
    if (!file)
        return;

    for (const auto &recipe : recipes)
    {
        file << recipe.name << '\n';
        for (const auto &ingredient : recipe.ingredients)
        {
            file << ingredient << ',';
        }
        file << '\n'
             << recipe.instructions << '\n'
             << "---\n"; // Separator
    }
}

// Load recipes from "recipes.txt"
void RecipeBook::loadRecipes()
{
    recipes.clear();
    std::ifstream file("recipes.txt");
    if (!file)
        return;

    std::string line;
    while (std::getline(file, line))
    {
        if (line == "---")
            continue; // Ignore separators

        Recipe recipe;
        recipe.name = line;

        std::getline(file, line);
        std::istringstream ingredientsStream(line);
        std::string ingredient;
        while (std::getline(ingredientsStream, ingredient, ','))
        {
            recipe.ingredients.push_back(ingredient);
        }

        std::getline(file, recipe.instructions);
        recipes.push_back(recipe);
    }
}
