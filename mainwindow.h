#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>

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
    const QSize lineEditSize;
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

public slots:
    void startComputations();
    void computeC();
    void computeCSS();
    void computeCForFireResitance();
};
#endif // MAINWINDOW_H
