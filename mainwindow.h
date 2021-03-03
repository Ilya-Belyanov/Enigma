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
#include <QShortcut>

#include <QDebug>

#include "switchPanel.h"
#include "viewConfig.h"
#include "qenigma.h"
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

    virtual void closeEvent(QCloseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);

    QEnigma enigma;

private:
    Ui::MainWindow *ui;
    QClipboard* pcb = QApplication::clipboard();
    SwitchPanel switchWidget;
    State state;
    QButtonGroup buttons;

    void connectChar();
    void connectSpins();
    void connectSupport();
    void connectShortCut();
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
    void pasteText();

    void reload();
    void showSwitchPanel();
};
#endif // MAINWINDOW_H
