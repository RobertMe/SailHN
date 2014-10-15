#ifndef HNCONNECTION_H
#define HNCONNECTION_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QPointer>

class HnConnection : public QObject
{
    Q_OBJECT
public:
    static HnConnection *instance();

    void get(QString path, QObject *callbackReceiver, const QString &callbackMember);

signals:

public slots:

private:
    class Callback
    {
    public:
        Callback() {}
        Callback(QPointer<QObject> receiver, const QString &member):
            m_receiver(receiver), m_member(member) {}

        QPointer<QObject> receiver() { return m_receiver; }
        QString member() { return m_member; }

    private:
        QPointer<QObject> m_receiver;
        QString m_member;
    };

private:
    static HnConnection *s_instance;
    explicit HnConnection(QObject *parent = 0);

    QNetworkAccessManager *m_network;
    QHash<QNetworkReply *, Callback> m_callbacks;

private slots:
    void replyReceived(QNetworkReply *reply);

};

#endif // HNCONNECTION_H
