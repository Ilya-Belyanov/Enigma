#include "qconfig.h"


namespace QRotors
{

   extern const QMap<QChar, QChar> defaultRotor = {{'A', 'A'}, {'B', 'B'}, {'C', 'C'}, {'D', 'D'}, {'E', 'E'},
                                                {'F', 'F'}, {'G', 'G'}, {'H', 'H'}, {'I', 'I'}, {'J', 'J'},
                                                {'K', 'K'}, {'L', 'L'}, {'M', 'M'}, {'N', 'N'}, {'O', 'O'},
                                                {'P', 'P'}, {'Q', 'Q'}, {'R', 'R'}, {'S', 'S'}, {'T', 'T'},
                                                {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'},
                                                {'Z', 'Z'}};

    extern const QMap<QChar, QChar> rotorI = {{'A', 'E'}, {'B', 'K'}, {'C', 'M'}, {'D', 'F'}, {'E', 'L'},
                                           {'F', 'G'}, {'G', 'D'}, {'H', 'Q'}, {'I', 'V'}, {'J', 'Z'},
                                           {'K', 'N'}, {'L', 'T'}, {'M', 'O'}, {'N', 'W'}, {'O', 'Y'},
                                           {'P', 'H'}, {'Q', 'X'}, {'R', 'U'}, {'S', 'S'}, {'T', 'P'},
                                           {'U', 'A'}, {'V', 'I'}, {'W', 'B'}, {'X', 'R'}, {'Y', 'C'},
                                           {'Z', 'J'}};

    extern const QMap<QChar, QChar> rotorII = {{'A', 'A'}, {'B', 'J'}, {'C', 'D'}, {'D', 'K'}, {'E', 'S'},
                                            {'F', 'I'}, {'G', 'R'}, {'H', 'U'}, {'I', 'X'}, {'J', 'B'},
                                            {'K', 'L'}, {'L', 'H'}, {'M', 'W'}, {'N', 'T'}, {'O', 'M'},
                                            {'P', 'C'}, {'Q', 'Q'}, {'R', 'G'}, {'S', 'Z'}, {'T', 'N'},
                                            {'U', 'P'}, {'V', 'Y'}, {'W', 'F'}, {'X', 'V'}, {'Y', 'O'},
                                            {'Z', 'E'}};

    extern const QMap<QChar, QChar> rotorIII = {{'A', 'B'}, {'B', 'D'}, {'C', 'F'}, {'D', 'H'}, {'E', 'J'},
                                             {'F', 'L'}, {'G', 'C'}, {'H', 'P'}, {'I', 'R'}, {'J', 'T'},
                                             {'K', 'X'}, {'L', 'V'}, {'M', 'Z'}, {'N', 'N'}, {'O', 'Y'},
                                             {'P', 'E'}, {'Q', 'I'}, {'R', 'W'}, {'S', 'G'}, {'T', 'A'},
                                             {'U', 'K'}, {'V', 'M'}, {'W', 'U'}, {'X', 'S'}, {'Y', 'Q'},
                                             {'Z', 'O'}};

};

namespace QReflectors
{
    extern const QMap<QChar, QChar> reflectorB = {{'A', 'Y'}, {'B', 'R'}, {'C', 'U'}, {'D', 'H'}, {'E', 'Q'},
                                               {'F', 'S'}, {'G', 'L'}, {'I', 'P'}, {'J', 'X'}, {'K', 'N'},
                                               {'M', 'O'}, {'T', 'Z'}, {'V', 'W'},
                                               {'Y', 'A'}, {'R', 'B'}, {'U', 'C'}, {'H', 'D'}, {'Q', 'E'},
                                               {'S', 'F'}, {'L', 'G'}, {'P', 'I'}, {'X', 'J'}, {'N', 'K'},
                                               {'O', 'M'}, {'Z', 'T'}, {'W', 'V'}};

};
