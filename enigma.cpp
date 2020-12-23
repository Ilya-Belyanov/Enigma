#include "enigma.h"

char Enigma::encode(char letter)
{
    forwardEncode(letter);
    reflection(letter);
    backEncode(letter);

    return letter;
}

void Enigma::forwardEncode(char &letter)
{
    int letterCode;
    for(unsigned i = 0; i < vrotors.size(); i++)
    {
        letterCode = preRotor(tr.enigmaCode[letter] + rotorConfig[i + 1] - rotorConfig[i]);
        letter = vrotors[i][decodeLetter(letterCode)];
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
    for(int i = vrotors.size(); i > 0; i--)
    {
        letterCode = preRotor(tr.enigmaCode[letter] + rotorConfig[i] - rotorConfig[i + 1]);
        letter = encodeRotor(vrotors[i - 1], decodeLetter(letterCode));
    }

    letterCode = preRotor(tr.enigmaCode[letter] + rotorConfig[0] - rotorConfig[1]);
    letter = decodeLetter(letterCode);
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
    return vrotors.size();
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

int* Enigma::rotor(unsigned idRotor)
{
    return &rotorConfig[idRotor + 1];
}
