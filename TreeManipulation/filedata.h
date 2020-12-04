#ifndef FILEDATA_H
#define FILEDATA_H

#include <QDialog>
#include <QIcon>

namespace Ui {
class FileData;
}

class FileData : public QDialog
{
    Q_OBJECT

public:
    explicit FileData(QIcon FileIcon, QString FileName, QString FileDirectory, int FileSize);
    ~FileData();

private:
    Ui::FileData *ui;

    QIcon FileIcon;
    QString FileName, FileDirectory;
    int FileSize;
};

#endif // FILEDATA_H
