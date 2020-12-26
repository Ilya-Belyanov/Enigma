#ifndef SWITHPANEL_H
#define SWITHPANEL_H
#include <map>

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QComboBox>
#include <QDebug>
#include <QFile>

#include "Enigma_machine/enigma.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SwitchPanel; }
QT_END_NAMESPACE

class SwitchPanel : public QWidget
{
    Q_OBJECT

public:
    SwitchPanel(QWidget *parent = nullptr);
    Enigma *enigma;
    void setEnigma(Enigma &e);
    void reloadComboBox();

private:
    Ui::SwitchPanel *ui;
    QVector<QLabel*> labels;
    QVector<QComboBox*> box;


private slots:
    void switchItem(int index);

};
#endif // SWITHPANEL_H
