#ifndef MODELSORTBOOKS_H
#define MODELSORTBOOKS_H

#include <QSortFilterProxyModel>

class ModelSortBooks : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit ModelSortBooks(const QList<QString>& searchedParamters, QObject *parent = nullptr);

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const;

protected:
    QList<QString> _searchedParamters;
};

#endif // MODELSORTBOOKS_H
