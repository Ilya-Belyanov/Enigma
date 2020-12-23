#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labels = {ui->lA, ui->lB, ui->lC, ui->lD, ui->lE, ui->lF, ui->lG, ui->lH,
             ui->lI, ui->lJ, ui->lK, ui->lL, ui->lM, ui->lN, ui->lO, ui->lP,
             ui->lQ, ui->lR, ui->lS, ui->lT, ui->lU, ui->lV, ui->lW, ui->lX,
             ui->lY, ui->lZ};
    buttons = {ui->bA, ui->bB, ui->bC, ui->bD, ui->bE, ui->bF, ui->bG, ui->bH,
             ui->bI, ui->bJ, ui->bK, ui->bL, ui->bM, ui->bN, ui->bO, ui->bP,
             ui->bQ, ui->bR, ui->bS, ui->bT, ui->bU, ui->bV, ui->bW, ui->bX,
             ui->bY, ui->bZ};

    QVectorIterator<QPushButton*> i(buttons);
    while (i.hasNext())
    {
        QPushButton* n = i.next();
        connect(n, SIGNAL(pressed()), this, SLOT(highLightLabel()));
        connect(n, SIGNAL(released()), this, SLOT(lowLightLabel()));
    }
    spinUpdate();
    ui -> sRI ->setFocusPolicy(Qt::NoFocus);
    ui -> sRII ->setFocusPolicy(Qt::NoFocus);
    ui -> sRIII ->setFocusPolicy(Qt::NoFocus);
    connect(ui -> sRI, SIGNAL(valueChanged(int)), this, SLOT(changeRI(int)));
    connect(ui -> sRII, SIGNAL(valueChanged(int)), this, SLOT(changeRII(int)));
    connect(ui -> sRIII, SIGNAL(valueChanged(int)), this, SLOT(changeRIII(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        {
            return;
        }
    if (clickButton == "")
        buttonPress(event->text().toUpper());
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        {
            return;
        }
    if(clickButton == event->text().toUpper())
        buttonRelease(event->text().toUpper());

}

void MainWindow::highLightLabel()
{
    if (clickButton != "")
        return;
    ui -> sRI -> setValue(ui -> sRI -> value() + 1);
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    clickLight = QString::fromStdString(enigma.encode(buttonSender->text().toStdString()));
    lightLabel(clickLight, R_LIGHT, G_LIGHT, B_LIGHT);
    buttonSender-> setStyleSheet(styleSheet().append(QString("background-color: rgb(%1,%2,%3)")
                                                     .arg(QString::number(R_LIGHT), QString::number(G_LIGHT), QString::number(B_LIGHT))));
    clickButton = buttonSender-> text();
}

void MainWindow::lowLightLabel()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    if(clickButton != buttonSender->text())
        return;
    lightLabel(clickLight, R_LOW_LABEL, G_LOW_LABEL, B_LOW_LABEL);
    buttonSender -> setStyleSheet(styleSheet().append(QString("background-color: rgb(%1,%2,%3)")
                                                      .arg(QString::number(R_LOW_BUTTON), QString::number(G_LOW_BUTTON), QString::number(B_LOW_BUTTON))));
    clickButton = "";
    clickLight = "";
}

void MainWindow::lightLabel(QString buttonText, int r, int g, int b)
{
    for(int i = 0; i < labels.size(); i++)
    {
        if(buttonText == labels[i] -> text())
        {
            labels[i] -> setStyleSheet(styleSheet().append(QString("background-color: rgb(%1,%2,%3)")
                                                           .arg(QString::number(r), QString::number(g), QString::number(b))));
        }
    }
}

void MainWindow::buttonPress(QString buttonText)
{
    for(int i = 0; i < buttons.size(); i++)
    {
        if(buttonText == buttons[i] -> text())
        {
            buttons[i] -> pressed();
            buttons[i] -> setStyleSheet(styleSheet().append(QString("background-color: rgb(%1,%2,%3)")
                                                            .arg(QString::number(R_LIGHT), QString::number(G_LIGHT), QString::number(B_LIGHT))));
        }
    }
}

void MainWindow::buttonRelease(QString buttonText)
{
    for(int i = 0; i < buttons.size(); i++)
    {
        if(buttonText == buttons[i] -> text())
        {
            buttons[i] -> released();
            buttons[i] -> setStyleSheet(styleSheet().append(QString("background-color: rgb(%1,%2,%3)")
                                                            .arg(QString::number(R_LOW_BUTTON), QString::number(G_LOW_BUTTON), QString::number(B_LOW_BUTTON))));
        }
    }
}

void MainWindow::spinUpdate()
{
    ui -> sRI -> setValue(enigma.configRotor(0));
    ui -> sRII -> setValue(enigma.configRotor(1));
    ui -> sRIII -> setValue(enigma.configRotor(2));
}


void MainWindow::changeRI(int value)
{
    enigma.rotateRotor(0, value);
    spinUpdate();
}

void MainWindow::changeRII(int value)
{
    enigma.rotateRotor(1, value);
    spinUpdate();
}

void MainWindow::changeRIII(int value)
{
    enigma.rotateRotor(2, value);
    spinUpdate();
}
