#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include <string>
#include <vector>

struct Recipe
{
    std::string name;
    std::string category;
    std::vector<std::string> ingredients;
    std::vector<std::string> steps;
};

class RecipeBook
{
public:
    void addRecipe(const Recipe &recipe);
    std::vector<Recipe> getRecipes() const;
    bool deleteRecipe(const std::string &name);
    bool updateRecipe(const std::string &name, const Recipe &updatedRecipe);
    Recipe searchRecipe(const std::string &name) const;

private:
    std::vector<Recipe> recipes;
    void saveToFile() const;
    void loadFromFile();
};

#endif // RECIPEBOOK_H
