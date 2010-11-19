#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString loadFile;

private:
    Ui::MainWindow *ui;

private slots:
    void on_loadButton_clicked();
    void on_processButton_clicked();
    void on_saveButton_clicked();

signals:
    void validFileSelected();


};

#endif // MAINWINDOW_H
