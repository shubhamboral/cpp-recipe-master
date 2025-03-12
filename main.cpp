#include <QApplication>
#include "recipebook.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    RecipeBook window;
    window.show();

    return app.exec();
}
