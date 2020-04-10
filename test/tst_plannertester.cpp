#include <QtTest>

// add necessary includes here

class plannerTester : public QObject
{
    Q_OBJECT

public:
    plannerTester();
    ~plannerTester();

private slots:
    void test_case1();

};

plannerTester::plannerTester()
{

}

plannerTester::~plannerTester()
{

}

void plannerTester::test_case1()
{

}

QTEST_APPLESS_MAIN(plannerTester)

#include "tst_plannertester.moc"
