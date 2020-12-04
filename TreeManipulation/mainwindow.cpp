#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "filedata.h"

#include <QDebug>
#include <QDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FS->setRootPath(directory->path());

    ui->TreeFileView->setModel(FS);
    ui->ListFileView->setModel(FS);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_TreeFileView_clicked(const QModelIndex &index)
{
    QString newPath = FS->fileInfo(index).absoluteFilePath();
    ui->ListFileView->setRootIndex(FS->setRootPath(newPath));
}

void MainWindow::on_TreeFileView_doubleClicked(const QModelIndex &index)
{
    QIcon FileIcon = FS->fileIcon(index);
    int FileSize = FS->fileInfo(index).size();
    QString FileDirectory = FS->fileInfo(index).absoluteFilePath();
    QString FileName = FS->fileName(index);

    FD = new FileData(FileIcon, FileName, FileDirectory, FileSize);

    FD->exec();
}
