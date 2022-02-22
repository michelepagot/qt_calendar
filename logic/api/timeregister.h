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
#ifndef TIMEREGISTER_H
#define TIMEREGISTER_H

#include <QString>
#include <QList>
#include "daydata.h"

class TimeRegister
{
public:
    TimeRegister(int year);
    bool loadFromFile(QString);
    bool saveToFile(QString);
    bool add(QDate d, QString msg);
    bool remove(QDate date);
    bool have(QDate date);
    QString getMessage(QDate date);

private:
    int m_year;
    QList<DayData*> m_data;

};

#endif // TIMEREGISTER_H
