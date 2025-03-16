#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipebook.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    recipeBook.loadRecipes(); // Load recipes when the app starts
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    Recipe newRecipe;
    newRecipe.name = ui->nameInput->text().toStdString();

    // Convert multi-line text into a vector of ingredients
    QStringList ingredientList = ui->ingredientsInput->toPlainText().split("\n", Qt::SkipEmptyParts);
    for (const QString &ingredient : ingredientList)
    {
        newRecipe.ingredients.push_back(ingredient.toStdString());
    }

    newRecipe.instructions = ui->stepsInput->toPlainText().toStdString();

    recipeBook.addRecipe(newRecipe);
}

void MainWindow::on_loadButton_clicked()
{
    recipeBook.loadRecipes();

    std::vector<Recipe> vecRecipes = recipeBook.getRecipes();

    ui->recipeListWidget->clear();
    for (const Recipe &recipe : vecRecipes)
    {
        ui->recipeListWidget->addItem(QString::fromStdString(recipe.name));
    }
}
