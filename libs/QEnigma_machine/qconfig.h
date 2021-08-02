#ifndef QCONFIG_H
#define QCONFIG_H

#include <QMap>

namespace QRotors
{
    extern const QMap<QChar, QChar> defaultRotor;
    extern const QMap<QChar, QChar> rotorI;
    extern const QMap<QChar, QChar> rotorII;
    extern const QMap<QChar, QChar> rotorIII;

};

namespace QReflectors
{
    extern const QMap<QChar, QChar> reflectorB;
};


#endif // QCONFIG_H
