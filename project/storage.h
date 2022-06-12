#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include <QStringListModel>

#include "bookmodel.h"
#include "modelsortbooks.h"

// maintains all operations related to loading and saving data from/to persistent storage

class Storage : public QObject
{
    Q_OBJECT
public:
    explicit Storage(QObject *parent = nullptr);

public:
    QString getFileName() const {return _fileName;}
    void setFileName(const QString& fileName) {_fileName = fileName;}

    BookModel* getBookModel() const {return _bookModel;}
    ModelSortBooks* getSortBooksModel() const {return _modelSortBooks;}

    QSortFilterProxyModel* getProxyModel() const {return _proxyModelSort;}
    // void setProxyModel(const QSortFilterProxyModel*& proxyModelSort) {_proxyModelSort = proxyModelSort;}

public:
    void loadFile(const QString& fileName); // loads a file using fileName

protected:
    bool readFile(); // returns true if succesfully

protected:
    QString _fileName;
    BookModel* _bookModel; // stores a ptr to our model
    ModelSortBooks* _modelSortBooks;
    QSortFilterProxyModel* _proxyModelSort;

signals:
    void onFileRead();
};

#endif // STORAGE_H
