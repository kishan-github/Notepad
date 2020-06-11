#include "mainwindow.h"

#include <QApplication>

// Driver method.
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Notepad");
    mainWindow.showMaximized();

    return app.exec();
}
