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
#ifndef DAYDATA_H
#define DAYDATA_H

#include <QString>
#include <QDate>

class DayData
{
public:
    DayData(QDate d, QString msg);
    QString getMessage();
    void editMessage(QString msg);
    QDate getDate();

private:
    QDate m_date;
    QString m_message;
};

#endif // DAYDATA_H
