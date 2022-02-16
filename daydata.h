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
