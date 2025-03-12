#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include <QWidget>

class RecipeBook : public QWidget {
    Q_OBJECT  // Required for Qt signal-slot mechanism

public:
    explicit RecipeBook(QWidget *parent = nullptr);
};

#endif // RECIPEBOOK_H
