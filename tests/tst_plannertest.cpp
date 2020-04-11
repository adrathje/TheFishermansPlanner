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
    Fish fish2 = Fish(10, 3, "Sunny");
    Fish fish3 = Fish(0, 984, "Blue whale");
    vector<Fish> fish {fish1, fish2, fish3};
    Planner p = Planner();
    p.setFishList(fish);
    int size = p.getFishListSize();
    QCOMPARE(size, 3);
}

QTEST_APPLESS_MAIN(plannerTest)

#include "tst_plannertest.moc"
