#include "bookmodel.h"

BookModel::BookModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

void BookModel::fillFromFile(QFile& file)
{
    QTextStream inputStream(&file);

    QString firstline = inputStream.readLine();    
    for (QString& item : firstline.split(","))
        _headerList.append(item);

    while (!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        QList<QVariant> dataRow;

        size_t startPos = 0;
        size_t columnNum = 0;
        while (dataRow.size() < _headerList.size() - 1)
        {
            columnNum += 1;
            size_t pos = line.indexOf(',', startPos);
            QString subLine = line.mid(startPos, pos - startPos);

            if (columnNum == 4)
                dataRow.append(subLine.toDouble());
            else if (columnNum == 5 || columnNum == 6)
                dataRow.append(subLine.toInt());
            else
                dataRow.append(subLine);

            startPos = pos + 1;
        }
        dataRow.append(line.mid(startPos));

        _dataTable.append(dataRow);
    }
    file.close();
}


int BookModel::rowCount(const QModelIndex& parent) const
{
    return _dataTable.size();
}

int BookModel::columnCount(const QModelIndex& parent) const
{
    return _dataTable[0].size();
}

QVariant BookModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return _headerList[section];

    return QVariant();
}

QVariant BookModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        int row = index.row();
        int col = index.column();
        return _dataTable[row][col];
    }

    return QVariant();
}

void BookModel::appendRow(const QList<QVariant>& newRow)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _dataTable.append(newRow);
    endInsertRows();
}


void BookModel::removeSetRow(const QPair<QString, QString>& pairTitleAuthor)
{
    int rowNum = rowCount();

    QString author = pairTitleAuthor.first;
    QString title = pairTitleAuthor.second;

    for (size_t i = 0; i < rowNum; ++i)
        if (_dataTable[i][0] == author && _dataTable[i][1] == title)
        {
            beginRemoveRows(QModelIndex(), i, i);
            endRemoveRows();
            _dataTable.removeAt(i);
        }
}

void outputRow(const QList<QVariant>& row, QTextStream& outputStream)
{
    bool firstItem = true;
    for (const QVariant& item : row)
    {
        if (firstItem)
        {
            outputStream << item.toString();
            firstItem = false;
        }
        else
        {
            outputStream << ",";
            outputStream << item.toString();
        }
    }
    outputStream << "\n";
}

void BookModel::saveDataFile(const QString& path)
{
    QFile outputFile(path);
    outputFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream outputStream(&outputFile);

    bool firstItem = true;
    for (const QString& item : _headerList)
    {
        if (firstItem)
        {
            outputStream << item;
            firstItem = false;
        }
        else
        {
            outputStream << ",";
            outputStream << item;
        }
    }
    outputStream << "\n";

    for (QList<QVariant>& row: _dataTable)
        outputRow(row, outputStream);

    outputFile.close();
}
