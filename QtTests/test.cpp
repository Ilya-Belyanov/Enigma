#include <QtWidgets>
#include <QtTest/QtTest>
#include "enigma.h"
#include "qenigma.h"

class TestEnigma: public QObject
{
    Q_OBJECT

private slots:
    void testEnigmaChar();
    void testQEnigmaChar();
    void testEnigmaString();
    void testQEnigmaString();
    void testEnigmaRotate();
    void testQEnigmaRotate();

    void testCompareEnigmasChar();
    void testCompareEnigmasString();
};


void TestEnigma::testEnigmaChar()
{
    Enigma enigma;
    enigma.autoRotate = true;
    enigma.reload();

    char A = 'A';
    char aEncode = enigma.encode(A);
    enigma.reload();
    QCOMPARE(A, enigma.encode(aEncode));
}

void TestEnigma::testQEnigmaChar()
{
    QEnigma qenigma;
    qenigma.autoRotate = true;

    qenigma.reload();
    QChar A = 'A';
    QChar aEncode = qenigma.encode(A);
    qenigma.reload();

    QCOMPARE(A, qenigma.encode(aEncode));
}

void TestEnigma::testEnigmaString()
{
    Enigma enigma;

    enigma.reload();
    string loveLetter = "I LOVE YOU, BABY";
    string loveLetterEncode = enigma.encode(loveLetter);
    enigma.reload();

    QCOMPARE(loveLetter, enigma.encode(loveLetterEncode));
}

void TestEnigma::testQEnigmaString()
{
    QEnigma qenigma;

    qenigma.reload();
    QString loveLetter = "I LOVE YOU, BABY";
    QString loveLetterEncode = qenigma.encode(loveLetter);
    qenigma.reload();

    QCOMPARE(loveLetter, qenigma.encode(loveLetterEncode));
}

void TestEnigma::testEnigmaRotate()
{
    Enigma enigma;

    enigma.rotateRotor(0, 25);
    QCOMPARE(25, enigma.configRotor(0));

    enigma.rotateRotor(0, 26);
    QCOMPARE(0, enigma.configRotor(0));

    enigma.rotateRotor(0, -3);
    QCOMPARE(25, enigma.configRotor(0));

    enigma.rotateRotor(0, 24);
    enigma.rotateRotor(1, 24);
    enigma.rotateRotor(2, 24);

    enigma.rotateRotorUp1(0);
    QCOMPARE(25, enigma.configRotor(0));
    QCOMPARE(24, enigma.configRotor(1));
    QCOMPARE(24, enigma.configRotor(2));

    enigma.rotateRotorUp1(0);
    QCOMPARE(0, enigma.configRotor(0));
    QCOMPARE(25, enigma.configRotor(1));
    QCOMPARE(24, enigma.configRotor(2));

    enigma.rotateRotorUp1(1);
    QCOMPARE(0, enigma.configRotor(0));
    QCOMPARE(0, enigma.configRotor(1));
    QCOMPARE(25, enigma.configRotor(2));

    enigma.rotateRotorUp1(2);
    QCOMPARE(0, enigma.configRotor(0));
    QCOMPARE(0, enigma.configRotor(1));
    QCOMPARE(0, enigma.configRotor(2));
}

void TestEnigma::testQEnigmaRotate()
{
    QEnigma qenigma;

    qenigma.rotateRotor(0, 25);
    QCOMPARE(25, qenigma.configRotor(0));

    qenigma.rotateRotor(0, 26);
    QCOMPARE(0, qenigma.configRotor(0));

    qenigma.rotateRotor(0, -3);
    QCOMPARE(25, qenigma.configRotor(0));

    qenigma.rotateRotor(0, 24);
    qenigma.rotateRotor(1, 24);
    qenigma.rotateRotor(2, 24);

    qenigma.rotateRotorUp1(0);
    QCOMPARE(25, qenigma.configRotor(0));
    QCOMPARE(24, qenigma.configRotor(1));
    QCOMPARE(24, qenigma.configRotor(2));

    qenigma.rotateRotorUp1(0);
    QCOMPARE(0, qenigma.configRotor(0));
    QCOMPARE(25, qenigma.configRotor(1));
    QCOMPARE(24, qenigma.configRotor(2));

    qenigma.rotateRotorUp1(1);
    QCOMPARE(0, qenigma.configRotor(0));
    QCOMPARE(0, qenigma.configRotor(1));
    QCOMPARE(25, qenigma.configRotor(2));

    qenigma.rotateRotorUp1(2);
    QCOMPARE(0, qenigma.configRotor(0));
    QCOMPARE(0, qenigma.configRotor(1));
    QCOMPARE(0, qenigma.configRotor(2));
}

void TestEnigma::testCompareEnigmasChar()
{
    Enigma enigma;
    QEnigma qenigma;

    enigma.autoRotate = true;
    qenigma.autoRotate = true;

    QCOMPARE(enigma.encode('A'), QString(qenigma.encode('A')).toStdString()[0]);
    QCOMPARE(enigma.encode('B'), QString(qenigma.encode('B')).toStdString()[0]);
    QCOMPARE(enigma.encode('W'), QString(qenigma.encode('W')).toStdString()[0]);
    QCOMPARE(enigma.encode('Q'), QString(qenigma.encode('Q')).toStdString()[0]);
}

void TestEnigma::testCompareEnigmasString()
{
    Enigma enigma;
    QEnigma qenigma;

    string sloveLetter = "I LOVE YOU, BABY";
    QString loveLetter = "I LOVE YOU, BABY";
    QCOMPARE(enigma.encode(sloveLetter), qenigma.encode(loveLetter).toStdString());
}

QTEST_MAIN(TestEnigma)
#include "test.moc"
