#ifndef HNMODEL_H
#define HNMODEL_H

#include <QAbstractItemModel>
#include <QJsonDocument>

#include "hnmodelitem.h"

class HnModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum Roles {
        RoleId = Qt::UserRole + 1,
        RoleDeleted,
        RoleType,
        RoleBy,
        RoleTime,
        RoleText,
        RoleDead,
        RoleParent,
        RoleKids,
        RoleUrl,
        RoleScore,
        RoleTitle,
        RoleParts
    };

    explicit HnModel(QObject *parent = 0);

    void setItemIds(const QList<int> &itemIds);
    Q_INVOKABLE HnModelItem *get(const int index) const;

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    int columnCount(const QModelIndex &parent) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;

signals:

public slots:

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    void requestItem(const int itemId);

    QHash<int, HnModelItem *> m_items;
    QList<int> m_itemIds;
    QList<int> m_pendingItemIds;

private slots:
    void itemReceived(const QJsonDocument document);
};

#endif // HNMODEL_H
