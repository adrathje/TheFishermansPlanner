#include <QtTest>
#include <weather.h>
#include <planner.h>
#include <fish.h>


class plannerTest : public QObject
{
    Q_OBJECT

public:
    plannerTest();
    ~plannerTest();

private slots:
    void test_case1();

};

plannerTest::plannerTest()
{

}

plannerTest::~plannerTest()
{

}


void plannerTest::test_case1()
{
    Fish fish1 = Fish(4, 13, "Bass");
    Planner p = Planner();
    QString bassyFish = fish1.getSpecies();
    p.setFish(bassyFish);
    QCOMPARE(p.getFish(), "Bass");
}

QTEST_APPLESS_MAIN(plannerTest)

#include "tst_plannertest.moc"
