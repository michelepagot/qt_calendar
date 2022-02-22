/*
 *   qt calendar, a simple calendar to take notes
 *   Copyright (C) 2022  Michele Pagot <michele.pagot.dev@outlook.com>
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
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

bool TimeRegister::add(QDate d, QString msg)
{
    if(have(d))
    {
        return false;
    }
    DayData *p_dd = new DayData(d, msg);
    m_data.append(p_dd);
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
