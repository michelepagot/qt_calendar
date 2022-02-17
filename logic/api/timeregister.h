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
