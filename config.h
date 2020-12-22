#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <string>
using namespace std;


map<string, int> keyCode = {{"A", 65}, {"B", 66}, {"C", 67}, {"D", 68}, {"E", 69},
                            {"F", 70}, {"G", 71}, {"H", 72}, {"I", 73}, {"J", 74},
                            {"K", 75}, {"L", 76}, {"M", 77}, {"N", 78}, {"O", 79},
                            {"P", 80}, {"Q", 81}, {"R", 82}, {"S", 83}, {"T", 84},
                            {"U", 85}, {"V", 86}, {"W", 87}, {"X", 88}, {"Y", 89},
                            {"Z", 90}};



struct Rotors
{
    map<string, string> rotorI = {{"A", "E"}, {"B", "K"}, {"C", "M"}, {"D", "F"}, {"E", "L"},
                                 {"F", "G"}, {"G", "D"}, {"H", "Q"}, {"I", "V"}, {"J", "Z"},
                                 {"K", "N"}, {"L", "T"}, {"M", "O"}, {"N", "W"}, {"O", "Y"},
                                 {"P", "H"}, {"Q", "X"}, {"R", "U"}, {"S", "S"}, {"T", "P"},
                                 {"U", "A"}, {"V", "I"}, {"W", "B"}, {"X", "R"}, {"Y", "C"},
                                 {"Z", "J"}};

    map<string, string> rotorII = {{"A", "A"}, {"B", "J"}, {"C", "D"}, {"D", "K"}, {"E", "S"},
                                  {"F", "I"}, {"G", "R"}, {"H", "U"}, {"I", "X"}, {"J", "B"},
                                  {"K", "L"}, {"L", "H"}, {"M", "W"}, {"N", "T"}, {"O", "M"},
                                  {"P", "C"}, {"Q", "Q"}, {"R", "G"}, {"S", "Z"}, {"T", "N"},
                                  {"U", "P"}, {"V", "Y"}, {"W", "F"}, {"X", "V"}, {"Y", "O"},
                                  {"Z", "E"}};

    map<string, string> rotorIII = {{"A", "B"}, {"B", "D"}, {"C", "F"}, {"D", "H"}, {"E", "J"},
                                   {"F", "L"}, {"G", "C"}, {"H", "P"}, {"I", "R"}, {"J", "T"},
                                   {"K", "X"}, {"L", "V"}, {"M", "Z"}, {"N", "N"}, {"O", "Y"},
                                   {"P", "E"}, {"Q", "I"}, {"R", "W"}, {"S", "G"}, {"T", "A"},
                                   {"U", "K"}, {"V", "M"}, {"W", "U"}, {"X", "S"}, {"Y", "Q"},
                                   {"Z", "O"}};

};

struct Reflectors
{

};


#endif // CONFIG_H