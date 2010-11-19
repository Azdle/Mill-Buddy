#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_loadButton_clicked(){
     QString fileString = QFileDialog::getOpenFileName(this, tr("Load Gerber"), "", tr("Gerber Files (*.cmp);;All Files (*)"));
     if(!fileString.isEmpty()){
         MainWindow::loadFile = fileString;
         MainWindow::validFileSelected();
     }
}

void MainWindow::on_processButton_clicked(){
    statusBar()->showMessage(tr("The process function has not been implimeted yet."), 15);
}

void MainWindow::on_saveButton_clicked(){
    statusBar()->showMessage(tr("The save function has not been implimeted yet."), 15);
}
