#ifndef QENIGMA_H
#define QENIGMA_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QMap>

#include "qconfig.h"


class QEnigma: QObject
{
    Q_OBJECT

public:
    QEnigma();

    QChar encode(QChar letter);
    QString encode(QString text);

    int configRotor(int idRotor);
    int countRotors();

    void rotateRotor(int idRotor, int value);
    void rotateRotorUp1(int idRotor);
    void rotateRotorDown1(int idRotor);

    bool isEnigmaEncode(QChar letter);

    void connectSwitch(QChar letterOne, QChar letterTwo);
    QVector<QChar> availableLetter();
    QMap<QChar, QChar> currentSwitchPanel();
    void clearSwitchPanel();
    void reload();

    bool autoRotate = false;

private:
    QVector<QMap<QChar, QChar>> vrotors = {QRotors::defaultRotor, QRotors::rotorI, QRotors::rotorII, QRotors::rotorIII};
    QMap<QChar, QChar> reflectors = QReflectors::reflectorB;

    void forwardEncode(QChar &letter);
    void reflection(QChar &letter);
    void backEncode(QChar &letter);
    int preRotor(int value);

    int* rotor(size_t idRotor);
    void checkRotor(size_t idRotor);

    QChar encodeRotor(QMap<QChar, QChar> rotor, QChar value);

    QVector<QChar> enigmaLetter;
    int startEnigmaCode = 65;
    int countEncodeLetters = QRotors::rotorI.size();

    QVector<int> rotorConfig;
    QMap<QChar, QChar> switchPanel;


};
#endif // QENIGMA_H
