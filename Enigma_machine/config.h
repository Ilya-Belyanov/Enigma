#ifndef CONFIG_H
#define CONFIG_H

#include <map>

using namespace std;

namespace Translate
{
    extern const map<char, int> keyCode;
    extern const map<char, int> enigmaCode;
};



namespace Rotors
{
    extern const map<char, char> defaultRotor;
    extern const map<char, char> rotorI;
    extern const map<char, char> rotorII;
    extern const map<char, char> rotorIII;

};

namespace Reflectors
{
    extern const map<char, char> reflectorB;
};


#endif // CONFIG_H
