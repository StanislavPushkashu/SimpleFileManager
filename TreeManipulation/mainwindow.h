#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "filedata.h"

#include <QDir>
#include <QFileSystemModel>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_TreeFileView_clicked(const QModelIndex &index);

    void on_TreeFileView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    FileData *FD;

    QFileSystemModel *FS = new QFileSystemModel();
    QDir *directory = new QDir("C:/");

    QFileInfo *F;
};
#endif // MAINWINDOW_H
