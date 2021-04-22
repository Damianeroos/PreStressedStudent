#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDoubleValidator>
#include <QString>
#include "mathformulas.h"
#include <math.h>
#include <QLocale>
#include "arrays.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Kalkulator dźwigara");
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    QPixmap pix(":/resources/img/rys.1.PNG");
    ui->labelPic->setPixmap(pix.scaled(ui->labelPic->width(),ui->labelPic->height(),Qt::KeepAspectRatio));
    ui->labelPic->setPixmap(pix.scaled(ui->labelPic->width(),ui->labelPic->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    QDoubleValidator* doubleValidator4 = new QDoubleValidator(0, std::numeric_limits<double>::max(), 4, this);
    ui->lineEditB1->setValidator(doubleValidator4);
    ui->lineEditB2->setValidator(doubleValidator4);
    ui->lineEditB3->setValidator(doubleValidator4);
    ui->lineEditH1->setValidator(doubleValidator4);
    ui->lineEditH2->setValidator(doubleValidator4);
    ui->lineEditH3->setValidator(doubleValidator4);
    ui->lineEditH4->setValidator(doubleValidator4);
    ui->lineEditH5->setValidator(doubleValidator4);
    ui->lineEditFck->setValidator(doubleValidator4);
    ui->lineEditGammaFcd->setValidator(doubleValidator4);
    ui->lineEditFpk->setValidator(doubleValidator4);
    ui->lineEditGammaFpd->setValidator(doubleValidator4);
    ui->lineEditMed->setValidator(doubleValidator4);
    ui->lineEditApc0->setValidator(doubleValidator4);
    ui->lineEditEp->setValidator(doubleValidator4);
    ui->lineEditEcm->setValidator(doubleValidator4);
    ui->lineEditK->setValidator(doubleValidator4);
    ui->lineEditB1S->setValidator(doubleValidator4);
    ui->lineEditB2S->setValidator(doubleValidator4);
    ui->lineEditB3S->setValidator(doubleValidator4);
    ui->lineEditH1S->setValidator(doubleValidator4);
    ui->lineEditH2S->setValidator(doubleValidator4);
    ui->lineEditH3S->setValidator(doubleValidator4);

    QDoubleValidator* doubleValidator1 = new QDoubleValidator(0,std::numeric_limits<double>::max(),1,this);
    ui->lineEditPhiS->setValidator(doubleValidator1);
    ui->lineEditCDurY->setValidator(doubleValidator1);
    ui->lineEditCDurSt->setValidator(doubleValidator1);
    ui->lineEditCDurAdd->setValidator(doubleValidator1);
    ui->lineEditCDev->setValidator(doubleValidator1);
    ui->lineEditPhiSSS->setValidator(doubleValidator1);
    ui->lineEditCDurYSS->setValidator(doubleValidator1);
    ui->lineEditCDurStSS->setValidator(doubleValidator1);
    ui->lineEditCDurAddSS->setValidator(doubleValidator1);
    ui->lineEditCDevSS->setValidator(doubleValidator1);
    ui->lineEditPhiStr->setValidator(doubleValidator1);
    ui->lineEditA->setValidator(doubleValidator1);

    ui->lineEditAc->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditBeta->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSc->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditKappa->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditIc->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditRho->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCmin->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNZbr->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPhiSOO->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNZbrOO->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNSprOO->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNZbrSS->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCminSS->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCZrbFinal->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCSprFinal->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditFcd->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditFpd->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditZ->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditNpov->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditAcc->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditAlphaE->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditAcs->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditScs->setStyleSheet(lineEditBackgroundColorGrey);

    ui->comboBoxConstruction->addItem("S1");
    ui->comboBoxConstruction->addItem("S2");
    ui->comboBoxConstruction->addItem("S3");
    ui->comboBoxConstruction->addItem("S4");
    ui->comboBoxConstruction->addItem("S5");
    ui->comboBoxConstruction->addItem("S6");
    ui->comboBoxExposition->addItem("X0");
    ui->comboBoxExposition->addItem("XC1");
    ui->comboBoxExposition->addItem("XC2/XC3");
    ui->comboBoxExposition->addItem("XC4");
    ui->comboBoxExposition->addItem("XD1/XS1");
    ui->comboBoxExposition->addItem("XD2/XS2");
    ui->comboBoxExposition->addItem("XD3/XS3");
    ui->comboBoxSteelType->addItem("pręt");
    ui->comboBoxSteelType->addItem("drut");
    ui->comboBoxSteelType->addItem("splot");

    // table lower
    ui->pushButtonAddRowLower->setStyleSheet("font: bold 14px;"
                                             "color: green");
    ui->pushButtonSubRowLower->setStyleSheet("font: bold 14px;"
                                             "color: red");
    ui->tableWidgetLower->setColumnCount(3);
    ui->tableWidgetLower->setShowGrid(true);
    QStringList lowerTableLabes = {"rząd", "l. splotów", "h [m]"};
    ui->tableWidgetLower->setHorizontalHeaderLabels(lowerTableLabes);
    ui->tableWidgetLower->horizontalHeader()->setStyleSheet("::section {background-color: lightblue;}");
    ui->tableWidgetLower->verticalHeader()->setVisible(false);
    ui->tableWidgetLower->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //table upper
    ui->pushButtonAddRowUpper->setStyleSheet("font: bold 14px;"
                                             "color: green");
    ui->pushButtonSubRowUpper->setStyleSheet("font: bold 14px;"
                                             "color: red");
    ui->tableWidgetUpper->setColumnCount(3);
    ui->tableWidgetUpper->setShowGrid(true);
    QStringList upperTableLabes = {"rząd", "l. splotów", "h [m]"};
    ui->tableWidgetUpper->setHorizontalHeaderLabels(upperTableLabes);
    ui->tableWidgetUpper->horizontalHeader()->setStyleSheet("::section {background-color: lightblue;}");
    ui->tableWidgetUpper->verticalHeader()->setVisible(false);
    ui->tableWidgetUpper->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    initParameters();

    QObject::connect(ui->startComputationButton, SIGNAL(clicked()),
                     this, SLOT(startComputations()));

    QObject::connect(ui->comboBoxConstruction, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(computeC()));
    QObject::connect(ui->comboBoxExposition, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(computeC()));
    QObject::connect(ui->lineEditPhiS, SIGNAL(textEdited(QString)),
                     this, SLOT(computeC()));
    QObject::connect(ui->lineEditCDurY, SIGNAL(textEdited(QString)),
                     this, SLOT(computeC()));
    QObject::connect(ui->lineEditCDurSt, SIGNAL(textEdited(QString)),
                     this, SLOT(computeC()));
    QObject::connect(ui->lineEditCDurAdd, SIGNAL(textEdited(QString)),
                     this, SLOT(computeC()));
    QObject::connect(ui->lineEditCDev, SIGNAL(textEdited(QString)),
                     this, SLOT(computeC()));

    QObject::connect(ui->comboBoxConstruction, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(computeCSS()));
    QObject::connect(ui->comboBoxExposition, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(computeCSS()));
    QObject::connect(ui->lineEditPhiSSS, SIGNAL(textEdited(QString)),
                     this, SLOT(computeCSS()));
    QObject::connect(ui->lineEditCDurYSS, SIGNAL(textEdited(QString)),
                     this, SLOT(computeCSS()));
    QObject::connect(ui->lineEditCDurStSS, SIGNAL(textEdited(QString)),
                     this, SLOT(computeCSS()));
    QObject::connect(ui->lineEditCDurAddSS, SIGNAL(textEdited(QString)),
                     this, SLOT(computeCSS()));
    QObject::connect(ui->lineEditCDevSS, SIGNAL(textEdited(QString)),
                     this, SLOT(computeCSS()));

    QObject::connect(ui->lineEditPhiS, SIGNAL(textEdited(QString)),
                     this, SLOT(computeCForFireResitance()));
    QObject::connect(ui->lineEditPhiS, SIGNAL(textChanged(QString)),
                     ui->lineEditPhiSOO, SLOT(setText(QString)));
    QObject::connect(ui->lineEditA, SIGNAL(textEdited(QString)),
                     this, SLOT(computeCForFireResitance()));
    QObject::connect(ui->lineEditPhiStr, SIGNAL(textEdited(QString)),
                     this, SLOT(computeCForFireResitance()));
    QObject::connect(ui->comboBoxSteelType, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(computeCForFireResitance()));

    QObject::connect(ui->pushButtonAddRowLower, SIGNAL(clicked()),
                     this, SLOT(addRowLowerTable()));
    QObject::connect(ui->pushButtonSubRowLower, SIGNAL(clicked()),
                     this, SLOT(removeRowLowerTable()));
    QObject::connect(ui->tableWidgetLower, SIGNAL(cellChanged(int,int)),
                     this, SLOT(validateCellDataLowerTable(int,int)));
    QObject::connect(ui->pushButtonAddRowUpper, SIGNAL(clicked()),
                     this, SLOT(addRowUpperTable()));
    QObject::connect(ui->pushButtonSubRowUpper, SIGNAL(clicked()),
                     this, SLOT(removeRowUpperTable()));
    QObject::connect(ui->tableWidgetUpper, SIGNAL(cellChanged(int,int)),
                     this, SLOT(validateCellDataUpperTable(int,int)));
}

void MainWindow::addRowTable( QTableWidget* table){
    table->insertRow(table->rowCount());
    QTableWidgetItem* itemA = new QTableWidgetItem("a"+QString::number(table->rowCount()));
    table->setItem(table->rowCount()-1, 0, itemA);
    itemA->setTextAlignment(Qt::AlignHCenter);
    itemA->setFlags(itemA->flags() ^ Qt::ItemIsEditable);

    QTableWidgetItem* itemS = new QTableWidgetItem("1");
    table->setItem(table->rowCount()-1, 1, itemS);
    itemS->setTextAlignment(Qt::AlignHCenter);

    QTableWidgetItem* itemH = new QTableWidgetItem("0,02");
    table->setItem(table->rowCount()-1, 2, itemH);
    itemH->setTextAlignment(Qt::AlignHCenter);
}

void MainWindow::addRowLowerTable(){
    QTableWidget* table = ui->tableWidgetLower;

    table->insertRow(table->rowCount());
    QTableWidgetItem* itemA = new QTableWidgetItem("a"+QString::number(table->rowCount()));
    table->setItem(table->rowCount()-1, 0, itemA);
    itemA->setTextAlignment(Qt::AlignHCenter);
    itemA->setFlags(itemA->flags() ^ Qt::ItemIsEditable);

    QTableWidgetItem* itemS = new QTableWidgetItem("1");
    table->setItem(table->rowCount()-1, 1, itemS);
    itemS->setTextAlignment(Qt::AlignHCenter);

    QTableWidgetItem* itemH = new QTableWidgetItem("0,02");
    table->setItem(table->rowCount()-1, 2, itemH);
    itemH->setTextAlignment(Qt::AlignHCenter);
}

void MainWindow::addRowUpperTable(){
    QTableWidget* table = ui->tableWidgetUpper;

    table->insertRow(table->rowCount());
    QTableWidgetItem* itemA = new QTableWidgetItem("a"+QString::number(table->rowCount()));
    table->setItem(table->rowCount()-1, 0, itemA);
    itemA->setTextAlignment(Qt::AlignHCenter);
    itemA->setFlags(itemA->flags() ^ Qt::ItemIsEditable);

    QTableWidgetItem* itemS = new QTableWidgetItem("1");
    table->setItem(table->rowCount()-1, 1, itemS);
    itemS->setTextAlignment(Qt::AlignHCenter);

    QTableWidgetItem* itemH = new QTableWidgetItem("0,02");
    table->setItem(table->rowCount()-1, 2, itemH);
    itemH->setTextAlignment(Qt::AlignHCenter);
}

void MainWindow::addRowTable(QTableWidget *table, int aCount, double hValue){
    QLocale locale(QLocale::Polish);
    table->insertRow(table->rowCount());
    QTableWidgetItem* itemA = new QTableWidgetItem("a"+QString::number(table->rowCount()));
    table->setItem(table->rowCount()-1, 0, itemA);
    itemA->setTextAlignment(Qt::AlignHCenter);
    itemA->setFlags(itemA->flags() ^ Qt::ItemIsEditable);

    QTableWidgetItem* itemS = new QTableWidgetItem(locale.toString(aCount));
    table->setItem(table->rowCount()-1, 1, itemS);
    itemS->setTextAlignment(Qt::AlignHCenter);

    QTableWidgetItem* itemH = new QTableWidgetItem(locale.toString(hValue));
    table->setItem(table->rowCount()-1, 2, itemH);
    itemH->setTextAlignment(Qt::AlignHCenter);
}

void MainWindow::removeRowTable(QTableWidget *table){
    if(!table->rowCount()){
        return;
    }
    else{
       table->removeRow(table->rowCount()-1);
    }
}

void MainWindow::removeRowLowerTable(){
    QTableWidget* table = ui->tableWidgetLower;

    if(!table->rowCount()){
        return;
    }
    else{
       table->removeRow(table->rowCount()-1);
    }
}

void MainWindow::removeRowUpperTable(){
    QTableWidget* table = ui->tableWidgetUpper;

    if(!table->rowCount()){
        return;
    }
    else{
       table->removeRow(table->rowCount()-1);
    }
}

QString MainWindow::getStringFromTable(QTableWidget *table, int row, int column){
    return table->item(row, column)->text();
}

void MainWindow::setCellTableValue(QTableWidget *table, int row, int column, QString text){
    table->item(row, column)->setText(text);
}

void MainWindow::validateCellDataLowerTable(int row, int column){
    if(!column){ // cells in column 0 are not editable
        return;
    }
    QTableWidget* table = ui->tableWidgetLower;
    QString cellValue = getStringFromTable(ui->tableWidgetLower, row, column);
    QLocale locale(QLocale::Polish);

    double number = locale.toDouble(cellValue);

    if(isinf(number) || isnan(number) || (number < 0)){ // number must be positive
        setCellTableValue(table, row, column, "0");
    }
    else{
       if(column == 1){
           // value in column 1 are  integers
            setCellTableValue(table, row, column, locale.toString(ceil(number)));
       }
       if(column == 2){
           // value in column 2 are doubles
           setCellTableValue(table, row, column, locale.toString(number));
       }
    }

}

bool MainWindow::checkThatTypedArgumentsAreValid(){
    if(ui->lineEditB1->text().isEmpty() ||
            ui->lineEditB2->text().isEmpty() ||
            ui->lineEditB3->text().isEmpty() ||
            ui->lineEditH1->text().isEmpty() ||
            ui->lineEditH2->text().isEmpty() ||
            ui->lineEditH3->text().isEmpty() ||
            ui->lineEditH4->text().isEmpty() ||
            ui->lineEditH5->text().isEmpty() ||
            ui->lineEditB1S->text().isEmpty() ||
            ui->lineEditB2S->text().isEmpty() ||
            ui->lineEditB3S->text().isEmpty() ||
            ui->lineEditH1S->text().isEmpty() ||
            ui->lineEditH2S->text().isEmpty() ||
            ui->lineEditH3S->text().isEmpty()){
        return false;
    }
    else{
        return true;
    }
}

void MainWindow::startComputations(){
    QLocale locale(QLocale::Polish);
    if(!checkThatTypedArgumentsAreValid()){
        msg.setText("Please fill all parameters");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
        return;
    }
    else{
        clearResults();
         //solves problem with separator ( , -> .)

        mathFormulas data(locale.toDouble(ui->lineEditB1->text()),
                          locale.toDouble(ui->lineEditB2->text()),
                          locale.toDouble(ui->lineEditB3->text()),
                          locale.toDouble(ui->lineEditH1->text()),
                          locale.toDouble(ui->lineEditH2->text()),
                          locale.toDouble(ui->lineEditH3->text()),
                          locale.toDouble(ui->lineEditH4->text()),
                          locale.toDouble(ui->lineEditH5->text()),
                          locale.toDouble(ui->lineEditFck->text()),
                          locale.toDouble(ui->lineEditGammaFcd->text()),
                          locale.toDouble(ui->lineEditFpk->text()),
                          locale.toDouble(ui->lineEditGammaFpd->text()),
                          ui->spinBoxHp->value(),
                          locale.toDouble(ui->lineEditMed->text()),
                          locale.toDouble(ui->lineEditApc0->text()),
                          ui->spinBoxNpovg->value(),
                          locale.toDouble(ui->lineEditEp->text()),
                          locale.toDouble(ui->lineEditEcm->text()),
                          locale.toDouble(ui->lineEditK->text()),
                          locale.toDouble(ui->lineEditB1S->text()),
                          locale.toDouble(ui->lineEditB2S->text()),
                          locale.toDouble(ui->lineEditB3S->text()),
                          locale.toDouble(ui->lineEditH1S->text()),
                          locale.toDouble(ui->lineEditH2S->text()),
                          locale.toDouble(ui->lineEditH3S->text()));

        double areaAc = data.calculateAreaAc();
        ui->lineEditAc->setText(locale.toString(areaAc));
        if(!checkThatResultsAreNumbers(areaAc)){
            return;
        }

        if(areaAc <= 0){
            msg.setText("Pole powierzchni nie może być równe lub mniejsze niż 0\n"
                        "Zmień parametry");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
            return;
        }

        double paramBeta = data.calculateBeta();
        ui->lineEditBeta->setText(locale.toString(paramBeta));
        if(!checkThatResultsAreNumbers(paramBeta)){
            return;
        }

        if(paramBeta < 0.18){
            msg.setText("<p>Współczynnik &beta; powinien spełniać założenie 0,18 &lt; &beta; &lt; 0,35\n</p>"
                        "Przekrój jest zbyt smukły");
            msg.setIcon(QMessageBox::Warning);
            msg.exec();
        }
        else if(paramBeta > 0.35){
            msg.setText("<p>Współczynnik &beta; powinien spełniać założenie 0,18 &lt; &beta; &lt; 0,35\n</p>"
                        "Przekrój nie jest optymalnie zaprojektowany");
            msg.setIcon(QMessageBox::Warning);
            msg.exec();
        }

        double paramSc = data.calculateCenterOfGravity();
        ui->lineEditSc->setText(locale.toString(paramSc));
        if(!checkThatResultsAreNumbers(paramSc)){
            return;
        }

        double paramKappa = data.calculateKappa();
        ui->lineEditKappa->setText(locale.toString(paramKappa));
        if(!checkThatResultsAreNumbers(paramKappa)){
            return;
        }

        if(paramKappa < 0.35 || paramKappa > 0.65){
            msg.setText("<p>Współczynnik &kappa; powinien spełniać założenie 0,35 &lt; &kappa; &lt; 0,65\n</p>\n"
                        "Przekrój nie spełnia warunku granicznego wskaźnika asymetrii");
            msg.setIcon(QMessageBox::Warning);
            msg.exec();
        }

        double paramIc = data.calculateSecondMomentOfArea();
        ui->lineEditIc->setText(locale.toString(paramIc));
        if(!checkThatResultsAreNumbers(paramIc)){
            return;
        }

        double paramRho = data.calculatePerformanceLimitIndicator();
        ui->lineEditRho->setText(locale.toString(paramRho));
        if(!checkThatResultsAreNumbers(paramRho)){
            return;
        }

        double paramFcd = data.calculateFcd();
        ui->lineEditFcd->setText(locale.toString(paramFcd));
        if(!checkThatResultsAreNumbers(paramFcd)){
            return;
        }

        double paramFpd = data.calculateFpd();
        ui->lineEditFpd->setText(locale.toString(paramFpd));
        if(!checkThatResultsAreNumbers(paramFpd)){
            return;
        }

        double paramZ = data.calculateZ();
        ui->lineEditZ->setText(locale.toString(paramZ));
        if(!checkThatResultsAreNumbers(paramZ)){
            return;
        }

        double paramNpov = data.calculateNpov();
        ui->lineEditNpov->setText(locale.toString(paramNpov));
        if(!checkThatResultsAreNumbers(paramNpov)){
            return;
        }

        double paramAcc = data.calculateAcc();
        ui->lineEditAcc->setText(locale.toString(paramAcc));
        if(!checkThatResultsAreNumbers(paramAcc)){
            return;
        }
        if(paramAcc > data.getA1()){
            msg.setText("<p>Warunek A<sub>cc</sub> &lt; A<sub>1</sub> nie został spełniony.</p>\n"
                        "<p>A<sub>cc</sub> = " + QString::number(paramAcc)+ " m<sup>2</sup></p>"
                        "<p>A<sub>1</sub> = " + QString::number(data.getA1())+ " m<sup>2</sup></p>");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }

        double paramAlphaE = data.calculateAlphaE();
        ui->lineEditAlphaE->setText(locale.toString(paramAlphaE));
        if(!checkThatResultsAreNumbers(paramAlphaE)){
            return;
        }

        double paramAcs = data.calculateAcs();
        ui->lineEditAcs->setText(locale.toString(paramAcs));
        if(!checkThatResultsAreNumbers(paramAcs)){
            return;
        }

        data.setApLower(performFormulaFromLowerTable());
        data.setApUpper(data.getH());
        double paramScs = data.calculateScs();
        ui->lineEditScs->setText(locale.toString(paramScs));
        if(!checkThatResultsAreNumbers(paramScs)){
            return;
        }

        setFinalCValue();

    }
}
void MainWindow::initParameters(){
    ui->lineEditB1->setText(QString("0,5"));
    ui->lineEditB2->setText(QString("0,5"));
    ui->lineEditB3->setText(QString("0,125"));
    ui->lineEditH1->setText(QString("0,15"));
    ui->lineEditH2->setText(QString("0,095"));
    ui->lineEditH3->setText(QString("1,065"));
    ui->lineEditH4->setText(QString("0,19"));
    ui->lineEditH5->setText(QString("0,15"));

    ui->lineEditPhiS->setText(QString("12"));
    ui->lineEditCDurY->setText(QString("0"));
    ui->lineEditCDurSt->setText(QString("0"));
    ui->lineEditCDurAdd->setText(QString("0"));
    ui->lineEditCDev->setText(QString("10"));

    ui->lineEditPhiSSS->setText(QString("12,5"));
    ui->lineEditCDurYSS->setText(QString("0"));
    ui->lineEditCDurStSS->setText(QString("0"));
    ui->lineEditCDurAddSS->setText(QString("0"));
    ui->lineEditCDevSS->setText(QString("10"));

    ui->lineEditPhiSOO->setText(ui->lineEditPhiS->text());
    ui->lineEditA->setText(QString("35"));
    ui->lineEditPhiStr->setText(QString("10"));

    ui->lineEditFck->setText(QString("45"));
    ui->lineEditGammaFcd->setText(QString("1,4"));
    ui->lineEditFpk->setText(QString("1860"));
    ui->lineEditGammaFpd->setText(QString("1,15"));
    ui->spinBoxHp->setValue(75);
    ui->lineEditMed->setText("4341,925");
    ui->lineEditApc0->setText("93e-6");
    ui->spinBoxNpovg->setValue(4);

    ui->lineEditEp->setText(QString("195"));
    ui->lineEditEcm->setText(QString("36"));
    ui->lineEditK->setText(QString("1,2"));
    ui->lineEditB1S->setText(QString("0,5"));
    ui->lineEditB2S->setText(QString("0,5"));
    ui->lineEditB3S->setText(QString("0,125"));
    ui->lineEditH1S->setText(QString("0,1975"));
    ui->lineEditH2S->setText(QString("0,245"));
    ui->lineEditH3S->setText(QString("1,207"));

    addRowTable(ui->tableWidgetLower, 6, 0.08);
    addRowTable(ui->tableWidgetLower, 6, 0.12);
    addRowTable(ui->tableWidgetLower, 6, 0.16);
    addRowTable(ui->tableWidgetLower, 6, 0.20);
    addRowTable(ui->tableWidgetUpper, 4, 0.06);


    computeC();
    computeCSS();
    computeCForFireResitance();
}

void MainWindow::clearResults(){
    ui->lineEditAc->setText("");
    ui->lineEditBeta->setText("");
    ui->lineEditSc->setText("");
    ui->lineEditKappa->setText("");
    ui->lineEditIc->setText("");
    ui->lineEditRho->setText("");
    ui->lineEditCZrbFinal->setText("");
    ui->lineEditCSprFinal->setText("");
    ui->lineEditFcd->setText("");
    ui->lineEditFpd->setText("");
    ui->lineEditZ->setText("");
    ui->lineEditNpov->setText("");
    ui->lineEditAcc->setText("");
    ui->lineEditAlphaE->setText("");
    ui->lineEditAcs->setText("");
    ui->lineEditScs->setText("");

    ui->lineEditCNZbrOO->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNSprOO->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNZbrSS->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNZbr->setStyleSheet(lineEditBackgroundColorGrey);
}

bool MainWindow::checkThatResultsAreNumbers(double arg){
    if(isinf(arg) || isnan(arg)){
        msg.setText("Attempted to perform illegal operation (eg: divided by zero)\n"
                      "Change parameters");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
        return false;
    }
    else{
        return true;
    }
}

int MainWindow::getCMinDur(){
    return arrayA[ui->comboBoxConstruction->currentIndex()][ui->comboBoxExposition->currentIndex()];
}

int MainWindow::getCMinDurSS(){
    return arrayB[ui->comboBoxConstruction->currentIndex()][ui->comboBoxExposition->currentIndex()];
}

void MainWindow::computeC(){
    QLocale locale(QLocale::Polish); //solves problem with separator ( , -> .)

    int cMin =  calculateCmin(locale.toDouble(ui->lineEditPhiS->text()),
                             getCMinDur(),
                             locale.toDouble(ui->lineEditCDurY->text()),
                             locale.toDouble(ui->lineEditCDurSt->text()),
                             locale.toDouble(ui->lineEditCDurAdd->text())
                             );
    ui->lineEditCmin->setText(QString::number(cMin));
    ui->lineEditCNZbr->setText(QString::number(ceil((cMin+locale.toDouble(ui->lineEditCDev->text())))));
}

void MainWindow::computeCSS(){
    QLocale locale(QLocale::Polish); //solves problem with separator ( , -> .)

    int cMin =  calculateCmin(locale.toDouble(ui->lineEditPhiSSS->text())*1.5,
                             getCMinDurSS(),
                             locale.toDouble(ui->lineEditCDurYSS->text()),
                             locale.toDouble(ui->lineEditCDurStSS->text()),
                             locale.toDouble(ui->lineEditCDurAddSS->text())
                             );
    ui->lineEditCminSS->setText(QString::number(cMin));
    ui->lineEditCNZbrSS->setText(QString::number(ceil((cMin+locale.toDouble(ui->lineEditCDevSS->text())))));
}

void MainWindow::computeCForFireResitance(){
    QLocale locale(QLocale::Polish);
    double a = locale.toDouble(ui->lineEditA->text());
    double phiS = locale.toDouble(ui->lineEditPhiS->text());
    double phiStr = locale.toDouble(ui->lineEditPhiStr->text());

    int cZbr = static_cast<int>(std::ceil(a - (phiS/2) - phiStr));
    int cSpr = static_cast<int>(std::ceil(a - (phiS/2) - phiStr + getIncrementValueFromSteelType()));

    ui->lineEditCNZbrOO->setText(QString::number(cZbr));
    ui->lineEditCNSprOO->setText(QString::number(cSpr));
}

int MainWindow::getIncrementValueFromSteelType(){
    if(ui->comboBoxSteelType->currentIndex()){
        return 15;
    }
    else{
        return 10;
    }
}

void MainWindow::setFinalCValue(){
    QLocale locale(QLocale::Polish);

    if(locale.toInt(ui->lineEditCNZbr->text()) > locale.toInt(ui->lineEditCNZbrOO->text())){
        ui->lineEditCZrbFinal->setText(ui->lineEditCNZbr->text());
        ui->lineEditCNZbr->setStyleSheet(lineEditBackgroundColorGreen);
    }
    else{
        ui->lineEditCZrbFinal->setText(ui->lineEditCNZbrOO->text());
        ui->lineEditCNZbrOO->setStyleSheet(lineEditBackgroundColorGreen);
    }

    if(locale.toInt(ui->lineEditCNZbrSS->text()) > locale.toInt(ui->lineEditCNSprOO->text())){
        ui->lineEditCSprFinal->setText(ui->lineEditCNZbrSS->text());
        ui->lineEditCNZbrSS->setStyleSheet(lineEditBackgroundColorGreen);
    }
    else{
        ui->lineEditCSprFinal->setText(ui->lineEditCNSprOO->text());
        ui->lineEditCNSprOO->setStyleSheet(lineEditBackgroundColorGreen);
    }
}

double MainWindow::performFormulaFromLowerTable(){
    QTableWidget* table = ui->tableWidgetLower;
    double temp = 0;
    QLocale locale(QLocale::Polish);

    for(int i = 0; i < table->rowCount(); ++i){
        temp += locale.toDouble(getStringFromTable(table,i,1)) * locale.toDouble(getStringFromTable(table,i,2));
    }
    return temp;
}

double MainWindow::performFormulaFromUpperTable(double height){
    QTableWidget* table = ui->tableWidgetUpper;
    double temp = 0;
    QLocale locale(QLocale::Polish);

    for(int i = 0; i < table->rowCount(); ++i){
        temp += locale.toDouble(getStringFromTable(table,i,1)) * (height - locale.toDouble(getStringFromTable(table,i,2)));
    }
    return temp;
}
