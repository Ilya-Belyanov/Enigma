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
    string encode(string text);

    int configRotor(unsigned idRotor);
    int countRotors();
    bool isEnigmaEncode(char letter);
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
    vector<char> enigmaLetter = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                                 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                                 'Q', 'X', 'C', 'V', 'B', 'N', 'M'};
    vector<map<char, char>> vrotors = {rotors.defaultRotor, rotors.rotorI, rotors.rotorII, rotors.rotorIII};
    vector<int> rotorConfig = {0, 16, 21, 2, 0};

};
#endif // ENIGMA_H
