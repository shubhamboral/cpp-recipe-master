#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include <vector>
#include <string>

class Recipe
{
public:
    std::string name;
    std::string ingredients;
    std::string instructions;
};

class RecipeBook
{
private:
    std::vector<Recipe> recipes;

public:
    void addRecipe(const Recipe &recipe);
    std::vector<Recipe> getRecipes() const;
    void loadRecipes(); // ✅ Fix: Added this function declaration
};

#endif // RECIPEBOOK_H
