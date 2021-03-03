#ifndef SWITHPANEL_H
#define SWITHPANEL_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QComboBox>
#include <QFile>
#include <QtGui>
#include <QtCore>

#include "qenigma.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SwitchPanel; }
QT_END_NAMESPACE

class SwitchPanel : public QWidget
{
    Q_OBJECT

public:
    SwitchPanel(QWidget *parent = nullptr);
    QEnigma *enigma;
    void setEnigma(QEnigma &e);
    void reloadComboBox();

private:
    Ui::SwitchPanel *ui;
    QVector<QLabel*> labels;
    QVector<QComboBox*> box;

    void loadStyle();


private slots:
    void switchItem(int index);

};
#endif // SWITHPANEL_H
