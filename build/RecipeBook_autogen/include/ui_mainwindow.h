/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *recipeListWidget;
    QLineEdit *nameInput;
    QLineEdit *categoryInput;
    QTextEdit *ingredientsInput;
    QTextEdit *stepsInput;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *viewButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        recipeListWidget = new QListWidget(centralwidget);
        recipeListWidget->setObjectName("recipeListWidget");

        verticalLayout->addWidget(recipeListWidget);

        nameInput = new QLineEdit(centralwidget);
        nameInput->setObjectName("nameInput");

        verticalLayout->addWidget(nameInput);

        categoryInput = new QLineEdit(centralwidget);
        categoryInput->setObjectName("categoryInput");

        verticalLayout->addWidget(categoryInput);

        ingredientsInput = new QTextEdit(centralwidget);
        ingredientsInput->setObjectName("ingredientsInput");

        verticalLayout->addWidget(ingredientsInput);

        stepsInput = new QTextEdit(centralwidget);
        stepsInput->setObjectName("stepsInput");

        verticalLayout->addWidget(stepsInput);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");

        verticalLayout->addWidget(deleteButton);

        viewButton = new QPushButton(centralwidget);
        viewButton->setObjectName("viewButton");

        verticalLayout->addWidget(viewButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        nameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Recipe Name", nullptr));
        categoryInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        ingredientsInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ingredients (one per line)", nullptr));
        stepsInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Steps (one per line)", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add Recipe", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete Recipe", nullptr));
        viewButton->setText(QCoreApplication::translate("MainWindow", "View Recipe", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
