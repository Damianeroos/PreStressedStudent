#include "dialogauthorsinfo.h"
#include "ui_dialogauthorsinfo.h"

DialogAuthorsInfo::DialogAuthorsInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAuthorsInfo)
{
    ui->setupUi(this);
}

DialogAuthorsInfo::~DialogAuthorsInfo()
{
    delete ui;
}
