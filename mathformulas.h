#ifndef MATHFORMULAS_H
#define MATHFORMULAS_H


class mathFormulas
{
public:
    mathFormulas();
    mathFormulas(double b1,
                 double b2,
                 double b3,
                 double h1,
                 double h2,
                 double h3,
                 double h4,
                 double h5):
        paramB1(b1),
        paramB2(b2),
        paramB3(b3),
        paramH1(h1),
        paramH2(h2),
        paramH3(h3),
        paramH4(h4),
        paramH5(h5) {};

    double calculateAreaAc();
    double calculateBeta();
    double calculateCenterOfGravity();
    double calculateKappa();
    double calculateSecondMomentOfArea();
    double calculatePerformanceLimitIndicator();

private:
    double paramB1;
    double paramB2;
    double paramB3;
    double paramH1;
    double paramH2;
    double paramH3;
    double paramH4;
    double paramH5;
    double paramS1;
    double paramS2;
    double paramS3;
    double paramS4;
    double paramS5;

    double areaA1;
    double areaA2;
    double areaA3;
    double areaA4;
    double areaA5;
    double areaAc;

    double paramH;
    double paramBeta;
    double paramSc;
    double paramIc;
    double paramRho;
};

int calculateCmin(double cMinB,int cMinDur, double cDurY, double cDurSt, double cDurAdd);

#endif // MATHFORMULAS_H
