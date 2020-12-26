#include "enigma.h"

#include <QDebug>


Enigma::Enigma()
{
    clearSwitchPanel();
    enigmaLetter = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                    'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

    rotorConfig = {0, 16, 21, 2, 0};
}

char Enigma::encode(char letter)
{
    if (autoRotate)
        rotateRotorUp1(0);

    letter = switchPanel[letter];
    forwardEncode(letter);
    reflection(letter);
    backEncode(letter);

    return letter;
}

string Enigma::encode(string text)
{
    string encodeText;
    for(unsigned i = 0; i < text.size(); i++)
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

void Enigma::forwardEncode(char &letter)
{
    int letterCode;
    for(unsigned i = 0; i < vrotors.size() - 1; i++)
    {
        letterCode = preRotor(tr.enigmaCode[letter] + rotorConfig[i + 1] - rotorConfig[i]);
        letter = vrotors[i + 1][decodeLetter(letterCode)];
    }
}

void Enigma::reflection(char &letter)
{
    int letterCode = preRotor(tr.enigmaCode[letter] - rotorConfig[rotorConfig.size() - 2]);
    letter = reflectors.reflectorB[decodeLetter(letterCode)];
}

void Enigma::backEncode(char &letter)
{
    int letterCode;
    for(unsigned i = vrotors.size(); i > 0; i--)
    {
        letterCode = preRotor(tr.enigmaCode[letter] + rotorConfig[i - 1] - rotorConfig[i]);
        letter = encodeRotor(vrotors[i - 1], decodeLetter(letterCode));
    }
}

char Enigma::decodeLetter(int value)
{
    auto it = tr.enigmaCode.begin();
    while(it != tr.enigmaCode.end())
    {
        if(it->second == value)
            return it->first;
        it++;
    }
    return ' ';
}

char Enigma::encodeRotor(map<char, char> rotor, char value)
{
    auto it = rotor.begin();
    while(it != rotor.end())
    {
        if(it->second == value)
            return it->first;
        it++;
    }
    return ' ';
}

int Enigma::preRotor(int value)
{
    while (value >= countEncodeLetters)
            value -= countEncodeLetters;

    while (value < 0)
        value += countEncodeLetters;

    return value;
}

int Enigma::configRotor(unsigned idRotor)
{
    if (idRotor >= rotorConfig.size() - 2)
        return 0;

    return rotorConfig[idRotor + 1];
}

int Enigma::countRotors()
{
    return vrotors.size() - 1;
}

void Enigma::rotateRotor(unsigned idRotor, int value)
{
    if (idRotor >= rotorConfig.size() - 2)
        return;

    *rotor(idRotor) = value;
    checkRotor(idRotor);
}

void Enigma::rotateRotorUp1(unsigned idRotor)
{
    if (idRotor >= rotorConfig.size() - 2)
        return;

    *rotor(idRotor) += 1;
    checkRotor(idRotor);
}

void Enigma::rotateRotorDown1(unsigned idRotor)
{
    if (idRotor >= rotorConfig.size() - 2)
        return;

    *rotor(idRotor) -= 1;
    checkRotor(idRotor);
}

void Enigma::checkRotor(unsigned idRotor)
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

void Enigma::connectSwitch(char letterOne, char letterTwo)
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

vector<char> Enigma::availableLetter()
{
    return enigmaLetter;
}

map<char, char> Enigma::currentSwitchPanel()
{
    return switchPanel;
}

void Enigma::clearSwitchPanel()
{
    switchPanel = {{'Q', 'Q'}, {'W', 'W'}, {'E', 'E'}, {'R', 'R'}, {'T', 'T'}, {'Y', 'Y'}, {'U', 'U'},
                   {'I' ,'I'}, {'O', 'O'}, {'P', 'P'},
                   {'A', 'A'}, {'S', 'S'}, {'D', 'D'}, {'F', 'F'}, {'G', 'G'}, {'H', 'H'}, {'J', 'J'},
                   {'K', 'K'}, {'L', 'L'}, {'Z', 'Z'}, {'X', 'X'}, {'C', 'C'}, {'V', 'V'}, {'B', 'B'},
                   {'N', 'N'}, {'M', 'M'}};
}

int* Enigma::rotor(unsigned idRotor)
{
    return &rotorConfig[idRotor + 1];
}

bool Enigma::isEnigmaEncode(char letter)
{
    for(unsigned i = 0; i < enigmaLetter.size(); i++)
        if(letter == enigmaLetter[i])
            return true;
    return false;
}
