#include <bits/stdc++.h>
using namespace std;

struct Recipe
{
    string name;
    string category;
    vector<string> ingredients;
    vector<string> steps;
};

void addRecipe();
void viewRecipes();
void searchRecipe();
void deleteRecipe();
void updateRecipe();
void saveRecipe(const Recipe &recipe);
vector<Recipe> loadRecipes();

int main()
{
    int choice;
    do
    {
        cout << "\n=== Recipe Book Application ===\n";
        cout << "1. Add Recipe\n";
        cout << "2. View Recipes\n";
        cout << "3. Search Recipe\n";
        cout << "4. Delete Recipe\n";
        cout << "5. Update Recipe\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addRecipe();
            break;
        case 2:
            viewRecipes();
            break;
        case 3:
            searchRecipe();
            break;
        case 4:
            deleteRecipe();
            break;
        case 5:
            updateRecipe();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void addRecipe()
{
    Recipe recipe;
    cout << "Enter Recipe Name: ";
    getline(cin, recipe.name);
    cout << "Enter Category (e.g., Dessert, Main Course): ";
    getline(cin, recipe.category);

    cout << "Enter Ingredients (type 'done' to stop):\n";
    string ingredient;
    while (true)
    {
        getline(cin, ingredient);
        if (ingredient == "done")
            break;
        recipe.ingredients.push_back(ingredient);
    }

    cout << "Enter Cooking Steps (type 'done' to stop):\n";
    string step;
    while (true)
    {
        getline(cin, step);
        if (step == "done")
            break;
        recipe.steps.push_back(step);
    }

    saveRecipe(recipe);
    cout << "Recipe added successfully!\n";
}

void saveRecipe(const Recipe &recipe)
{
    ofstream file("recipes.txt", ios::app);
    file << recipe.name << "\n"
         << recipe.category << "\n";
    file << recipe.ingredients.size() << "\n";
    for (const string &ing : recipe.ingredients)
        file << ing << "\n";
    file << recipe.steps.size() << "\n";
    for (const string &step : recipe.steps)
        file << step << "\n";
    file.close();
}

vector<Recipe> loadRecipes()
{
    vector<Recipe> recipes;
    ifstream file("recipes.txt");
    if (!file)
        return recipes;

    while (!file.eof())
    {
        Recipe recipe;
        string line;
        getline(file, recipe.name);
        if (recipe.name.empty())
            break;
        getline(file, recipe.category);

        int num;
        file >> num;
        file.ignore();
        for (int i = 0; i < num; i++)
        {
            getline(file, line);
            recipe.ingredients.push_back(line);
        }

        file >> num;
        file.ignore();
        for (int i = 0; i < num; i++)
        {
            getline(file, line);
            recipe.steps.push_back(line);
        }

        recipes.push_back(recipe);
    }
    file.close();
    return recipes;
}

void viewRecipes()
{
    vector<Recipe> recipes = loadRecipes();
    if (recipes.empty())
    {
        cout << "No recipes available.\n";
        return;
    }

    for (const Recipe &recipe : recipes)
    {
        cout << "\nRecipe: " << recipe.name << "\nCategory: " << recipe.category << "\nIngredients:\n";
        for (const string &ing : recipe.ingredients)
            cout << "- " << ing << "\n";
        cout << "Steps:\n";
        for (const string &step : recipe.steps)
            cout << step << "\n";
    }
}

void searchRecipe()
{
    string searchName;
    cout << "Enter Recipe Name to search: ";
    cin.ignore();
    getline(cin, searchName);

    vector<Recipe> recipes = loadRecipes();
    for (const Recipe &recipe : recipes)
    {
        if (recipe.name == searchName)
        {
            cout << "\nRecipe: " << recipe.name << "\nCategory: " << recipe.category << "\nIngredients:\n";
            for (const string &ing : recipe.ingredients)
                cout << "- " << ing << "\n";
            cout << "Steps:\n";
            for (const string &step : recipe.steps)
                cout << step << "\n";
            return;
        }
    }
    cout << "Recipe not found.\n";
}

void deleteRecipe()
{
    string deleteName;
    cout << "Enter Recipe Name to delete: ";
    cin.ignore();
    getline(cin, deleteName);

    vector<Recipe> recipes = loadRecipes();
    vector<Recipe> updatedRecipes;
    bool found = false;

    for (const Recipe &recipe : recipes)
    {
        if (recipe.name != deleteName)
        {
            updatedRecipes.push_back(recipe);
        }
        else
        {
            found = true;
        }
    }

    if (!found)
    {
        cout << "Recipe not found.\n";
        return;
    }

    ofstream file("recipes.txt");
    for (const Recipe &recipe : updatedRecipes)
        saveRecipe(recipe);
    cout << "Recipe deleted successfully!\n";
}

void updateRecipe()
{
    string updateName;
    cout << "Enter Recipe Name to update: ";
    cin.ignore();
    getline(cin, updateName);

    vector<Recipe> recipes = loadRecipes();
    bool found = false;

    for (Recipe &recipe : recipes)
    {
        if (recipe.name == updateName)
        {
            found = true;
            cout << "Enter New Category: ";
            getline(cin, recipe.category);
            cout << "Enter New Ingredients (type 'done' to stop):\n";
            recipe.ingredients.clear();
            string ingredient;
            while (true)
            {
                getline(cin, ingredient);
                if (ingredient == "done")
                    break;
                recipe.ingredients.push_back(ingredient);
            }

            cout << "Enter New Cooking Steps (type 'done' to stop):\n";
            recipe.steps.clear();
            string step;
            while (true)
            {
                getline(cin, step);
                if (step == "done")
                    break;
                recipe.steps.push_back(step);
            }
            break;
        }
    }

    if (!found)
    {
        cout << "Recipe not found.\n";
        return;
    }

    ofstream file("recipes.txt");
    for (const Recipe &recipe : recipes)
        saveRecipe(recipe);
    cout << "Recipe updated successfully!\n";
}
