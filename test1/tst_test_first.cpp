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
