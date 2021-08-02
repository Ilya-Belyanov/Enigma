#include "qenigma.h"


QEnigma::QEnigma()
{
    reload();
}

QChar QEnigma::encode(QChar letter)
{
    if (autoRotate)
        rotateRotorUp1(0);

    letter = switchPanel[letter];
    forwardEncode(letter);
    reflection(letter);
    backEncode(letter);

    return letter;
}

QString QEnigma::encode(QString text)
{
    QString encodeText;
    for(int i = 0; i < text.size(); i++)
    {
        if (isEnigmaEncode(text[i]))
        {
            if (!autoRotate)
                rotateRotorUp1(0);

            encodeText += encode(text[i]);
        }
        else if (text[i] != '\xd')
            encodeText += text[i];
    }
    return encodeText;
}

void QEnigma::forwardEncode(QChar &letter)
{
    int letterCode;
    for(int i = 0; i < vrotors.size() - 1; i++)
    {
        letterCode = preRotor(letter.toLatin1() + rotorConfig[i + 1] - rotorConfig[i]);
        letter = vrotors[i + 1][letterCode];
    }
}

void QEnigma::reflection(QChar &letter)
{
    int letterCode = preRotor(letter.toLatin1() - rotorConfig[rotorConfig.size() - 2]);
    letter = reflectors[letterCode];
}

void QEnigma::backEncode(QChar &letter)
{
    int letterCode;
    for(size_t i = vrotors.size(); i > 0; i--)
    {
        letterCode = preRotor(letter.toLatin1() + rotorConfig[i - 1] - rotorConfig[i]);
        letter = encodeRotor(vrotors[i - 1], letterCode);
    }
}

QChar QEnigma::encodeRotor(QMap<QChar, QChar> rotor, QChar value)
{
    auto it = rotor.begin();
    while(it != rotor.end())
    {
        if(it.value() == value)
            return it.key();
        it++;
    }
    return ' ';
}

int QEnigma::preRotor(int value)
{
    while (value >= startEnigmaCode + countEncodeLetters)
            value -= countEncodeLetters;

    while (value < startEnigmaCode)
        value += countEncodeLetters;

    return value;
}

int QEnigma::configRotor(int idRotor)
{
    if (idRotor >= rotorConfig.size() - 2)
        return 0;

    return rotorConfig[idRotor + 1];
}

int QEnigma::countRotors()
{
    return vrotors.size() - 1;
}

void QEnigma::rotateRotor(int idRotor, int value)
{
    if (idRotor >= rotorConfig.size() - 2)
        return;

    *rotor(idRotor) = value;
    checkRotor(idRotor);
}

void QEnigma::rotateRotorUp1(int idRotor)
{
    if (idRotor >= rotorConfig.size() - 2)
        return;

    *rotor(idRotor) += 1;
    checkRotor(idRotor);
}

void QEnigma::rotateRotorDown1(int idRotor)
{
    if (idRotor >= rotorConfig.size() - 2)
        return;

    *rotor(idRotor) -= 1;
    checkRotor(idRotor);
}

void QEnigma::checkRotor(size_t idRotor)
{
    if (*rotor(idRotor) >= countEncodeLetters)
    {
        *rotor(idRotor) = 0;
        rotateRotorUp1(idRotor + 1);
    }
    else if (*rotor(idRotor) < 0)
    {
        *rotor(idRotor) = countEncodeLetters - 1;
        rotateRotorDown1(idRotor + 1);
    }
}

void QEnigma::connectSwitch(QChar letterOne, QChar letterTwo)
{
    if (!isEnigmaEncode(letterOne) && !isEnigmaEncode(letterTwo))
        return;

    //Off old connect
    switchPanel[switchPanel[letterOne]] = switchPanel[letterOne];
    switchPanel[switchPanel[letterTwo]] = switchPanel[letterTwo];

    //On new connect
    switchPanel[letterOne] = letterTwo;
    switchPanel[letterTwo] = letterOne;
}

QVector<QChar> QEnigma::availableLetter()
{
    return enigmaLetter;
}

QMap<QChar, QChar> QEnigma::currentSwitchPanel()
{
    return switchPanel;
}

void QEnigma::clearSwitchPanel()
{
    switchPanel.clear();
    for(int i = 0; i < enigmaLetter.size(); i++)
        switchPanel[enigmaLetter[i]] = enigmaLetter[i];

}

void QEnigma::reload()
{
    enigmaLetter = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                    'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

    rotorConfig = {0, 16, 21, 2, 0};
    clearSwitchPanel();
}

int* QEnigma::rotor(size_t idRotor)
{
    return &rotorConfig[idRotor + 1];
}

bool QEnigma::isEnigmaEncode(QChar letter)
{
    for(int i = 0; i < enigmaLetter.size(); i++)
        if(letter == enigmaLetter[i])
            return true;
    return false;
}
