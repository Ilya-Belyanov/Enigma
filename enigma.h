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
private:
    string findKey(int value);
    string findKey(map<string, string> rotor, string value);
    int preRotor(int value);
    Rotors rotors;
    vector<map<string, string>> vrotors = {rotors.rotorI, rotors.rotorII, rotors.rotorIII};
    Reflectors reflectors;
    Translate tr;
    vector<int> rotorConfig = {0, 17, 21, 2, 0};

};
#endif // ENIGMA_H
