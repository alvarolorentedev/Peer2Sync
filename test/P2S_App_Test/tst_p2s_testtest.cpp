#include <QString>
#include <QtTest>

class P2S_TestTest : public QObject
{
    Q_OBJECT

public:
    P2S_TestTest();

private Q_SLOTS:
    void testCase1();
    void testRPCRoute();
};

P2S_TestTest::P2S_TestTest()
{
}

void P2S_TestTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void P2S_TestTest::testRPCRoute()
{
    QVERIFY2(true, "Failure");
}


QTEST_APPLESS_MAIN(P2S_TestTest)

#include "tst_p2s_testtest.moc"
