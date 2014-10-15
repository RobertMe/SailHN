#ifndef HNMODELITEM_H
#define HNMODELITEM_H

#include <QObject>
#include <QDateTime>
#include <QUrl>

class HnModelItem : public QObject
{
    Q_OBJECT
    Q_ENUMS(Types)
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(bool deleted READ deleted WRITE setDeleted NOTIFY deletedChanged)
    Q_PROPERTY(Types type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString by READ by WRITE setBy NOTIFY byChanged)
    Q_PROPERTY(QDateTime time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(bool dead READ dead WRITE setDead NOTIFY deadChanged)
    Q_PROPERTY(int parent READ parent WRITE setParent NOTIFY parentChanged)
    Q_PROPERTY(QList<int> kids READ kids WRITE setKids NOTIFY kidsChanged)
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QList<int> parts READ parts WRITE setParts NOTIFY partsChanged)
public:
    enum Types {
        TypeJob,
        TypeStory,
        TypeComment,
        TypePoll,
        TypePollOption
    };

    HnModelItem();

    int id() const;
    void setId(const int id);

    bool deleted() const;
    void setDeleted(const bool deleted);

    Types type() const;
    void setType(const Types type);

    QString by() const;
    void setBy(const QString &by);

    QDateTime time() const;
    void setTime(const QDateTime &time);

    QString text() const;
    void setText(const QString &text);

    bool dead() const;
    void setDead(const bool dead);

    int parent() const;
    void setParent(const int parent);

    QList<int> kids() const;
    void setKids(const QList<int> &kids);

    QUrl url() const;
    void setUrl(const QUrl &url);

    int score() const;
    void setScore(const int score);

    QString title() const;
    void setTitle(const QString &title);

    QList<int> parts() const;
    void setParts(const QList<int> &parts);

signals:
    void idChanged();
    void deletedChanged();
    void typeChanged();
    void byChanged();
    void timeChanged();
    void textChanged();
    void deadChanged();
    void parentChanged();
    void kidsChanged();
    void urlChanged();
    void scoreChanged();
    void titleChanged();
    void partsChanged();

private:
    int m_id;
    bool m_deleted;
    Types m_type;
    QString m_by;
    QDateTime m_time;
    QString m_text;
    bool m_dead;
    int m_parent;
    QList<int> m_kids;
    QUrl m_url;
    int m_score;
    QString m_title;
    QList<int> m_parts;
};

#endif // HNMODELITEM_H
