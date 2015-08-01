#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class FileExplorer;
}

class FileExplorer : public QDialog
{
    Q_OBJECT

public:
    explicit FileExplorer(QWidget *parent = 0);
    ~FileExplorer();

    QString getFileName();
    bool getCloseType();
    virtual int exec() {
        closeType = true;
        return QDialog::exec();
    }

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::FileExplorer *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    QString fileName;
    bool closeType = true;
};

#endif // FILEEXPLORER_H
