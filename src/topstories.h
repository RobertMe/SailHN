#ifndef TOPSTORIES_H
#define TOPSTORIES_H

#include <QNetworkReply>

#include "hnmodel.h"
#include "hnmodelitem.h"

class TopStories : public HnModel
{
    Q_OBJECT
public:
    explicit TopStories(QObject *parent = 0);

signals:

public slots:

private:
    void requestTopStories();

private slots:
    void topStoriesReceived(const QJsonDocument &document);

};

#endif // TOPSTORIES_H
