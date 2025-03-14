#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox> // ✅ Fix: Included QMessageBox
#include <QList>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    Recipe newRecipe;
    newRecipe.name = ui->nameInput->text().toStdString(); // ✅ Fix: Converted QString to std::string
    newRecipe.ingredients = ui->ingredientsInput->toPlainText().toStdString();
    newRecipe.instructions = ui->instructionsInput->toPlainText().toStdString();

    if (newRecipe.name.empty())
    { // ✅ Fix: Used `.empty()` instead of `.isEmpty()`
        QMessageBox::warning(this, "Warning", "Recipe name cannot be empty!");
        return;
    }

    recipeBook.addRecipe(newRecipe);
    ui->recipeListWidget->addItem(QString::fromStdString(newRecipe.name)); // ✅ Fix: Converted std::string to QString
}

void MainWindow::on_loadButton_clicked()
{
    recipeBook.loadRecipes();

    std::vector<Recipe> vecRecipes = recipeBook.getRecipes();
    QList<Recipe> recipes = QList<Recipe>::fromStdVector(vecRecipes); // ✅ Fix: Convert std::vector to QList

    ui->recipeListWidget->clear();
    for (const Recipe &recipe : recipes)
    {
        ui->recipeListWidget->addItem(QString::fromStdString(recipe.name)); // ✅ Fix: Convert std::string to QString
    }
}
