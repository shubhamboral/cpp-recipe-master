#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include <vector>
#include <string>

struct Recipe
{
    std::string name;
    std::vector<std::string> ingredients;
    std::string instructions;
};

class RecipeBook
{
private:
    std::vector<Recipe> recipes;
    void saveRecipes() const;

public:
    RecipeBook();
    void addRecipe(const Recipe &recipe);
    std::vector<Recipe> getRecipes() const;
    void loadRecipes();
};

#endif // RECIPEBOOK_H
