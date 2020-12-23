#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include <map>
#include "config.h"

class MainWindow;

using namespace std;


class Enigma
{
public:
    Enigma();
    MainWindow *window;
    string encode(string letter);
    int configRotor(int rotor);
    void rotateRotor(unsigned rotor, int value);
    void rotateRotorUp1(unsigned rotor);
    void rotateRotorDown1(unsigned rotor);
    vector<int> rotorConfig = {0, 17, 21, 2, 0};
private:
    int* rotor(unsigned idRotor);
    void checkRotor(unsigned idRotor);

    string findKey(int value);
    string findKey(map<string, string> rotor, string value);
    int preRotor(int value);
    Rotors rotors;
    vector<map<string, string>> vrotors = {rotors.rotorI, rotors.rotorII, rotors.rotorIII};
    Reflectors reflectors;
    Translate tr;

};
#endif // ENIGMA_H
