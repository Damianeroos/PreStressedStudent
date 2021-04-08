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
    , lineEditSize(QSize(50,22))
{
    ui->setupUi(this);
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

    ui->labelB1->setText(QString("B<sub>1</sub> :"));
    ui->labelB2->setText(QString("B<sub>2</sub> :"));
    ui->labelB3->setText(QString("B<sub>3</sub> :"));
    ui->labelH1->setText(QString("H<sub>1</sub> :"));
    ui->labelH2->setText(QString("H<sub>2</sub> :"));
    ui->labelH3->setText(QString("H<sub>3</sub> :"));
    ui->labelH4->setText(QString("H<sub>4</sub> :"));
    ui->labelH5->setText(QString("H<sub>5</sub> :"));

    ui->lineEditB1->setMaximumSize(lineEditSize);
    ui->lineEditB2->setMaximumSize(lineEditSize);
    ui->lineEditB3->setMaximumSize(lineEditSize);
    ui->lineEditH1->setMaximumSize(lineEditSize);
    ui->lineEditH2->setMaximumSize(lineEditSize);
    ui->lineEditH3->setMaximumSize(lineEditSize);
    ui->lineEditH4->setMaximumSize(lineEditSize);
    ui->lineEditH5->setMaximumSize(lineEditSize);

    QDoubleValidator* figureParamsValidator = new QDoubleValidator(0, std::numeric_limits<double>::max(), 3, this);
    ui->lineEditB1->setValidator(figureParamsValidator);
    ui->lineEditB2->setValidator(figureParamsValidator);
    ui->lineEditB3->setValidator(figureParamsValidator);
    ui->lineEditH1->setValidator(figureParamsValidator);
    ui->lineEditH2->setValidator(figureParamsValidator);
    ui->lineEditH3->setValidator(figureParamsValidator);
    ui->lineEditH4->setValidator(figureParamsValidator);
    ui->lineEditH5->setValidator(figureParamsValidator);

    QDoubleValidator* cParamsValidator = new QDoubleValidator(0,std::numeric_limits<double>::max(),1,this);
    ui->lineEditPhiS->setValidator(cParamsValidator);
    ui->lineEditCDurY->setValidator(cParamsValidator);
    ui->lineEditCDurSt->setValidator(cParamsValidator);
    ui->lineEditCDurAdd->setValidator(cParamsValidator);
    ui->lineEditCDev->setValidator(cParamsValidator);
    ui->lineEditPhiSSS->setValidator(cParamsValidator);
    ui->lineEditCDurYSS->setValidator(cParamsValidator);
    ui->lineEditCDurStSS->setValidator(cParamsValidator);
    ui->lineEditCDurAddSS->setValidator(cParamsValidator);
    ui->lineEditCDevSS->setValidator(cParamsValidator);
    ui->lineEditPhiStr->setValidator(cParamsValidator);
    ui->lineEditA->setValidator(cParamsValidator);

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
    ui->comboBoxConstructionSS->addItem("S1");
    ui->comboBoxConstructionSS->addItem("S2");
    ui->comboBoxConstructionSS->addItem("S3");
    ui->comboBoxConstructionSS->addItem("S4");
    ui->comboBoxConstructionSS->addItem("S5");
    ui->comboBoxConstructionSS->addItem("S6");
    ui->comboBoxExpositionSS->addItem("X0");
    ui->comboBoxExpositionSS->addItem("XC1");
    ui->comboBoxExpositionSS->addItem("XC2/XC3");
    ui->comboBoxExpositionSS->addItem("XC4");
    ui->comboBoxExpositionSS->addItem("XD1/XS1");
    ui->comboBoxExpositionSS->addItem("XD2/XS2");
    ui->comboBoxExpositionSS->addItem("XD3/XS3");
    ui->comboBoxSteelType->addItem("pręt");
    ui->comboBoxSteelType->addItem("drut");
    ui->comboBoxSteelType->addItem("splot");

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

    QObject::connect(ui->comboBoxConstructionSS, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(computeCSS()));
    QObject::connect(ui->comboBoxExpositionSS, SIGNAL(currentIndexChanged(int)),
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
}

bool MainWindow::checkThatTypedArgumentsAreValid(){
    if(ui->lineEditB1->text().isEmpty() ||
            ui->lineEditB2->text().isEmpty() ||
            ui->lineEditB3->text().isEmpty() ||
            ui->lineEditH1->text().isEmpty() ||
            ui->lineEditH2->text().isEmpty() ||
            ui->lineEditH3->text().isEmpty() ||
            ui->lineEditH4->text().isEmpty() ||
            ui->lineEditH5->text().isEmpty()){
        return false;
    }
    else{
        return true;
    }
}

void MainWindow::startComputations(){
    if(!checkThatTypedArgumentsAreValid()){
        msg.setText("Please fill all parameters");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
        return;
    }
    else{
        clearResults();
        QLocale locale(QLocale::Polish); //solves problem with separator ( , -> .)

        mathFormulas data(locale.toDouble(ui->lineEditB1->text()),
                          locale.toDouble(ui->lineEditB2->text()),
                          locale.toDouble(ui->lineEditB3->text()),
                          locale.toDouble(ui->lineEditH1->text()),
                          locale.toDouble(ui->lineEditH2->text()),
                          locale.toDouble(ui->lineEditH3->text()),
                          locale.toDouble(ui->lineEditH4->text()),
                          locale.toDouble(ui->lineEditH5->text())
                          );

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
    return arrayB[ui->comboBoxConstructionSS->currentIndex()][ui->comboBoxExpositionSS->currentIndex()];
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
