#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    void init();
    void initParameters();
    double formula1();
    bool checkThatTypedArgumentsAreValid();
    QMessageBox msg;
    void clearResults();
    bool checkThatResultsAreNumbers(double arg);
    void test();
    int getCMinDur();
    int getCMinDurSS();
    int getIncrementValueFromSteelType();
    void setFinalCValue();
    QPixmap pix;
    const QString lineEditBackgroundColorGrey =  "QLineEdit { background: rgb(225, 225, 225); selection-background-color: rgb(0, 120, 215); }";
    const QString lineEditBackgroundColorGreen = "QLineEdit { background: rgb(120, 230, 120); selection-background-color: rgb(0, 120, 215); }";
    void addRowTable(QTableWidget* table, int aCount, double hValue);
    void addRowTable(QTableWidget* table);
    void removeRowTable(QTableWidget* table);
    QString getStringFromTable(QTableWidget* table, int row, int column);
    void setCellTableValue(QTableWidget* table, int row, int column, QString text);
    double performFormulaFromLowerTable(); // li * ai
    double performFormulaFromUpperTable(double height); // li * (height - ai)
    double performFormula2FromTable(QTableWidget* table, double z, double height, bool isUpperTable); // SUM(li*(z-ai)^2)
    double performFormula3FromTable(QTableWidget *table, double z, double height, bool isUpperTable); // SUM(li*(z-ai))
    int getItemsSumOfRow1(QTableWidget* table);
    void checkIfNumberOfTendonsAreValid(int computeNpovd);
    void initPhaseTable();
    void addRowPhaseTable(double c, double h);
    double computeTeq();
    double computeDeltaT(bool withThermalTreatment, int initialT = 20);
    double getSumT();

public slots:
    void startComputations();
    void computeC();
    void computeCSS();
    void computeCForFireResitance();
    void addRowLowerTable();
    void addRowUpperTable();
    void removeRowLowerTable();
    void removeRowUpperTable();
    void validateCellDataLowerTable(int, int);
    void validateCellDataUpperTable(int, int);    
    void setLabelInfoOfTable(QTableWidget* table);
    void setLabelInfoOfUpperTable(int);
    void setP1000(int);
    void setObjectPropertiesDependsFromRadioButton(bool);
    void validateCellDataPhaseTable(int row, int column);
    void calculateU();
    void setAlphaCoeffCement(int);
signals:
    void tableContextChanged(QTableWidget* table);
};
#endif // MAINWINDOW_H
