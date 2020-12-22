#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QVector>
#include <QLabel>
#include <QPushButton>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QVector<QLabel*> labels;
    QVector<QPushButton*> buttons;
    QString clickButton = "";
    void lightLabel(QString buttonText, int r, int g, int b);
    void buttonPress(QString buttonText);
    void buttonRelease(QString buttonText);

private slots:
    void highLightLabel();
    void lowLightLabel();


};
#endif // MAINWINDOW_H
