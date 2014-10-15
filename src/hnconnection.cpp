#include "hnconnection.h"

#include <QNetworkReply>
#include <QHash>
#include <QPointer>
#include <QJsonDocument>
#include <QJsonParseError>

HnConnection *HnConnection::s_instance = 0;

HnConnection::HnConnection(QObject *parent) :
    QObject(parent),
    m_network(new QNetworkAccessManager())
{
    QObject::connect(m_network, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyReceived(QNetworkReply*)));
}

HnConnection *HnConnection::instance()
{
    if (!s_instance) {
        s_instance = new HnConnection();
    }

    return s_instance;
}

void HnConnection::get(QString path, QObject *callbackReceiver, const QString &callbackMember)
{
    QNetworkRequest request;
    request.setUrl(QUrl("https://hacker-news.firebaseio.com/" + path));
    QNetworkReply *reply = m_network->get(request);

    Callback callback(callbackReceiver, callbackMember);
    m_callbacks.insert(reply, callback);
}

void HnConnection::replyReceived(QNetworkReply *reply)
{
    reply->deleteLater();
    if (!m_callbacks.contains(reply)) {
        return;
    }

    Callback callback = m_callbacks.take(reply);
    if (callback.receiver().isNull()) {
        return;
    }

    QByteArray content = reply->readAll();
    QJsonParseError error;
    QJsonDocument document = QJsonDocument::fromJson(content, &error);
    if (error.error == QJsonParseError::NoError) {
        QMetaObject::invokeMethod(callback.receiver().data(), callback.member().toLocal8Bit(), Qt::DirectConnection, Q_ARG(const QJsonDocument&, document));
    }
}
