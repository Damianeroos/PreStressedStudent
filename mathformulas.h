#ifndef MATHFORMULAS_H
#define MATHFORMULAS_H

#define EULER 2.7182818284

#include <vector>

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
                 double h3s,
                 int    rh,
                 int    tStart,
                 int    tEnd,
                 double aDS1,
                 double aDS2) :

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
        paramH3S(h3s),
        paramRH(rh),
        paramTStart(tStart),
        paramTEnd(tEnd),
        paramAlphaDS1(aDS1),
        paramAlphaDS2(aDS2){};

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
    void setApLower(double arg){ ApLower = arg;}
    void setApUpper(double arg){ ApUpper = arg;}
    const double& getA1() {return areaA1;}
    const double& getH() {return paramH;}
    double calculateScs();
    double calculateZd();
    double calculateZg();
    double getZd() const { return paramZd;}
    double getZg() const { return paramZg;}
    void setSumF2d(double arg){ sumF2d = arg;}
    void setSumF2g(double arg){ sumF2g = arg;}
    void setSumF3d(double arg){ sumF3d = arg;}
    void setSumF3g(double arg){ sumF3g = arg;}
    double calculateWdcs();
    double calculateWgcs();
    double calculateIcs();
    double calculateSigma(double k1, double k2, double fpk, double Fp01k, double Apc0);
    double calculateP0max();
    double calculateSigma0(double k7, double k8, double fpk);
    double calculatePm0();
    void calculateTemporaryLosses(double t, double p1000, double fpk);
    void calculateTemporaryLosses(double t, double teq, double p1000, double fpk);
    double getDeltaSigma() const {return paramSigmapr1;}
    double getDeltaP() const {return paramPpr1;}
    double calculateDeltaPTheta(double dT, double alphaT);
    double calculatePm01();
    double calculatePm02();
    double calculateDeltaPel();
    double calculateSigmaPm02();
    void setU(double arg){ paramU = arg;}
    double calculateH0();
    double calculateFcm();
    std::vector<double> calculateParametersA();
    double calculateBetaH();
    std::vector<double> calculateBetas();
    std::vector<double> calculatePhis();
    double calculatePhiRH();
    std::vector<double> calculateEpsilons(double fcmo, double kh);
    std::vector<double> calculateSigmas(double Meqp, double p1000);

private:
    enum a {a1, a2, a3};
    enum beta {bH, bC, bT0, bFcm, bRH, bAS};
    enum phi {pRH, p0, p0T};

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

    double ApLower; //( li * ai)
    double ApUpper; // li * (h-ai)
    double paramScs;
    double paramZd;
    double paramZg;
    double paramIcs;
    double paramWdcs;
    double paramWgcs;
    double sumF2d; // SUM(li*(z-ai)^2)
    double sumF2g; // SUM(li*(z-ai)^2)

    double paramSigmapmax;
    double paramfp01k;
    double paramSigmapm0;

    double paramSigmapr1;
    double paramPpr1;

    double paramDeltaPTheta;
    double paramPm01;
    double paramPm02;
    double sumF3d; // SUM(li*(z-ai))
    double sumF3g; // SUM(li*(z-ai))
    double paramDeltaPel;
    double paramZpc;

    double paramU;
    double paramH0;
    double paramFcm;
    std::vector<double> paramsA;
    std::vector<double> paramsBeta;
    int paramRH;
    int paramTStart;
    int paramTEnd;
    std::vector<double> paramsPhis;
    double paramAlphaDS1;
    double paramAlphaDS2;
    std::vector<double> paramsEpsilons;

    std::vector<double> paramsSigmas;

};

int calculateCmin(double cMinB,int cMinDur, double cDurY, double cDurSt, double cDurAdd);

#endif // MATHFORMULAS_H
