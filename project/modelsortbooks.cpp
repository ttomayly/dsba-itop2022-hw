#include "modelsortbooks.h"

ModelSortBooks::ModelSortBooks(const QList<QString>& searchedParamters, QObject *parent)
    : _searchedParamters(searchedParamters), QSortFilterProxyModel{parent}
{
}

bool ModelSortBooks::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    for (size_t i = 0; i < _searchedParamters.size(); ++i)
        if (_searchedParamters[i] != "")
            if (!sourceModel()->data(sourceModel()->index(source_row, i, source_parent)).toString().contains(_searchedParamters[i]))
                return false;

    return true;
}
