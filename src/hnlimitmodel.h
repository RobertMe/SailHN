#ifndef HNLIMITMODEL_H
#define HNLIMITMODEL_H

#include <QSortFilterProxyModel>

#include "hnmodel.h"

class HnLimitModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(int limit READ limit WRITE setLimit NOTIFY limitChanged)
public:
    explicit HnLimitModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;

    QModelIndex mapFromSource(const QModelIndex &sourceIndex) const;
    QModelIndex mapToSource(const QModelIndex &proxyIndex) const;

    int limit() const;
    void setLimit(const int limit);

signals:
    void limitChanged();
public slots:

private:
    int m_limit;
};

#endif // HNLIMITMODEL_H
