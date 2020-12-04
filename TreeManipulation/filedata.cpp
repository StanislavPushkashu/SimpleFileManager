#include "filedata.h"
#include "ui_filedata.h"

#include <QIcon>
#include <QDialog>

FileData::FileData(QIcon FileIcon, QString FileName, QString FileDirectory, int FileSize) :
    QDialog(),
    ui(new Ui::FileData)
{
    ui->setupUi(this);

    this->FileIcon = FileIcon;
    this->FileName = FileName;
    this->FileDirectory = FileDirectory;
    this->FileSize = FileSize;

    ui->InputFileIconLabel->setPixmap(FileIcon.pixmap(QSize(128, 128)));
    ui->InputFileNameLabel->setText(FileName);
    ui->InputFileDirectoryLabel->setText(FileDirectory);
    ui->InputFileSizeLabel->setText(QString::number(FileSize) + " bytes");

    connect(ui->AcceptButton, &QPushButton::clicked, [=](){ accept(); });
}

FileData::~FileData()
{
    delete ui;
}
