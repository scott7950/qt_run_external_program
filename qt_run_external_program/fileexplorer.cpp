#include "fileexplorer.h"
#include "ui_fileexplorer.h"

#include <QDir>
#include <QDebug>

FileExplorer::FileExplorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileExplorer)
{
    ui->setupUi(this);

    //QString sPath = "C:/";
    QString sPath = QDir::currentPath();
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    ui->treeView->setModel(dirmodel);

    filemodel = new QFileSystemModel(this);
    //filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    dirmodel->setRootPath(sPath);
    ui->listView->setModel(filemodel);
}

FileExplorer::~FileExplorer()
{
    delete ui;
    delete dirmodel;
    delete filemodel;
}

void FileExplorer::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    dirmodel->setRootPath(sPath);
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}

void FileExplorer::on_listView_clicked(const QModelIndex &index)
{
    QString sPath = filemodel->fileInfo(index).absoluteFilePath();
    dirmodel->setRootPath(sPath);
    //ui->treeView->setRootIndex(dirmodel->setRootPath(sPath));
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}

void FileExplorer::on_listView_doubleClicked(const QModelIndex &index)
{
    fileName = filemodel->fileInfo(index).absoluteFilePath();
    closeType = false;
    this->close();
}

QString FileExplorer::getFileName() {
    return fileName;
}

bool FileExplorer::getCloseType() {
    return closeType;
}
