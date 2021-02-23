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
#include <QScrollBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QMimeData>
#include <QCloseEvent>
#include <QButtonGroup>

#include <QDebug>

#include "switchPanel.h"
#include "viewConfig.h"
#include "enigma.h"
#include "state.h"

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
    SwitchPanel switchWidget;

    virtual void closeEvent(QCloseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);

    QButtonGroup buttons;

private:
    Ui::MainWindow *ui;
    State state;

    void connectChar();
    void connectSpins();
    void connectSupport();
    void addActions();
    void loadStyle();

    void keyButtonPress(QString buttonText);
    void keyButtonRelease(QString buttonText);
    void textDown();
    void spinUpdate();
    void changeColorLabel(QString labelText, int r, int g, int b);
    void changeColorButton(QPushButton *bt, int r, int g, int b);

private slots:
    void charButtonPress();
    void charButtonRelease();
    void changeRI(int value);
    void changeRII(int value);
    void changeRIII(int value);


    void openFile();
    void encodeText(QString text);
    void saveFile();
    void clearText();
    void copyText();

    void reload();
    void showSwitchPanel();


};
#endif // MAINWINDOW_H
