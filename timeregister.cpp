#include "timeregister.h"

TimeRegister::TimeRegister(int year)
{
    m_data.clear();
}

bool TimeRegister::loadFromFile(QString)
{
    return true;
}

bool TimeRegister::saveToFile(QString)
{
    return true;
}

bool TimeRegister::add(DayData *d)
{
    if(m_data.contains(d))
    {
        return false;
    }
    m_data.append(d);
    return true;
}

bool TimeRegister::have(QDate date)
{
    QList<DayData*>::iterator i;
    if(m_data.isEmpty())
    {
        return false;
    }
    for (i = m_data.begin(); i != m_data.end(); ++i)
    {
        if(date == (*i)->getDate())
        {
            return true;
        }
    }
    return false;
}

QString TimeRegister::getMessage(QDate date)
{
    QList<DayData*>::iterator i;
    QString ret = QString("");
    if(m_data.isEmpty())
    {
        return ret;
    }
    for (i = m_data.begin(); i != m_data.end(); ++i)
    {
        if(date == (*i)->getDate())
        {
            ret = (*i)->getMessage();
        }
    }
    return ret;
}

bool TimeRegister::remove(QDate date)
{
    QList<DayData*>::iterator i;
    if(m_data.isEmpty())
    {
        return false;
    }
    for (i = m_data.begin(); i != m_data.end(); ++i)
    {
        if(date == (*i)->getDate())
        {
            delete *i;
            return true;
        }
    }
    return false;
}
