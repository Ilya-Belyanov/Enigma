#include "switchPanel.h"
#include "ui_switchPanel.h"

SwitchPanel::SwitchPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SwitchPanel)
{
    ui->setupUi(this);

    labels = {ui->lQ, ui->lW, ui->lE, ui->lR, ui->lT, ui->lY,
              ui->lU, ui->lI, ui->lO, ui->lP, ui->lA, ui->lS,
              ui->lD, ui->lF, ui->lG, ui->lH, ui->lJ, ui->lK,
              ui->lL, ui->lZ, ui->lX, ui->lC, ui->lV, ui->lB,
              ui->lN, ui->lM};

    box = {ui->cbQ, ui->cbW, ui->cbE, ui->cbR, ui->cbT, ui->cbY,
           ui->cbU, ui->cbI, ui->cbO, ui->cbP, ui->cbA, ui->cbS,
           ui->cbD, ui->cbF, ui->cbG, ui->cbH, ui->cbJ, ui->cbK,
           ui->cbL, ui->cbZ, ui->cbX, ui->cbC, ui->cbV, ui->cbB,
           ui->cbN, ui->cbM};
}

void SwitchPanel::setEnigma(Enigma &e)
{
    enigma = &e;
    vector<char> available = enigma->availableLetter();

    for(int i = 0; i < box.size(); i++)
    {
        for(unsigned j = 0; j < available.size(); j++)
            box[i]->addItem(QString(available[j]));
        box[i]->setCurrentIndex(i);
        box[i] -> setFocusPolicy(Qt::NoFocus);
        connect(box[i], SIGNAL(currentIndexChanged(int)), this, SLOT(switchItem(int)));
    }
}

void SwitchPanel::switchItem(int index)
{
    QComboBox* comboBox = qobject_cast<QComboBox*>(sender());
    int indexBox = 0;
    for(int i = 0; i < box.size(); i++)
        if(box[i] == comboBox)
        {
            indexBox = i;
            break;
        }
    enigma->connectSwitch(labels[indexBox] -> text().toStdString()[0],
                          comboBox->itemText(index).toStdString()[0]);

    reloadComboBox();

}

void SwitchPanel::reloadComboBox()
{
    map<char, char> switchPanel = enigma->currentSwitchPanel();
    vector<char> available = enigma->availableLetter();
    int id;
    for(unsigned i = 0; i < available.size(); i++)
    {
        id = box[i]->findText(QString(switchPanel[available[i]]));
        box[i]->setCurrentIndex(id);
    }


}
