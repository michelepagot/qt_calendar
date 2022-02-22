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

#include <QtTest>
#include "timeregister.h"

class TimeRegisterTest : public QObject
{
    Q_OBJECT

public:
    TimeRegisterTest();
    ~TimeRegisterTest();

private slots:
    void test_newNotHaveSpecificDate();
    void test_noDateAddHave();
    void test_noSameDateAdd();
    void test_noSameDateDiffMsgAdd();
    void test_addRemoveAddTheSame();

};

TimeRegisterTest::TimeRegisterTest()
{

}

TimeRegisterTest::~TimeRegisterTest()
{

}

void TimeRegisterTest::test_newNotHaveSpecificDate()
{
  TimeRegister *x = new TimeRegister(2008);
  QVERIFY(!x->have(QDate(1,1,2001)));
  delete x;
}

void TimeRegisterTest::test_noDateAddHave()
{
  TimeRegister *x = new TimeRegister(2008);
  QDate d(1995, 5, 17);
  QVERIFY(x->add(d,QString("BauBau")));
  QVERIFY(x->have(d));
  delete x;
}

void TimeRegisterTest::test_noSameDateAdd()
{
  TimeRegister *x = new TimeRegister(2008);
  QDate d(1995, 5, 17);
  QString s("BauBau");
  QVERIFY(x->add(d,s));
  QVERIFY(!x->add(d,s));
  delete x;
}

void TimeRegisterTest::test_noSameDateDiffMsgAdd()
{
  TimeRegister *x = new TimeRegister(2008);
  QDate d(1995, 5, 17);
  QVERIFY(x->add(d,QString("BauBau")));
  QVERIFY(!x->add(d,QString("CiaoCiao")));
  delete x;
}

void TimeRegisterTest::test_addRemoveAddTheSame()
{
  TimeRegister *x = new TimeRegister(2008);
  QDate d(1995, 5, 17);
  QString s("BauBau");
  QVERIFY(x->add(d,s));
  QVERIFY(x->remove(d));
  QVERIFY(x->add(d,s));
  delete x;
}

QTEST_APPLESS_MAIN(TimeRegisterTest)

#include "tst_test_first.moc"
