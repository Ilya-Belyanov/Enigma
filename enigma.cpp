#include "enigma.h"
#include <QDebug>
#include <QString>

Enigma::Enigma()
{
    //qDebug() << tr.keyCode[rotors.rotorI["A"]];
    encode("A");
}


string Enigma::encode(string letter)
{
    for(unsigned i = 0; i < vrotors.size(); i++)
    {
        int input = preRotor(tr.enigmaCode[letter] + rotorConfig[i + 1] - rotorConfig[i]);
        string first = findKey(input);
        letter = vrotors[i][first];
    }

    int input = preRotor(tr.enigmaCode[letter] - rotorConfig[rotorConfig.size() - 2]);
    string first = findKey(input);
    letter = reflectors.reflectorB[first];

    for(int i = vrotors.size(); i > 0; i--)
    {
        input = preRotor(tr.enigmaCode[letter] + rotorConfig[i] - rotorConfig[i + 1]);
        first = findKey(input);
        letter = findKey(vrotors[i - 1], first);
    }

    input = preRotor(tr.enigmaCode[letter] + rotorConfig[0] - rotorConfig[1]);
    letter = findKey(input);

    return letter;
}

string Enigma::findKey(int value)
{
    auto it = tr.enigmaCode.begin();
    while(it != tr.enigmaCode.end())
    {
        if(it->second == value)
            return it->first;
        it++;
    }
    return "";
}

string Enigma::findKey(map<string, string> rotor, string value)
{
    auto it = rotor.begin();
    while(it != rotor.end())
    {
        if(it->second == value)
            return it->first;
        it++;
    }
    return "";
}

int Enigma::preRotor(int value)
{
    while (value >= 26)
            value -= 26;

    while (value < 0)
        value += 26;

    return value;
}

int Enigma::configRotor(int rotor)
{
    return rotorConfig[rotor + 1];
}
