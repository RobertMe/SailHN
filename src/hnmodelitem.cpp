#include "hnmodelitem.h"

HnModelItem::HnModelItem()
{
}

int HnModelItem::id() const
{
    return m_id;
}

void HnModelItem::setId(const int id)
{
    m_id = id;
    emit idChanged();
}

bool HnModelItem::deleted() const
{
    return m_deleted;
}

void HnModelItem::setDeleted(const bool deleted)
{
    m_deleted = deleted;
    emit deletedChanged();
}

HnModelItem::Types HnModelItem::type() const
{
    return m_type;
}

void HnModelItem::setType(const Types type)
{
    m_type = type;
    emit typeChanged();
}

QString HnModelItem::by() const
{
    return m_by;
}

void HnModelItem::setBy(const QString &by)
{
    m_by = by;
    emit byChanged();
}

QDateTime HnModelItem::time() const
{
    return m_time;
}

void HnModelItem::setTime(const QDateTime &time)
{
    m_time = time;
    emit timeChanged();
}

QString HnModelItem::text() const
{
    return m_text;
}

void HnModelItem::setText(const QString &text)
{
    m_text = text;
    emit textChanged();
}

bool HnModelItem::dead() const
{
    return m_dead;
}

void HnModelItem::setDead(const bool dead)
{
    m_dead = dead;
    emit deadChanged();
}

int HnModelItem::parent() const
{
    return m_parent;
}
void HnModelItem::setParent(const int parent)
{
    m_parent = parent;
    emit parentChanged();
}

QList<int> HnModelItem::kids() const
{
    return m_kids;
}

void HnModelItem::setKids(const QList<int> &kids)
{
    m_kids = kids;
    emit kidsChanged();
}

QUrl HnModelItem::url() const
{
    return m_url;
}

void HnModelItem::setUrl(const QUrl &url)
{
    m_url = url;
    emit urlChanged();
}

int HnModelItem::score() const
{
    return m_score;
}

void HnModelItem::setScore(const int score)
{
    m_score = score;
    emit scoreChanged();
}

QString HnModelItem::title() const
{
    return m_title;
}

void HnModelItem::setTitle(const QString &title)
{
    m_title = title;
    emit titleChanged();
}

QList<int> HnModelItem::parts() const
{
    return m_parts;
}

void HnModelItem::setParts(const QList<int> &parts)
{
    m_parts = parts;
    emit partsChanged();
}
