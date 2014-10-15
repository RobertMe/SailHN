#include "hnmodel.h"

#include <QJsonObject>
#include <QJsonValue>

#include "hnconnection.h"

HnModel::HnModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

void HnModel::setItemIds(const QList<int> &itemIds)
{
    beginResetModel();
    m_itemIds = itemIds;
    qDeleteAll(m_items);
    m_items.clear();
    m_pendingItemIds.clear();
    endResetModel();
}

int HnModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_itemIds.size();
}

QVariant HnModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_itemIds.size()) {
        return QVariant();
    }

    int itemId = m_itemIds.at(index.row());
    if (role == RoleId) {
        return itemId;
    }

    HnModelItem* item = m_items.value(itemId);
    if (!item) {
        ((HnModel*)this)->requestItem(itemId);
        return QVariant();
    }

    if (role == RoleId) {
        return item->id();
    } else if (role == RoleDeleted) {
        return item->deleted();
    } else if (role == RoleType) {
        return item->type();
    } else if (role == RoleBy) {
        return item->by();
    } else if (role == RoleTime) {
        return item->time();
    } else if (role == RoleText) {
        return item->text();
    } else if (role == RoleDead) {
        return item->dead();
    } else if (role == RoleParent) {
        return item->parent();
    } else if (role == RoleKids) {
        //return item->kids();
    } else if (role == RoleUrl) {
        return item->url();
    } else if (role == RoleScore) {
        return item->score();
    } else if (role == RoleTitle) {
        return item->title();
    } else if (role == RoleParts) {
        //return item->parts();
    }

    return QVariant();
}

int HnModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 1;
}

QModelIndex HnModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return createIndex(row, column);
}

QModelIndex HnModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child)
    return QModelIndex();
}

QHash<int, QByteArray> HnModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RoleId] = "id";
    roles[RoleDeleted] = "deleted";
    roles[RoleType] = "type";
    roles[RoleBy] = "by";
    roles[RoleTime] = "time";
    roles[RoleText] = "text";
    roles[RoleDead] = "dead";
    roles[RoleParent] = "parent";
    roles[RoleKids] = "kids";
    roles[RoleUrl] = "url";
    roles[RoleScore] = "score";
    roles[RoleTitle] = "title";
    roles[RoleParts] = "parts";
    return roles;
}

void HnModel::requestItem(const int itemId)
{
    if (m_pendingItemIds.contains(itemId)) {
        return;
    }

    HnConnection::instance()->get("v0/item/" + QString::number(itemId) + ".json", this, "itemReceived");
    m_pendingItemIds.append(itemId);
}

void HnModel::itemReceived(const QJsonDocument document)
{
    if (!document.isObject() || !document.object().contains("id")) {
        return;
    }

    QJsonObject jsonItem = document.object();
    int itemId = jsonItem.value("id").toVariant().toInt();
    m_pendingItemIds.removeOne(itemId);

    HnModelItem *item = new HnModelItem();
    item->setId(itemId);
    item->setBy(jsonItem.value("by").toString());
    item->setDead(jsonItem.value("dead").toBool());
    item->setDeleted(jsonItem.value("deleted").toBool());
    item->setParent(jsonItem.value("parent").toVariant().toInt());
    item->setScore(jsonItem.value("score").toVariant().toInt());
    item->setText(jsonItem.value("text").toString());
    item->setTime(QDateTime::fromTime_t(jsonItem.value("time").toVariant().toInt()));
    item->setTitle(jsonItem.value("title").toString());
    item->setUrl(jsonItem.value("url").toVariant().toUrl());

    int row = m_itemIds.indexOf(itemId);
    m_items.insert(itemId, item);

    emit dataChanged(index(row, 0, QModelIndex()), index(row, 0, QModelIndex()));
}
