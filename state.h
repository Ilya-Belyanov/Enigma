#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <QObject>

class State : public QObject
{
    Q_OBJECT
    public:
        bool isButtonPress() {return clickButton != "";}
        bool isThisButtonPress(QString buttonText) {return clickButton == buttonText;}
        void pressButton(QString buttonText) {clickButton = buttonText;}
        void releaseButton() {clickButton = ""; clickLight = "";}

        QString clickLabel(){return clickLight;}
        void setClickLabel(QString label){clickLight = label;}

    private:
        QString clickButton = "";
        QString clickLight= "";

};
#endif // MAINLOGIC_H
