#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include <map>

#include "config.h"

using namespace std;

class Enigma
{
public:
    Enigma();

    char encode(char letter);
    string encode(string text);

    int configRotor(unsigned idRotor);
    int countRotors();

    void rotateRotor(unsigned idRotor, int value);
    void rotateRotorUp1(unsigned idRotor);
    void rotateRotorDown1(unsigned idRotor);

    bool isEnigmaEncode(char letter);

    void connectSwitch(char letterOne, char letterTwo);
    vector<char> availableLetter();
    map<char, char> currentSwitchPanel();
    void clearSwitchPanel();

    bool autoRotate = false;

private:
    vector<map<char, char>> vrotors = {Rotors::defaultRotor, Rotors::rotorI, Rotors::rotorII, Rotors::rotorIII};
    map<char, char> reflectors = Reflectors::reflectorB;

    void forwardEncode(char &letter);
    void reflection(char &letter);
    void backEncode(char &letter);
    int preRotor(int value);

    int* rotor(unsigned idRotor);
    void checkRotor(unsigned idRotor);

    char decodeLetter(int value);
    char encodeRotor(map<char, char> rotor, char value);

    vector<char> enigmaLetter;
    int countEncodeLetters = Rotors::rotorI.size();

    vector<int> rotorConfig;

    map<char, char> switchPanel;

};
#endif // ENIGMA_H
