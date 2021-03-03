#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectChar();
    connectSpins();
    connectSupport();
    addActions();

    ui -> txOutput ->setReadOnly(true);
    ui -> txOutput -> ensureCursorVisible();

    switchWidget.setEnigma(enigma);
    loadStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectChar()
{
    foreach(QPushButton *button, ui->groupBox->findChildren<QPushButton *>())
    {
        connect(button, SIGNAL(pressed()), this, SLOT(charButtonPress()));
        connect(button, SIGNAL(released()), this, SLOT(charButtonRelease()));
        button -> setObjectName("Enter");
        buttons.addButton(button);
    }
}

void MainWindow::connectSpins()
{
    ui -> sRI ->setFocusPolicy(Qt::NoFocus);
    ui -> sRII ->setFocusPolicy(Qt::NoFocus);
    ui -> sRIII ->setFocusPolicy(Qt::NoFocus);
    spinUpdate();

    connect(ui -> sRI, SIGNAL(valueChanged(int)), this, SLOT(changeRI(int)));
    connect(ui -> sRII, SIGNAL(valueChanged(int)), this, SLOT(changeRII(int)));
    connect(ui -> sRIII, SIGNAL(valueChanged(int)), this, SLOT(changeRIII(int)));
}

void MainWindow::connectSupport()
{
    ui -> bPaste->setObjectName("Support");
    ui -> bCopy->setObjectName("Support");
    ui -> bClear->setObjectName("Support");
    ui -> bReload->setObjectName("Support");

    connect(ui -> bPaste, SIGNAL(pressed()), this, SLOT(pasteText()));
    connect(ui -> bCopy, SIGNAL(pressed()), this, SLOT(copyText()));
    connect(ui -> bClear, SIGNAL(pressed()), this, SLOT(clearText()));
    connect(ui -> bReload,SIGNAL(pressed()),this,SLOT(reload()));
}

void MainWindow::addActions()
{
    connect(ui -> actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui -> actionOpen,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui -> actionCopy,SIGNAL(triggered()),this,SLOT(copyText()));
    connect(ui -> actionPaste,SIGNAL(triggered()),this,SLOT(pasteText()));
    connect(ui -> actionSave,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(ui -> actionReload,SIGNAL(triggered()),this,SLOT(reload()));
    connect(ui -> actionSwitch_panel,SIGNAL(triggered()),this,SLOT(showSwitchPanel()));
}

void MainWindow::loadStyle()
{
    this -> setAcceptDrops(true);
    QFile file(":/res/static/styles/style.css");
    file.open(QIODevice::ReadOnly);
    this -> setStyleSheet(file.readAll());
    file.close();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
            return;

    if (!state.isButtonPress())
        keyButtonPress(event->text().toUpper());
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
            return;

    if (event -> key() == Qt::Key_Tab)
        copyText();

    else if(state.isThisButtonPress(event->text().toUpper()))
        keyButtonRelease(event->text().toUpper());
}

void MainWindow::charButtonPress()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    if (state.isButtonPress())
        return;
    ui -> sRI -> setValue(ui -> sRI -> value() + 1);

    QChar letter = buttonSender->text()[0];
    state.pressButton(buttonSender-> text());
    state.setClickLabel(enigma.encode(letter));

    changeColorLabel(state.clickLabel(), R_LIGHT, G_LIGHT, B_LIGHT);
    changeColorButton(buttonSender, R_LIGHT, G_LIGHT, B_LIGHT);

    ui -> txOutput -> setText(ui -> txOutput -> toPlainText() + state.clickLabel());
    textDown();
}

void MainWindow::charButtonRelease()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    if(!state.isButtonPress())
        return;

    changeColorLabel(state.clickLabel(), R_LOW_LABEL, G_LOW_LABEL, B_LOW_LABEL);
    changeColorButton(buttonSender, R_LOW_BUTTON, G_LOW_BUTTON, B_LOW_BUTTON);

    state.releaseButton();
}

void MainWindow::textDown()
{
    QScrollBar *sb =  ui -> txOutput->verticalScrollBar();
    sb -> setValue(sb -> maximum());
}

void MainWindow::keyButtonPress(QString buttonText)
{
    foreach(QAbstractButton *button, buttons.buttons())
        if(buttonText == button -> text())
             button -> pressed();
}

void MainWindow::keyButtonRelease(QString buttonText)
{
    foreach(QAbstractButton *button, buttons.buttons())
        if(buttonText == button -> text())
             button -> released();
}


void MainWindow::changeColorLabel(QString labelText, int r, int g, int b)
{
    foreach(QLabel *label, findChildren<QLabel *>())
        if(labelText == label -> text())
            label -> setStyleSheet(QString("background-color: rgb(%1,%2,%3)")
                                    .arg(QString::number(r), QString::number(g), QString::number(b)));
}

void MainWindow::changeColorButton(QPushButton *bt, int r, int g, int b)
{
    bt -> setStyleSheet(QString("background-color: rgb(%1,%2,%3)")
                        .arg(QString::number(r), QString::number(g), QString::number(b)));
}
void MainWindow::clearText()
{
    ui -> txOutput -> clear();
}

void MainWindow::copyText()
{
    pcb->setText(ui -> txOutput -> toPlainText(), QClipboard::Clipboard);
}

void MainWindow::pasteText()
{
    encodeText(pcb->text());
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open Text"), "",
             tr("Enigma (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else
    {
         QFile file(fileName);
         if (!file.open(QIODevice::ReadOnly))
         {
             QMessageBox::information(this, tr("Unable to open file"),
                 file.errorString());
             return;
         }
         encodeText(QString::fromUtf8(file.readAll()));
    }
}

void MainWindow::encodeText(QString text)
{
    text = text.toUpper();
    QString encodeText = enigma.encode(text);
    ui -> txOutput -> setText(encodeText);
    spinUpdate();
}

void MainWindow::saveFile()
 {
     QString fileName = QFileDialog::getSaveFileName(this,
         tr("Save Encode Text"), "",
         tr("Enigma (*.txt);;All Files (*)"));

     if (fileName.isEmpty())
              return;
     else
     {
         QFile file(fileName);
         if (!file.open(QIODevice::WriteOnly))
         {
             QMessageBox::information(this, tr("Unable to open file"),
                 file.errorString());
             return;
         }
         QByteArray data = ui -> txOutput -> toPlainText().toUtf8();
         file.write(data);
         file.close();
     }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if ( mimeData->hasUrls())
    {
        QString fileName = mimeData -> text().remove(0,8);
        QFile file(fileName);
        if (QFileInfo(file).completeSuffix() != "txt")
            return;
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
        encodeText(QString::fromUtf8(file.readAll()));
        event->acceptProposedAction();
    }
    else
    {
        event->ignore();
    }
}

void  MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if ( mimeData->hasUrls() )
        event->acceptProposedAction();
    else
        event->ignore();
}

void  MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if ( mimeData->hasUrls() )
        event->acceptProposedAction();
    else
        event->ignore();
}

void  MainWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
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

void MainWindow::reload()
{
    enigma.reload();

    clearText();
    spinUpdate();
    switchWidget.reloadComboBox();
}

void MainWindow::showSwitchPanel()
{
    switchWidget.show();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    switchWidget.close();
}
