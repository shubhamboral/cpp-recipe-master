#include "recipebook.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>

RecipeBook::RecipeBook(QWidget *parent) : QWidget(parent) {
    // Set up layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Title label
    QLabel *title = new QLabel("📖 Digital Recipe Book", this);
    title->setAlignment(Qt::AlignCenter);

    // Text area to display recipes
    recipeDisplay = new QTextEdit(this);
    recipeDisplay->setReadOnly(true);

    // Buttons
    QPushButton *addRecipeBtn = new QPushButton("➕ Add Recipe", this);
    QPushButton *loadRecipesBtn = new QPushButton("📂 Load Recipes", this);

    // Add widgets to layout
    layout->addWidget(title);
    layout->addWidget(recipeDisplay);
    layout->addWidget(addRecipeBtn);
    layout->addWidget(loadRecipesBtn);

    setLayout(layout);
    setWindowTitle("Recipe Book");
    resize(400, 300); // Set window size

    // Connect button signals to slots
    connect(addRecipeBtn, &QPushButton::clicked, this, &RecipeBook::addRecipe);
    connect(loadRecipesBtn, &QPushButton::clicked, this, &RecipeBook::loadRecipes);
}

// Function to add a new recipe
void RecipeBook::addRecipe() {
    QString recipeName = QInputDialog::getText(this, "New Recipe", "Enter recipe name:");
    if (recipeName.isEmpty()) return;

    QString recipeDetails = QInputDialog::getMultiLineText(this, "Recipe Details", "Enter recipe steps:");
    if (recipeDetails.isEmpty()) return;

    QFile file("recipes.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << recipeName << "\n" << recipeDetails << "\n---\n";
        file.close();
    }

    QMessageBox::information(this, "Success", "Recipe added!");
}

// Function to load and display saved recipes
void RecipeBook::loadRecipes() {
    QFile file("recipes.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open recipe file.");
        return;
    }

    QTextStream in(&file);
    recipeDisplay->setPlainText(in.readAll());
    file.close();
}
