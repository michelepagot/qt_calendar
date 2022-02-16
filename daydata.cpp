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
