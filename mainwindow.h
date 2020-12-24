#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QVector>
#include <QLabel>
#include <QPushButton>
#include <QMap>
#include <QApplication>

#include "viewConfig.h"
#include "enigma.h"

using namespace COLOR;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QClipboard* pcb = QApplication::clipboard();
    Enigma enigma;
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);

    QVector<QLabel*> labels;
    QVector<QPushButton*> buttons;

private:
    Ui::MainWindow *ui;
    QString clickButton = "";
    QString clickLight = "";
    void lightLabel(QString buttonText, int r, int g, int b);
    void buttonPress(QString buttonText);
    void buttonRelease(QString buttonText);
    void spinUpdate();

    void textDown();

private slots:
    void highLightLabel();
    void lowLightLabel();
    void changeRI(int value);
    void changeRII(int value);
    void changeRIII(int value);
    void clearText();
    void copyText();

    void openFile();
    void encodeText(QString text);
    void saveFile();

    void reload();


};
#endif // MAINWINDOW_H
