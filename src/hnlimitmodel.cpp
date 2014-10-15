#include "hnlimitmodel.h"

HnLimitModel::HnLimitModel(QObject *parent) :
    QSortFilterProxyModel(parent),
    m_limit(5)
{
}

int HnLimitModel::rowCount(const QModelIndex &parent) const
{
    if (!sourceModel()) {
        return 0;
    }

    return sourceModel()->rowCount(parent) < m_limit ? sourceModel()->rowCount(parent) : m_limit;
}

QModelIndex HnLimitModel::mapFromSource(const QModelIndex &sourceIndex) const
{
    return sourceIndex;
}

QModelIndex HnLimitModel::mapToSource(const QModelIndex &proxyIndex) const
{
    return proxyIndex;
}

int HnLimitModel::limit() const
{
    return m_limit;
}

void HnLimitModel::setLimit(const int limit)
{
    beginResetModel();
    m_limit = limit;
    endResetModel();
    emit limitChanged();
}
