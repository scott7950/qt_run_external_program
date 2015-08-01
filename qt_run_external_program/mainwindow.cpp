#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileInfo>

#include <QDebug>

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

void MainWindow::on_pushButton_clicked()
{
    bool result = false;
    FileExplorer fw;
    fw.setModal(true);

    while(!result) {

        fw.exec();

        if(fw.getCloseType() == true) {
            return;
        }

        fileName = fw.getFileName();

        QFileInfo checkFile(fileName);
        if (checkFile.exists() && checkFile.isExecutable()) {
           result = true;
        } else {
            result = false;

            QMessageBox msgBox;
            msgBox.setText("FIle is not executable");
            msgBox.exec();
        }
    }

    ui->lineEdit->setText(fileName);

    //fe = new FileExplorer(this);
    //fe->show();

}
