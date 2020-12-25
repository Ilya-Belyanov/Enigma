#ifndef SWITHPANEL_H
#define SWITHPANEL_H
#include <map>

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QComboBox>
#include <QDebug>
#include <QPushButton>

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

private:
    Ui::SwitchPanel *ui;
    QVector<QLabel*> labels;
    QVector<QComboBox*> box;

    void reloadComboBox();

private slots:
    void switchItem(int index);

};
#endif // SWITHPANEL_H
