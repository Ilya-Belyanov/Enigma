#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include <map>
#include "config.h"

using namespace std;

class Enigma
{
public:

    char encode(char letter);

    int configRotor(unsigned idRotor);
    int countRotors();

    void rotateRotor(unsigned idRotor, int value);
    void rotateRotorUp1(unsigned idRotor);
    void rotateRotorDown1(unsigned idRotor);

private:
    Rotors rotors;
    Reflectors reflectors;
    Translate tr;

    void forwardEncode(char &letter);
    void reflection(char &letter);
    void backEncode(char &letter);
    int preRotor(int value);

    int* rotor(unsigned idRotor);
    void checkRotor(unsigned idRotor);

    char decodeLetter(int value);
    char encodeRotor(map<char, char> rotor, char value);

    int countEncodeLetters = rotors.rotorI.size();
    vector<map<char, char>> vrotors = {rotors.rotorI, rotors.rotorII, rotors.rotorIII};
    vector<int> rotorConfig = {0, 17, 21, 2, 0};

};
#endif // ENIGMA_H
