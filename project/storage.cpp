#include "storage.h"

#include <stdexcept>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QSortFilterProxyModel>

Storage::Storage(QObject *parent)
    : QObject{parent}
{
     _bookModel = new BookModel(this);
}

void Storage::loadFile(const QString& fileName)
{
    _fileName = fileName;
    if (readFile())
        emit onFileRead(); // notify the MainWindow that the file was read properly
}

bool Storage::readFile()
{
    delete _bookModel;
    _bookModel = new BookModel(this);

    if (_fileName.isEmpty())
        throw std::invalid_argument("file name is not set");

    QFile file(_fileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox box;
        box.setText("cannot open file");
        box.exec();
       return false;
    }

    _bookModel->fillFromFile(file);
    file.close();

    return true;
}
