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
                 double h5,
                 double fck,
                 double gammaFcd,
                 double fpk,
                 double gammaFpd,
                 int Hp,
                 double Med,
                 double Apc0,
                 int Npovg,
                 double Ep,
                 double Ecm,
                 double k,
                 double b1s,
                 double b2s,
                 double b3s,
                 double h1s,
                 double h2s,
                 double h3s) :

        paramB1(b1),
        paramB2(b2),
        paramB3(b3),
        paramH1(h1),
        paramH2(h2),
        paramH3(h3),
        paramH4(h4),
        paramH5(h5),
        paramFck(fck),
        paramGammaFcd(gammaFcd),
        paramFpk(fpk),
        paramGammaFpd(gammaFpd),
        paramHp(Hp),
        paramMed(Med),
        paramApc0(Apc0),
        paramNpovg(Npovg),
        paramEp(Ep),
        paramEcm(Ecm),
        paramK(k),
        paramB1S(b1s),
        paramB2S(b2s),
        paramB3S(b3s),
        paramH1S(h1s),
        paramH2S(h2s),
        paramH3S(h3s) {};

    double calculateAreaAc();
    double calculateBeta();
    double calculateCenterOfGravity();
    double calculateKappa();
    double calculateSecondMomentOfArea();
    double calculatePerformanceLimitIndicator();
    double calculateFcd();
    double calculateFpd();
    double calculateZ();
    int calculateNpov();
    double calculateAcc();
    double calculateAlphaE();
    double calculateAcs();

    const double& getA1() {return areaA1;}

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

    double paramFck;
    double paramGammaFcd;
    double paramFpk;
    double paramGammaFpd;
    int paramHp;
    double paramMed;
    double paramApc0;
    int paramNpovg;

    double paramFcd;
    double paramFpd;
    double paramZ;
    int paramNpov;
    double areaAcc;
    double areaApc;

    double paramEp;
    double paramEcm;
    double paramK;
    double paramAlphaE;
    double areaAcs;

    double paramB1S;
    double paramB2S;
    double paramB3S;
    double paramH1S;
    double paramH2S;
    double paramH3S;
};

int calculateCmin(double cMinB,int cMinDur, double cDurY, double cDurSt, double cDurAdd);

#endif // MATHFORMULAS_H
