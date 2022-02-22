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

#include "daydata.h"

DayData::DayData(QDate d, QString msg)
{
    m_date = d;
    m_message = msg;
}

void DayData::editMessage(QString msg)
{
    m_message = msg;
}

QString DayData::getMessage()
{
    return m_message;
}

QDate DayData::getDate()
{
    return m_date;
}
