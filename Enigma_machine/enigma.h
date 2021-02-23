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

    int configRotor(size_t idRotor);
    int countRotors();

    void rotateRotor(size_t idRotor, int value);
    void rotateRotorUp1(size_t idRotor);
    void rotateRotorDown1(size_t idRotor);

    bool isEnigmaEncode(char letter);

    void connectSwitch(char letterOne, char letterTwo);
    vector<char> availableLetter();
    map<char, char> currentSwitchPanel();
    void clearSwitchPanel();
    void reload();

    bool autoRotate = false;

private:
    vector<map<char, char>> vrotors = {Rotors::defaultRotor, Rotors::rotorI, Rotors::rotorII, Rotors::rotorIII};
    map<char, char> reflectors = Reflectors::reflectorB;

    void forwardEncode(char &letter);
    void reflection(char &letter);
    void backEncode(char &letter);
    int preRotor(int value);

    int* rotor(size_t idRotor);
    void checkRotor(size_t idRotor);

    char decodeLetter(int value);
    char encodeRotor(map<char, char> rotor, char value);

    vector<char> enigmaLetter;
    int startEnigmaCode = 65;
    int countEncodeLetters = Rotors::rotorI.size();

    vector<int> rotorConfig;

    map<char, char> switchPanel;

};
#endif // ENIGMA_H
