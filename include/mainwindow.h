#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipebook.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addRecipeButton_clicked();
    void on_viewRecipesButton_clicked();
    void on_searchRecipeButton_clicked();
    void on_deleteRecipeButton_clicked();
    void on_updateRecipeButton_clicked();

private:
    Ui::MainWindow *ui;
    RecipeBook recipeBook;
};

#endif // MAINWINDOW_H
