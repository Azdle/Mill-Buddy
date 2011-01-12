#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "input.h"
#include <QFileDialog>
#include <string>

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
     QString fileName = QFileDialog::getOpenFileName(this, tr("Load Gerber"), "", tr("Gerber Files (*.cmp);;All Files (*)"));
     if(!fileName.isEmpty()){
         MainWindow::loadFile = fileName;
         MainWindow::validFileSelected();
     }
}

void MainWindow::on_processButton_clicked(){
    statusBar()->showMessage(tr("The process function has not been implimeted yet. Pretending to check stdout."), 1500);
    MainWindow::processFile();
}

void MainWindow::on_saveButton_clicked(){
    statusBar()->showMessage(tr("The save function has not been implimeted yet."), 1500);
}

void MainWindow::processFile(){

input inputFile;
inputFile.readGerber(std::string(MainWindow::loadFile.toAscii()));
}
