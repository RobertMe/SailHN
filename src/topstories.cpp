#include "topstories.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

#include "hnconnection.h"

TopStories::TopStories(QObject *parent) :
    HnModel(parent)
{
    requestTopStories();
}

void TopStories::requestTopStories()
{
    HnConnection::instance()->get("v0/topstories.json", this, "topStoriesReceived");
}

void TopStories::topStoriesReceived(const QJsonDocument &document)
{
    QList<int> ids;
    if (document.isArray()) {
        QJsonArray array = document.array();
        int i;
        for (i = 0; i < array.size(); i++) {
            ids.append(array.at(i).toVariant().toInt());
        }
    }
    setItemIds(ids);
}
