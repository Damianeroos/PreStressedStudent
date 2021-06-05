#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDoubleValidator>
#include <QString>
#include "mathformulas.h"
#include <math.h>
#include <QLocale>
#include "arrays.h"
#include "mainwindow.h"


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
    ui->lineEditK1->setValidator(doubleValidator4);
    ui->lineEditK2->setValidator(doubleValidator4);
    ui->lineEditFp01k->setValidator(doubleValidator4);
    ui->lineEditK7->setValidator(doubleValidator4);
    ui->lineEditK8->setValidator(doubleValidator4);
    ui->lineEditT->setValidator(doubleValidator4);
    ui->lineEditAlphaT->setValidator(doubleValidator4);
    ui->lineEditU->setValidator(doubleValidator4);
    ui->lineEditFcmo->setValidator(doubleValidator4);
    ui->lineEditKh->setValidator(doubleValidator4);
    ui->lineEditXi->setValidator(doubleValidator4);
    ui->lineEditRsup->setValidator(doubleValidator4);
    ui->lineEditRinf->setValidator(doubleValidator4);
    ui->lineEditMeqp_2->setValidator(doubleValidator4);
    ui->lineEditLeff->setValidator(doubleValidator4);
    ui->lineEditFctm->setValidator(doubleValidator4);

    QIntValidator* intValidator = new QIntValidator(this);
    ui->lineEditT0->setValidator(intValidator);
    ui->lineEditTEnd->setValidator(intValidator);

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
    ui->lineEditZd->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditZg->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditIcs->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditWdcs->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditWgcs->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaPMax->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditP0max->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaPM0->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPM0->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditP1000->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditDeltaSigma->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditDeltaP->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditDeltaPtheta->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPm01->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPm02->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditDeltaPel->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaPM02->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditH0->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditFcm->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCoeffA1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCoeffA2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCoeffA3->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditBetaH->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditBetaC->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditBetaT0->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditBetaFcm->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditBetaRH->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditBetaAS->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPhiRH->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPhi0->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPhiT->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditAlphaDS1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditAlphaDS2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditEpsCD->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditEpsCDInf->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditEpsCA->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditEpsCAT->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditEpsCS->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaPR->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaPR2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaCQP->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaPCSR->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPcsr->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPmt->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaPMT->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditXeffspr->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditXeff->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditXefflim->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditMrd->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPksup->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditPkinf->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditEceff->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditB->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditA_2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditAlim->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmacpinf->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditMcr->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditF_1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaDC_1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaDC_2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditF_2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaGC_1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaGC_2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditF_3->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaCP_1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaCP_2->setStyleSheet(lineEditBackgroundColorGrey);

    ui->tabWidget->setStyleSheet("#tab_1 {background-color: rgb(240, 240, 240);}"
                                 "#tab_2 {background-color: rgb(240, 240, 240);}"
                                 "#tab_3 {background-color: rgb(240, 240, 240);}"
                                 "#tab_4 {background-color: rgb(240, 240, 240);}");

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

    ui->comboBoxClassRel->addItem("1");
    ui->comboBoxClassRel->addItem("2");
    ui->comboBoxClassRel->addItem("3");

    ui->comboBoxCement->addItem("S");
    ui->comboBoxCement->addItem("N");
    ui->comboBoxCement->addItem("R");

    // table lower
    ui->pushButtonAddRowLower->setIcon(QIcon(":/resources/img/plus.svg"));
    ui->pushButtonSubRowLower->setIcon(QIcon(":/resources/img/minus.svg"));
    ui->tableWidgetLower->setColumnCount(3);
    ui->tableWidgetLower->setShowGrid(true);
    QStringList lowerTableLabes = {"rząd", "l. splotów", "h [m]"};
    ui->tableWidgetLower->setHorizontalHeaderLabels(lowerTableLabes);
    ui->tableWidgetLower->horizontalHeader()->setStyleSheet("::section {background-color: lightblue;}");
    ui->tableWidgetLower->verticalHeader()->setVisible(false);
    ui->tableWidgetLower->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidgetLower->verticalHeader()->setDefaultSectionSize(24);
    ui->tableWidgetLower->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //table upper
    ui->pushButtonAddRowUpper->setIcon(QIcon(":/resources/img/plus.svg"));
    ui->pushButtonSubRowUpper->setIcon(QIcon(":/resources/img/minus.svg"));
    ui->tableWidgetUpper->setColumnCount(3);
    ui->tableWidgetUpper->setShowGrid(true);
    QStringList upperTableLabes = {"rząd", "l. splotów", "h [m]"};
    ui->tableWidgetUpper->setHorizontalHeaderLabels(upperTableLabes);
    ui->tableWidgetUpper->horizontalHeader()->setStyleSheet("::section {background-color: lightblue;}");
    ui->tableWidgetUpper->verticalHeader()->setVisible(false);
    ui->tableWidgetUpper->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidgetUpper->verticalHeader()->setDefaultSectionSize(24);
    ui->tableWidgetUpper->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //table phase
    ui->tableWidgetPhase->setColumnCount(3);
    ui->tableWidgetPhase->setShowGrid(true);
    QStringList phaseTableLabels = {"faza", "temp. [C]", "czas [h]"};
    ui->tableWidgetPhase->setHorizontalHeaderLabels(phaseTableLabels);
    ui->tableWidgetPhase->horizontalHeader()->setStyleSheet("::section {background-color: lightblue;}");
    ui->tableWidgetPhase->verticalHeader()->setVisible(false);
    ui->tableWidgetPhase->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidgetPhase->verticalHeader()->setDefaultSectionSize(24);
    ui->tableWidgetPhase->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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
    QObject::connect(this, SIGNAL(tableContextChanged(QTableWidget*)),
                     this, SLOT(setLabelInfoOfTable(QTableWidget*)));
    QObject::connect(ui->spinBoxNpovg, SIGNAL(valueChanged(int)),
                     this, SLOT(setLabelInfoOfUpperTable(int)));

    QObject::connect(ui->comboBoxClassRel, SIGNAL(currentIndexChanged(int)),
                    this, SLOT(setP1000(int)));
    QObject::connect(ui->radioButton, SIGNAL(clicked(bool)),
                    this, SLOT(setObjectPropertiesDependsFromRadioButton(bool)));

    QObject::connect(ui->tableWidgetPhase, SIGNAL(cellChanged(int,int)),
                     this, SLOT(validateCellDataPhaseTable(int,int)));

    QObject::connect(ui->lineEditH1S, SIGNAL(textEdited(QString)),
                     this, SLOT(calculateU()));
    QObject::connect(ui->lineEditH2S, SIGNAL(textEdited(QString)),
                     this, SLOT(calculateU()));
    QObject::connect(ui->lineEditH3S, SIGNAL(textEdited(QString)),
                     this, SLOT(calculateU()));
    QObject::connect(ui->lineEditB1S, SIGNAL(textEdited(QString)),
                     this, SLOT(calculateU()));
    QObject::connect(ui->lineEditB2S, SIGNAL(textEdited(QString)),
                     this, SLOT(calculateU()));
    QObject::connect(ui->lineEditB3S, SIGNAL(textEdited(QString)),
                     this, SLOT(calculateU()));

    QObject::connect(ui->comboBoxCement, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(setAlphaCoeffCement(int)));

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

    ui->lineEditT0->setText(QString("28"));
    ui->lineEditTEnd->setText(QString("50"));
    ui->spinBoxRH->setValue(50);
    ui->lineEditFcmo->setText("10");
    ui->lineEditKh->setText("0,883");

    ui->lineEditRsup->setText("1,05");
    ui->lineEditRinf->setText("0,95");

    addRowTable(ui->tableWidgetLower, 6, 0.08);
    addRowTable(ui->tableWidgetLower, 6, 0.12);
    addRowTable(ui->tableWidgetLower, 6, 0.16);
    addRowTable(ui->tableWidgetLower, 6, 0.20);
    addRowTable(ui->tableWidgetUpper, 4, 0.06);

    ui->labelSumLowerTable->setText(QString::number(getItemsSumOfRow1(ui->tableWidgetLower)));
    ui->labelSumUpperTable->setText(QString::number(getItemsSumOfRow1(ui->tableWidgetUpper)));

    ui->labelUpperNpov->setText(QString::number(ui->spinBoxNpovg->value()));

    ui->lineEditK1->setText(QString("0,8"));
    ui->lineEditK2->setText(QString("0,9"));
    ui->lineEditFp01k->setText(QString("149"));
    ui->lineEditK7->setText(QString("0,75"));
    ui->lineEditK8->setText(QString("0,85"));
    setP1000(ui->comboBoxClassRel->currentIndex());
    ui->lineEditT->setText(QString("70"));
    initPhaseTable();
    ui->tableWidgetPhase->setDisabled(true);
    ui->lineEditAlphaT->setText("1,2e-5");

    ui->radioButton->setChecked(true);
    setObjectPropertiesDependsFromRadioButton(true);
    ui->comboBoxClassRel->setCurrentIndex(1);
    ui->lineEditP1000->setText(QString("2,5"));

    ui->comboBoxCement->setCurrentIndex(1);
    ui->lineEditAlphaDS1->setText("4");
    ui->lineEditAlphaDS2->setText("0,12");

    ui->lineEditMeqp->setText("2433,738");

    ui->lineEditXi->setText("0,433");
    ui->lineEditMeqp_2->setText("2936,8");
    ui->lineEditLeff->setText("11,78");
    ui->lineEditFctm->setText("3,2");

    computeC();
    computeCSS();
    computeCForFireResitance();
    calculateU();
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
    ui->lineEditZd->setText("");
    ui->lineEditZg->setText("");
    ui->lineEditIcs->setText("");
    ui->lineEditWdcs->setText("");
    ui->lineEditWgcs->setText("");
    ui->lineEditSigmaPMax->setText("");
    ui->lineEditP0max->setText("");
    ui->lineEditSigmaPM0->setText("");
    ui->lineEditPM0->setText("");
    ui->lineEditDeltaSigma->setText("");
    ui->lineEditDeltaP->setText("");
    ui->lineEditDeltaPtheta->setText("");
    ui->lineEditPm01->setText("");
    ui->lineEditPm02->setText("");
    ui->lineEditDeltaPel->setText("");
    ui->lineEditSigmaPM02->setText("");
    ui->lineEditH0->setText("");
    ui->lineEditFcm->setText("");
    ui->lineEditCoeffA1->setText("");
    ui->lineEditCoeffA2->setText("");
    ui->lineEditCoeffA3->setText("");
    ui->lineEditBetaH->setText("");
    ui->lineEditBetaC->setText("");
    ui->lineEditBetaT0->setText("");
    ui->lineEditBetaFcm->setText("");
    ui->lineEditBetaRH->setText("");
    ui->lineEditBetaAS->setText("");
    ui->lineEditPhiRH->setText("");
    ui->lineEditPhi0->setText("");
    ui->lineEditPhiT->setText("");
    ui->lineEditEpsCD->setText("");
    ui->lineEditEpsCDInf->setText("");
    ui->lineEditEpsCA->setText("");
    ui->lineEditEpsCAT->setText("");
    ui->lineEditEpsCS->setText("");
    ui->lineEditSigmaPR->setText("");
    ui->lineEditSigmaPR2->setText("");
    ui->lineEditSigmaCQP->setText("");
    ui->lineEditSigmaPCSR->setText("");
    ui->lineEditPcsr->setText("");
    ui->lineEditPmt->setText("");
    ui->lineEditSigmaPMT->setText("");
    ui->lineEditXeffspr->setText("");
    ui->lineEditXeff->setText("");
    ui->lineEditXefflim->setText("");
    ui->labelProfile->setText("");
    ui->lineEditMrd->setText("");
    ui->lineEditPksup->setText("");
    ui->lineEditPkinf->setText("");
    ui->lineEditEceff->setText("");
    ui->lineEditB->setText("");
    ui->lineEditA_2->setText("");
    ui->lineEditAlim->setText("");
    ui->lineEditSigmacpinf->setText("");
    ui->lineEditMcr->setText("");
    ui->lineEditF_1->setText("");
    ui->lineEditSigmaDC_1->setText("");
    ui->lineEditSigmaDC_2->setText("");
    ui->lineEditF_2->setText("");
    ui->lineEditSigmaGC_1->setText("");
    ui->lineEditSigmaGC_2->setText("");
    ui->lineEditF_3->setText("");
    ui->lineEditSigmaCP_1->setText("");
    ui->lineEditSigmaCP_2->setText("");

    ui->lineEditCNZbrOO->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNSprOO->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNZbrSS->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditCNZbr->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaDC_1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaDC_2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaGC_1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaGC_2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaCP_1->setStyleSheet(lineEditBackgroundColorGrey);
    ui->lineEditSigmaCP_2->setStyleSheet(lineEditBackgroundColorGrey);
    ui->labelSumUpperTable->setStyleSheet("QLabel { background-color : rgb(240, 240, 240);}");
    ui->labelSumLowerTable->setStyleSheet("QLabel { background-color : rgb(240, 240, 240);}");
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
                          locale.toDouble(ui->lineEditH3S->text()),
                          ui->spinBoxRH->value(),
                          locale.toInt(ui->lineEditT0->text()),
                          locale.toInt(ui->lineEditTEnd->text()) * 365,
                          locale.toDouble(ui->lineEditAlphaDS1->text()),
                          locale.toDouble(ui->lineEditAlphaDS2->text())); //casting from years to days

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
            msg.setText("<p>Współczynnik &beta; powinien spełniać założenie 0,18 &lt; &beta; &lt; 0,35</p>"
                        "<p>Przekrój jest zbyt smukły</p>");
            msg.setIcon(QMessageBox::Warning);
            msg.exec();
        }
        else if(paramBeta > 0.35){
            msg.setText("<p>Współczynnik &beta; powinien spełniać założenie 0,18 &lt; &beta; &lt; 0,35</p>"
                        "<p>Przekrój nie jest optymalnie zaprojektowany</p>");
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
            msg.setText("<p>Współczynnik &kappa; powinien spełniać założenie 0,35 &lt; &kappa; &lt; 0,65\n</p>"
                        "<p>Przekrój nie spełnia warunku granicznego wskaźnika asymetrii</p>");
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
        ui->labelLowerNpov->setText(QString::number(paramNpov));
        if(!checkThatResultsAreNumbers(paramNpov)){
            return;
        }
        checkIfNumberOfTendonsAreValid(paramNpov);

        double paramAcc = data.calculateAcc();
        ui->lineEditAcc->setText(locale.toString(paramAcc));
        if(!checkThatResultsAreNumbers(paramAcc)){
            return;
        }
        if(paramAcc > data.getA1()){
            msg.setText("<p>Warunek A<sub>cc</sub> &lt; A<sub>1</sub> nie został spełniony.</p>"
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
        data.setApUpper(performFormulaFromUpperTable(data.getH()));
        double paramScs = data.calculateScs();
        ui->lineEditScs->setText(locale.toString(paramScs));
        if(!checkThatResultsAreNumbers(paramScs)){
            return;
        }

        double paramZd = data.calculateZd();
        ui->lineEditZd->setText(locale.toString(paramZd));
        if(!checkThatResultsAreNumbers(paramZd)){
            return;
        }

        double paramZg = data.calculateZg();
        ui->lineEditZg->setText(locale.toString(paramZg));
        if(!checkThatResultsAreNumbers(paramZg)){
            return;
        }

        data.setSumF2d(performFormula2FromTable(ui->tableWidgetLower,data.getZd(),data.getH(),false));
        data.setSumF2g(performFormula2FromTable(ui->tableWidgetUpper,data.getZg(),data.getH(),true));
        double paramIcs = data.calculateIcs();
        ui->lineEditIcs->setText(locale.toString(paramIcs));
        if(!checkThatResultsAreNumbers(paramIcs)){
            return;
        }

        double paramWdcs = data.calculateWdcs();
        ui->lineEditWdcs->setText(locale.toString(paramWdcs));
        if(!checkThatResultsAreNumbers(paramWdcs)){
            return;
        }

        double paramWgcs = data.calculateWgcs();
        ui->lineEditWgcs->setText(locale.toString(paramWgcs));
        if(!checkThatResultsAreNumbers(paramWgcs)){
            return;
        }

        double paramSigmapmax = data.calculateSigma(locale.toDouble(ui->lineEditK1->text()),
                                                    locale.toDouble(ui->lineEditK2->text()),
                                                    locale.toDouble(ui->lineEditFpk->text()),
                                                    locale.toDouble(ui->lineEditFp01k->text()),
                                                    locale.toDouble(ui->lineEditApc0->text())
                                                    );
        ui->lineEditSigmaPMax->setText(locale.toString(paramSigmapmax));
        if(!checkThatResultsAreNumbers(paramSigmapmax)){
            return;
        }

        double paramP0max = data.calculateP0max();
        ui->lineEditP0max->setText(locale.toString(paramP0max));
        if(!checkThatResultsAreNumbers(paramP0max)){
            return;
        }

        double paramSigmapm0 = data.calculateSigma0(locale.toDouble(ui->lineEditK7->text()),
                                                    locale.toDouble(ui->lineEditK8->text()),
                                                    locale.toDouble(ui->lineEditFpk->text())
                                                    );
        ui->lineEditSigmaPM0->setText(locale.toString(paramSigmapm0));
        if(!checkThatResultsAreNumbers(paramSigmapm0)){
            return;
        }

        double paramPM0 = data.calculatePm0();
        ui->lineEditPM0->setText(locale.toString(paramPM0));
        if(!checkThatResultsAreNumbers(paramPM0)){
            return;
        }

        if(ui->radioButton->isChecked()){
            data.calculateTemporaryLosses(getSumT(),
                                          computeTeq(),
                                          locale.toDouble(ui->lineEditP1000->text()),
                                          locale.toDouble(ui->lineEditFpk->text())
                                          );
        }
        else{
            data.calculateTemporaryLosses(locale.toDouble(ui->lineEditT->text()),
                                          locale.toDouble(ui->lineEditP1000->text()),
                                          locale.toDouble(ui->lineEditFpk->text())
                                          );
        }
        double paramDeltaSigma = data.getDeltaSigma();
        ui->lineEditDeltaSigma->setText(locale.toString(paramDeltaSigma));
        if(!checkThatResultsAreNumbers(paramDeltaSigma)){
            return;
        }
        double paramDeltaP = data.getDeltaP();
        ui->lineEditDeltaP->setText(locale.toString(paramDeltaP));
        if(!checkThatResultsAreNumbers(paramDeltaP)){
            return;
        }

        double paramDeltaPTheta = data.calculateDeltaPTheta(computeDeltaT(ui->radioButton->isChecked()),
                                                            locale.toDouble(ui->lineEditAlphaT->text())
                                                            );
        ui->lineEditDeltaPtheta->setText(locale.toString(paramDeltaPTheta));
        if(!checkThatResultsAreNumbers(paramDeltaPTheta)){
            return;
        }

        double paramPm01 = data.calculatePm01();
        ui->lineEditPm01->setText(locale.toString(paramPm01));
        if(!checkThatResultsAreNumbers(paramPm01)){
            return;
        }

        data.setSumF3d(performFormula3FromTable(ui->tableWidgetLower,data.getZd(),data.getH(),false));
        data.setSumF3g(performFormula3FromTable(ui->tableWidgetUpper,data.getZg(),data.getH(),false)); // zamienic na true jezeli Julita się jebneła
        double paramDeltaPel = data.calculateDeltaPel();
        ui->lineEditDeltaPel->setText(locale.toString(paramDeltaPel));
        if(!checkThatResultsAreNumbers(paramDeltaPel)){
            return;
        }

        double paramPm02 = data.calculatePm02();
        ui->lineEditPm02->setText(locale.toString(paramPm02));
        if(!checkThatResultsAreNumbers(paramPm02)){
            return;
        }

        double paramSigmaPm02 = data.calculateSigmaPm02();
        ui->lineEditSigmaPM02->setText(locale.toString(paramSigmaPm02));
        if(!checkThatResultsAreNumbers(paramSigmaPm02)){
            return;
        }
        if(paramSigmaPm02 > paramSigmapm0){
            msg.setText("<p>Warunek &sigma;<sub>pm,02</sub> &le; &sigma;<sub>pm0</sub>(x) nie został spełniony.</p>"
                        "<p>&sigma;<sub>pm,02</sub> = " + QString::number(paramSigmaPm02)+ " MPa</p>"
                        "<p>&sigma;<sub>pm0</sub>(x) = " + QString::number(paramSigmapm0)+ " MPa</p>");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }

        data.setU(locale.toDouble(ui->lineEditU->text()));
        double paramH0 = data.calculateH0();
        ui->lineEditH0->setText(locale.toString(paramH0));
        if(!checkThatResultsAreNumbers(paramH0)){
            return;
        }

        double paramFcm = data.calculateFcm();
        ui->lineEditFcm->setText(locale.toString(paramFcm));
        if(!checkThatResultsAreNumbers(paramFcm)){
            return;
        }

        std::vector<double> a = data.calculateParametersA();
        ui->lineEditCoeffA1->setText(locale.toString(a[0]));
        ui->lineEditCoeffA2->setText(locale.toString(a[1]));
        ui->lineEditCoeffA3->setText(locale.toString(a[2]));
        for(double n : a){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }

        std::vector<double> beta = data.calculateBetas();
        ui->lineEditBetaH->setText(locale.toString(beta[0]));
        ui->lineEditBetaC->setText(locale.toString(beta[1]));
        ui->lineEditBetaT0->setText(locale.toString(beta[2]));
        ui->lineEditBetaFcm->setText(locale.toString(beta[3]));
        ui->lineEditBetaRH->setText(locale.toString(beta[4]));
        ui->lineEditBetaAS->setText(locale.toString(beta[5]));
        for(double n : beta){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }

        std::vector<double> phi = data.calculatePhis();
        ui->lineEditPhiRH->setText(locale.toString(phi[0]));
        ui->lineEditPhi0->setText(locale.toString(phi[1]));
        ui->lineEditPhiT->setText(locale.toString(phi[2]));
        for(double n : phi){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }

        std::vector<double> eps = data.calculateEpsilons(locale.toDouble(ui->lineEditFcmo->text()),
                                                         locale.toDouble(ui->lineEditKh->text()));
        ui->lineEditEpsCD->setText(locale.toString(eps[0]));
        ui->lineEditEpsCDInf->setText(locale.toString(eps[1]));
        ui->lineEditEpsCA->setText(locale.toString(eps[2]));
        ui->lineEditEpsCAT->setText(locale.toString(eps[3]));
        ui->lineEditEpsCS->setText(locale.toString(eps[4]));
        for(double n : eps){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }

        std::vector<double> sigma = data.calculateSigmas(locale.toDouble(ui->lineEditMeqp->text()),
                                                         locale.toDouble(ui->lineEditP1000->text()));
        ui->lineEditSigmaPR->setText(locale.toString(sigma[0]));
        ui->lineEditSigmaPR2->setText(locale.toString(sigma[1]));
        ui->lineEditSigmaCQP->setText(locale.toString(sigma[2]));
        ui->lineEditSigmaPCSR->setText(locale.toString(sigma[3]));
        ui->lineEditSigmaPMT->setText(locale.toString(sigma[4]));
        for(double n : sigma){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }

        double paramPcsr = data.calculatePcsr();
        ui->lineEditPcsr->setText(locale.toString(paramPcsr));
        if(!checkThatResultsAreNumbers(paramPcsr)){
            return;
        }

        double paramPmt = data.calculatePmt();
        ui->lineEditPmt->setText(locale.toString(paramPmt));
        if(!checkThatResultsAreNumbers(paramPmt)){
            return;
        }
        if(sigma[4] > 0.65*locale.toDouble(ui->lineEditFpk->text())){
            msg.setText("<p>Warunek &sigma;<sub>pmt</sub> &le; 0.65*f<sub>pk</sub> nie został spełniony.</p>"
                        "<p>&sigma;<sub>pmt</sub> = " + QString::number(sigma[4])+ " MPa</p>"
                        "<p>0.65*f<sub>pk</sub> = " + QString::number(0.65*locale.toDouble(ui->lineEditFpk->text()))+ " MPa</p>");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }

        std::vector<double> x = data.calculateXs(locale.toDouble(ui->lineEditXi->text()),
                                                 locale.toDouble(getStringFromTable(ui->tableWidgetLower,0,2)),
                                                 locale.toDouble(getStringFromTable(ui->tableWidgetUpper,0,2)),
                                                 getAreaApLower(),
                                                 getAreaApUpper());
        ui->lineEditXeffspr->setText(locale.toString(x[0]));
        ui->lineEditXeff->setText(locale.toString(x[1]));
        ui->lineEditXefflim->setText(locale.toString(x[2]));
        for(double n : x){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }
        if(x[0]<=locale.toDouble(ui->lineEditH1S->text())){
            ui->labelProfile->setText("PRZEKRÓJ POZORNIE TEOWY");
        }
        else{
            ui->labelProfile->setText("PRZEKRÓJ RZECZYWIŚCIE TEOWY");
        }

        double paramMrd = data.getMrd();
        ui->lineEditMrd->setText(locale.toString(paramMrd));
        if(!checkThatResultsAreNumbers(paramMrd)){
            return;
        }

        std::pair<double, double> pk = data.calculatePk(locale.toDouble(ui->lineEditRsup->text()),
                                                        locale.toDouble(ui->lineEditRinf->text())
                                                        );
        ui->lineEditPksup->setText(locale.toString(pk.first));
        ui->lineEditPkinf->setText(locale.toString(pk.second));
        if(!(checkThatResultsAreNumbers(pk.first) || checkThatResultsAreNumbers(pk.second))){
            return;
        }

        double Eceff = data.calculateEceff();
        ui->lineEditEceff->setText(locale.toString(Eceff));
        if(!checkThatResultsAreNumbers(Eceff)){
            return;
        }

        double B = data.calculateB();
        ui->lineEditB->setText(locale.toString(B));
        if(!checkThatResultsAreNumbers(B)){
            return;
        }

        std::pair<double, double> aa = data.calculateA(locale.toDouble(ui->lineEditMeqp_2->text()),
                                                        locale.toDouble(ui->lineEditLeff->text())
                                                        );
        ui->lineEditA_2->setText(locale.toString(aa.first));
        ui->lineEditAlim->setText(locale.toString(aa.second));
        if(!(checkThatResultsAreNumbers(aa.first) || checkThatResultsAreNumbers(aa.second))){
            return;
        }

        double sigmaCpinf = data.calculateSigmaCpinf();
        ui->lineEditSigmacpinf->setText(locale.toString(sigmaCpinf));
        if(!checkThatResultsAreNumbers(sigmaCpinf)){
            return;
        }

        double mcr = data.calculateMcr(locale.toDouble(ui->lineEditFctm->text()));
        ui->lineEditMcr->setText(locale.toString(mcr));
        if(!checkThatResultsAreNumbers(mcr)){
            return;
        }

        std::vector<double> css1 = data.calculateStressesInSection_1(locale.toDouble(ui->lineEditMeqp->text()));
        ui->lineEditF_1->setText(locale.toString(css1[0]));
        ui->lineEditSigmaDC_1->setText(locale.toString(css1[1]));
        ui->lineEditSigmaDC_2->setText(locale.toString(css1[2]));
        for(double n : css1){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }
        if(css1[0]>css1[1]){
           ui->lineEditSigmaDC_1->setStyleSheet(lineEditBackgroundColorGreen);
        }
        else{
            ui->lineEditSigmaDC_1->setStyleSheet(lineEditBackgroundColorRed);
        }
        if(css1[0]>css1[2]){
           ui->lineEditSigmaDC_2->setStyleSheet(lineEditBackgroundColorGreen);
        }
        else{
            ui->lineEditSigmaDC_2->setStyleSheet(lineEditBackgroundColorRed);
        }

        std::vector<double> css2 = data.calculateStressesInSection_2(locale.toDouble(ui->lineEditMeqp->text()),
                                                                     locale.toDouble(ui->lineEditFctm->text()));
        ui->lineEditF_2->setText(locale.toString(css2[0]));
        ui->lineEditSigmaGC_1->setText(locale.toString(css2[1]));
        ui->lineEditSigmaGC_2->setText(locale.toString(css2[2]));
        for(double n : css2){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }
        if(css2[0]>css2[1]){
           ui->lineEditSigmaGC_1->setStyleSheet(lineEditBackgroundColorGreen);
        }
        else{
            ui->lineEditSigmaGC_1->setStyleSheet(lineEditBackgroundColorRed);
        }
        if(css2[0]>css2[2]){
           ui->lineEditSigmaGC_2->setStyleSheet(lineEditBackgroundColorGreen);
        }
        else{
            ui->lineEditSigmaGC_2->setStyleSheet(lineEditBackgroundColorRed);
        }

        std::vector<double> css3 = data.calculateStressesInSection_3(locale.toDouble(ui->lineEditMeqp->text()));
        ui->lineEditF_3->setText(locale.toString(css3[0]));
        ui->lineEditSigmaCP_1->setText(locale.toString(css3[1]));
        ui->lineEditSigmaCP_2->setText(locale.toString(css3[2]));
        for(double n : css3){
            if(!checkThatResultsAreNumbers(n)){
                return;
            }
        }
        if(css3[0]>css3[1]){
           ui->lineEditSigmaCP_1->setStyleSheet(lineEditBackgroundColorGreen);
        }
        else{
            ui->lineEditSigmaCP_1->setStyleSheet(lineEditBackgroundColorRed);
        }
        if(css3[0]>css3[2]){
           ui->lineEditSigmaCP_2->setStyleSheet(lineEditBackgroundColorGreen);
        }
        else{
            ui->lineEditSigmaCP_2->setStyleSheet(lineEditBackgroundColorRed);
        }

        setFinalCValue();
    }
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

    emit tableContextChanged(table);
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

    emit tableContextChanged(table);
}

void MainWindow::addRowPhaseTable(double c, double h){
    QTableWidget *table = ui->tableWidgetPhase;
    QLocale locale(QLocale::Polish);
    table->insertRow(table->rowCount());

    QTableWidgetItem* itemF = new QTableWidgetItem(QString::number(table->rowCount()));
    table->setItem(table->rowCount()-1, 0, itemF);
    itemF->setTextAlignment(Qt::AlignHCenter);
    itemF->setFlags(itemF->flags() ^ Qt::ItemIsEditable);

    QTableWidgetItem* itemC = new QTableWidgetItem(locale.toString(c));
    table->setItem(table->rowCount()-1, 1, itemC);
    itemC->setTextAlignment(Qt::AlignHCenter);

    QTableWidgetItem* itemH = new QTableWidgetItem(locale.toString(h));
    table->setItem(table->rowCount()-1, 2, itemH);
    itemH->setTextAlignment(Qt::AlignHCenter);
}

double MainWindow::getSumT(){
    QLocale locale(QLocale::Polish);
    QTableWidget *table = ui->tableWidgetPhase;

    double sumT = 0;
    for(int i = 0; i < table->rowCount(); ++i){
        sumT += locale.toDouble(getStringFromTable(table,i,1));
    }
    return sumT;
}

double MainWindow::getAreaApLower()
{
    QLocale locale(QLocale::Polish);
    return QString(ui->labelSumLowerTable->text()).toInt()*locale.toDouble(ui->lineEditApc0->text());
}

double MainWindow::getAreaApUpper()
{
    QLocale locale(QLocale::Polish);
    return QString(ui->labelSumUpperTable->text()).toInt()*locale.toDouble(ui->lineEditApc0->text());
}

void MainWindow::calculateU()
{
    QLocale locale(QLocale::Polish);
    double H1S = locale.toDouble(ui->lineEditH1S->text());
    double H2S = locale.toDouble(ui->lineEditH2S->text());
    double H3S = locale.toDouble(ui->lineEditH3S->text());
    double B1S = locale.toDouble(ui->lineEditB1S->text());
    double B2S = locale.toDouble(ui->lineEditB2S->text());
    double B3S = locale.toDouble(ui->lineEditB3S->text());

    double h = H1S + H2S + H3S;

    double U = B1S + B2S + 2*h + (B1S - B3S) + (B2S - B3S);
    ui->lineEditU->setText(locale.toString(U));
}

void MainWindow::setAlphaCoeffCement(int arg)
{
    switch (arg) {
    case 0 :
        ui->lineEditAlphaDS1->setText("3");
        ui->lineEditAlphaDS2->setText("0,13");
        break;
    case 1 :
        ui->lineEditAlphaDS1->setText("4");
        ui->lineEditAlphaDS2->setText("0,12");
        break;
    case 2 :
        ui->lineEditAlphaDS1->setText("6");
        ui->lineEditAlphaDS2->setText("0,11");
        break;
    }
}

double MainWindow::computeDeltaT(bool withThermalTreatment, int initialT){
    QLocale locale(QLocale::Polish);
    if(withThermalTreatment){
        QTableWidget *table = ui->tableWidgetPhase;
        //finding the lowest temperature
        double minT = locale.toDouble(getStringFromTable(table,0,1));
        double temp;
        for(int i = 1; i < table->rowCount(); ++i){
            temp = locale.toDouble(getStringFromTable(table,i,1));
            if(minT > temp){
                minT = temp;
            }
        }
        //finding the highest temperature
        double maxT = locale.toDouble(getStringFromTable(table,0,1));
        for(int i = 1; i < table->rowCount(); ++i){
            temp = locale.toDouble(getStringFromTable(table,i,1));
            if(maxT < temp){
                maxT = temp;
            }
        }
        return maxT-minT;
    }
    else{
        return locale.toDouble(ui->lineEditT->text()) - initialT;
    }
}

double MainWindow::computeTeq()
{
    QLocale locale(QLocale::Polish);
    QTableWidget *table = ui->tableWidgetPhase;

    double maxT = locale.toDouble(getStringFromTable(table,0,1));
    double temp;
    for(int i = 1; i < table->rowCount(); ++i){
        temp = locale.toDouble(getStringFromTable(table,i,1));
        if(maxT < temp){
            maxT = temp;
        }
    }

    temp = pow(1.14,maxT-20)/(maxT-20);
    double temp1 = 0;
    for(int i = 1; i < table->rowCount(); ++i){
        temp1 += (locale.toDouble(getStringFromTable(table,i,1)) - 20) *
                locale.toDouble(getStringFromTable(table,i,2));
    }

    return temp*temp1;
}

void MainWindow::initPhaseTable(){
    addRowPhaseTable(20, 4);
    addRowPhaseTable(45, 2);
    addRowPhaseTable(70, 6);
    addRowPhaseTable(45, 2);
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
    emit tableContextChanged(table);
}

void MainWindow::removeRowUpperTable(){
    QTableWidget* table = ui->tableWidgetUpper;

    if(!table->rowCount()){
        return;
    }
    else{
       table->removeRow(table->rowCount()-1);
    }
    emit tableContextChanged(table);
}

QString MainWindow::getStringFromTable(QTableWidget *table, int row, int column){
    if(!table->rowCount()){
        return QString("");
    }
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
    QString cellValue = getStringFromTable(table, row, column);
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
    emit tableContextChanged(table);
}

void MainWindow::validateCellDataPhaseTable(int row, int column){
    if(!column){ // cells in column 0 are not editable
        return;
    }
    QTableWidget* table = ui->tableWidgetPhase;
    QString cellValue = getStringFromTable(table, row, column);
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

void MainWindow::validateCellDataUpperTable(int row, int column){
    if(!column){ // cells in column 0 are not editable
        return;
    }
    QTableWidget* table = ui->tableWidgetUpper;
    QString cellValue = getStringFromTable(table, row, column);
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
    emit tableContextChanged(table);
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

double MainWindow::performFormula2FromTable(QTableWidget *table, double z, double height, bool isUpperTable)
{
    double result = 0;
    QLocale locale(QLocale::Polish);

    if(!isUpperTable){
        for(int i = 0; i < table->rowCount(); ++i){
            result += locale.toDouble(getStringFromTable(table,i,1)) * pow((z - locale.toDouble(getStringFromTable(table,i,2))),2);
        }
    }
    else{
        for(int i = 0; i < table->rowCount(); ++i){
            result += locale.toDouble(getStringFromTable(table,i,1)) * pow((z - (height - locale.toDouble(getStringFromTable(table,i,2)))),2);
        }
    }
    return result;
}

double MainWindow::performFormula3FromTable(QTableWidget *table, double z, double height, bool isUpperTable)
{
    double result = 0;
    QLocale locale(QLocale::Polish);

    if(!isUpperTable){
        for(int i = 0; i < table->rowCount(); ++i){
            result += locale.toDouble(getStringFromTable(table,i,1)) * (z - locale.toDouble(getStringFromTable(table,i,2)));
        }
    }
    else{
        for(int i = 0; i < table->rowCount(); ++i){
            result += locale.toDouble(getStringFromTable(table,i,1)) * (z - (height - locale.toDouble(getStringFromTable(table,i,2))));
        }
    }
    return result;
}

int MainWindow::getItemsSumOfRow1(QTableWidget *table)
{
    QLocale locale(QLocale::Polish);
    int result = 0;
    for(int i = 0; i < table->rowCount(); ++i){
        result += locale.toInt(getStringFromTable(table,i,1));
    }
    return result;
}

void MainWindow::checkIfNumberOfTendonsAreValid(int computeNpovd)
{
    int Npovg = getItemsSumOfRow1(ui->tableWidgetUpper);
    int Npovd = getItemsSumOfRow1(ui->tableWidgetLower);

    if(Npovg != ui->spinBoxNpovg->value()){
        ui->labelSumUpperTable->setStyleSheet("QLabel { background-color : red;}");
    }
    if(Npovd != computeNpovd) {
        ui->labelSumLowerTable->setStyleSheet("QLabel { background-color : red;}");
    }
    if(Npovg != ui->spinBoxNpovg->value() || Npovd != computeNpovd){
        msg.setText("Liczba splotów wpisanych do tabeli jest nieprawidłowa\n"
                "Popraw tabelę.");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}

void MainWindow::setLabelInfoOfTable(QTableWidget* table){
    if(table == ui->tableWidgetLower){
        ui->labelSumLowerTable->setText(QString::number(getItemsSumOfRow1(table)));
    }
    else if(table == ui->tableWidgetUpper){
        ui->labelSumUpperTable->setText(QString::number(getItemsSumOfRow1(table)));
    }
}

void MainWindow::setLabelInfoOfUpperTable(int arg)
{
    ui->labelUpperNpov->setText(QString::number(arg));
}

void MainWindow::setP1000(int arg)
{
    switch (arg) {
    case 0:
        ui->lineEditP1000->setText("8");
        break;
    case 1:
        ui->lineEditP1000->setText("2,5");
        break;
    case 2:
        ui->lineEditP1000->setText("4");
        break;
    }
}

void MainWindow::setObjectPropertiesDependsFromRadioButton(bool arg)
{
    if(arg){
        ui->labelT->setDisabled(true);
        ui->labelT1->setDisabled(true);
        ui->labelT2->setDisabled(true);
        ui->lineEditT->setDisabled(true);

        ui->tableWidgetPhase->setEnabled(true);
    }
    else{
        ui->labelT->setEnabled(true);
        ui->labelT1->setEnabled(true);
        ui->labelT2->setEnabled(true);
        ui->lineEditT->setEnabled(true);

        ui->tableWidgetPhase->setDisabled(true);
    }
}
