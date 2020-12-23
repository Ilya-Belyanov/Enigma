#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <string>
#include <vector>

using namespace std;

struct Translate
{
    map<char, int> keyCode = {{'A', 65}, {'B', 66}, {'C', 67}, {'D', 68}, {'E', 69},
                              {'F', 70}, {'G', 71}, {'H', 72}, {'I', 73}, {'J', 74},
                              {'K', 75}, {'L', 76}, {'M', 77}, {'N', 78}, {'O', 79},
                              {'P', 80}, {'Q', 81}, {'R', 82}, {'S', 83}, {'T', 84},
                              {'U', 85}, {'V', 86}, {'W', 87}, {'X', 88}, {'Y', 89},
                              {'Z', 90}};

    map<char, int> enigmaCode = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4},
                                 {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9},
                                 {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14},
                                 {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},
                                 {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24},
                                 {'Z', 25}};
};



struct Rotors
{
    map<char, char> rotorI = {{'A', 'E'}, {'B', 'K'}, {'C', 'M'}, {'D', 'F'}, {'E', 'L'},
                              {'F', 'G'}, {'G', 'D'}, {'H', 'Q'}, {'I', 'V'}, {'J', 'Z'},
                              {'K', 'N'}, {'L', 'T'}, {'M', 'O'}, {'N', 'W'}, {'O', 'Y'},
                              {'P', 'H'}, {'Q', 'X'}, {'R', 'U'}, {'S', 'S'}, {'T', 'P'},
                              {'U', 'A'}, {'V', 'I'}, {'W', 'B'}, {'X', 'R'}, {'Y', 'C'},
                              {'Z', 'J'}};

    map<char, char> rotorII = {{'A', 'A'}, {'B', 'J'}, {'C', 'D'}, {'D', 'K'}, {'E', 'S'},
                               {'F', 'I'}, {'G', 'R'}, {'H', 'U'}, {'I', 'X'}, {'J', 'B'},
                               {'K', 'L'}, {'L', 'H'}, {'M', 'W'}, {'N', 'T'}, {'O', 'M'},
                               {'P', 'C'}, {'Q', 'Q'}, {'R', 'G'}, {'S', 'Z'}, {'T', 'N'},
                               {'U', 'P'}, {'V', 'Y'}, {'W', 'F'}, {'X', 'V'}, {'Y', 'O'},
                               {'Z', 'E'}};

    map<char, char> rotorIII = {{'A', 'B'}, {'B', 'D'}, {'C', 'F'}, {'D', 'H'}, {'E', 'J'},
                                   {'F', 'L'}, {'G', 'C'}, {'H', 'P'}, {'I', 'R'}, {'J', 'T'},
                                   {'K', 'X'}, {'L', 'V'}, {'M', 'Z'}, {'N', 'N'}, {'O', 'Y'},
                                   {'P', 'E'}, {'Q', 'I'}, {'R', 'W'}, {'S', 'G'}, {'T', 'A'},
                                   {'U', 'K'}, {'V', 'M'}, {'W', 'U'}, {'X', 'S'}, {'Y', 'Q'},
                                   {'Z', 'O'}};

};

struct Reflectors
{
    map<char, char> reflectorB = {{'A', 'Y'}, {'B', 'R'}, {'C', 'U'}, {'D', 'H'}, {'E', 'Q'},
                                      {'F', 'S'}, {'G', 'L'}, {'I', 'P'}, {'J', 'X'}, {'K', 'N'},
                                      {'M', 'O'}, {'T', 'Z'}, {'V', 'W'},
                                      {'Y', 'A'}, {'R', 'B'}, {'U', 'C'}, {'H', 'D'}, {'Q', 'E'},
                                      {'S', 'F'}, {'L', 'G'}, {'P', 'I'}, {'X', 'J'}, {'N', 'K'},
                                      {'O', 'M'}, {'Z', 'T'}, {'W', 'V'}};

};


#endif // CONFIG_H
