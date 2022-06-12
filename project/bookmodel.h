#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QAbstractTableModel>
#include <QFile>

class BookModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BookModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void saveDataFile(const QString& path);

public:
    void fillFromFile(QFile& file);        
    void appendRow(const QList<QVariant>& newRow);
    void removeSetRow(const QPair<QString, QString>& pairTitleAuthor);
    QList<int> findBookTitle(const QString& searchedTitle);

private:
    QList<QList<QVariant>> _dataTable;
    QList<QString> _headerList;
};

#endif // BOOKMODEL_H
