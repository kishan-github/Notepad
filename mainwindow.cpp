#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"
#include "helperclass.h"

#include <QDebug>
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCut_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(cursor.hasSelection())
    {
        Data::copiedText = cursor.selectedText();
        cursor.removeSelectedText();
    }
}

void MainWindow::on_actionCopy_triggered()
{
    Data::copiedText = ui->textEdit->textCursor().selectedText();
}

void MainWindow::on_actionPaste_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(cursor.hasSelection())
    {
        cursor.removeSelectedText();
    }
    ui->textEdit->insertPlainText(Data::copiedText);
}
