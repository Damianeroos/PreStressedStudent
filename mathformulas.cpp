#include "mathformulas.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <QDebug>

mathFormulas::mathFormulas()
{

}
double mathFormulas::calculateAreaAc(){
    areaA1 = paramB1*paramH1;
    areaA2 = ((paramB1+paramB3)*paramH2)/2;
    areaA3 = paramB3*paramH3;
    areaA4 = ((paramB2+paramB3)*paramH4)/2;
    areaA5 = paramB2*paramH5;

    areaAc = areaA1+areaA2+areaA3+areaA4+areaA5;
    return areaAc;
}

double mathFormulas::calculateBeta(){
    paramH = paramH1+paramH2+paramH3+paramH4+paramH5;
    return areaAc/(paramH*paramH);
}

double mathFormulas::calculateCenterOfGravity(){
    paramS1 = paramH1/2 +paramH2+paramH3+paramH4+paramH5;
    paramS2 = (paramH2*(paramB3+2*paramB1))/(3*(paramB3+paramB1)) + paramH3+paramH4+paramH5;
    paramS3 = paramH3/2 + paramH4+paramH5;
    paramS4 = (paramH4*(paramB2+2*paramB3))/(3*(paramB2+paramB3)) + paramH5;
    paramS5 = paramH5/2;

    paramSc = (paramS1*areaA1+paramS2*areaA2+paramS3*areaA3+paramS4*areaA4+paramS5*areaA5)/areaAc;

    return paramSc;
}

double mathFormulas::calculateKappa(){
    return paramSc/paramH;
}

double mathFormulas::calculateSecondMomentOfArea(){
    double Ixa1 = (paramB1*pow(paramH1,3))/12;
    double Ixa2 = (pow(paramH2,3)*(pow(paramB1,2)+4*paramB1*paramB3+pow(paramB3,2)))/(36*(paramB1+paramB3));
    double Ixa3 = (paramB3*pow(paramH3,3))/12;
    double Ixa4 = (pow(paramH4,3)*(pow(paramB3,2)+4*paramB3*paramB2+pow(paramB2,2)))/(36*(paramB3+paramB2));
    double Ixa5 = (paramB2*pow(paramH5,3))/12;

    paramIc = Ixa1 + areaA1*pow(std::abs(paramS1-paramSc),2) + Ixa2 + areaA2*pow(std::abs(paramS2-paramSc),2)
            + Ixa3 + areaA3*pow(std::abs(paramS3-paramSc),2) + Ixa4 + areaA4*pow(std::abs(paramS4-paramSc),2)
            + Ixa5 + areaA5*pow(std::abs(paramS5-paramSc),2);

    return paramIc;
}

double mathFormulas::calculatePerformanceLimitIndicator(){
    paramRho = paramIc/(paramSc*areaAc*(paramH-paramSc));
    return paramRho;
}

int calculateCmin(double cMinB, int cMinDur, double cDurY, double cDurSt, double cDurAdd){
    std::vector<double> vec{cMinB, static_cast<double>(cMinDur) - cDurY - cDurSt - cDurAdd, 10.0};
    return static_cast<int>(ceil(*std::max_element(vec.begin(), vec.end())));
}

double mathFormulas::calculateFcd(){
    paramFcd = paramFck / paramGammaFcd;
    return paramFcd;
}

double mathFormulas::calculateFpd(){
    paramFpd = paramFpk / paramGammaFpd;
    return paramFpd;
}

double mathFormulas::calculateZ(){
    paramZ = (paramHp * paramH) / 100;
    return paramZ;
}

int mathFormulas::calculateNpov(){
    paramNpov = static_cast<int>(std::ceil(paramMed / (paramZ * paramApc0 * paramFpd * 1000)));
    return paramNpov;
}

double mathFormulas::calculateAcc(){
    areaApc = (paramNpov  + paramNpovg) * paramApc0;
    areaAcc = areaApc * (paramFpd/paramFcd);
    return areaAcc;
}

double mathFormulas::calculateAlphaE(){
    paramAlphaE = paramEp / (paramEcm * paramK);
    return paramAlphaE;
}

double mathFormulas::calculateAcs(){
    areaAcs = areaAc - areaApc + paramAlphaE * areaApc;
    return areaAcs;
}

double mathFormulas::calculateScs(){
    double temp = (paramAlphaE-1) * paramApc0 * (ApLower + ApUpper);

    paramScs = paramH1S*(paramB1S-paramB3S)*(paramH-(paramH1S/2))+
            paramH2S*(paramB2S-paramB3S)*(paramH2S/2)+
            paramB3S*paramH*(paramH/2)+temp;

    return paramScs;
}

double mathFormulas::calculateZd(){
    paramZd = paramScs/areaAcs;
    return paramZd;
}

double mathFormulas::calculateZg(){
    paramZg = paramH-paramZd;
    return paramZg;
}

double mathFormulas::calculateWdcs()
{
    paramWdcs = paramIcs / paramZd;
    return paramWdcs;
}

double mathFormulas::calculateWgcs()
{
    paramWgcs = paramIcs / paramZg;
    return paramWgcs;
}

double mathFormulas::calculateIcs()
{
    paramIcs = paramIc + areaAc*pow((paramSc - paramZd),2)+(paramAlphaE-1)*paramApc0*sumF2d+paramApc0*sumF2g;
    return paramIcs;
}

double mathFormulas::calculateSigma(double k1, double k2, double fpk, double Fp01k, double Apc0)
{
    paramfp01k = round((Fp01k / Apc0)/1000);
    double temp1 = k1*fpk;
    double temp2 = k2*paramfp01k;

    temp1 < temp2 ? paramSigmapmax = round(temp1) : paramSigmapmax = round(temp2);

    return paramSigmapmax;
}

double mathFormulas::calculateP0max()
{
    return round(areaApc * paramSigmapmax * 1000);
}

double mathFormulas::calculateSigma0(double k7, double k8, double fpk)
{
    double temp1 = k7*fpk;
    double temp2 = k8*paramfp01k;

    temp1 < temp2 ? paramSigmapm0 = round(temp1) : paramSigmapm0 = round(temp2);

    return paramSigmapm0;
}

double mathFormulas::calculatePm0()
{
    return round(areaApc * paramSigmapm0 * 1000);
}

void mathFormulas::calculateTemporaryLosses(double t, double p1000, double fpk)
{
    double u = paramSigmapmax / fpk;
    double pmod = 0.66 * p1000 * pow(EULER, 9.1*u) * pow(t / 1000, 0.75* (1- u)) * 1e-5;

    paramSigmapr1 = pmod * paramSigmapmax;
    paramPpr1 = pmod * calculateP0max();
}

void mathFormulas::calculateTemporaryLosses(double t, double teq, double p1000, double fpk)
{
    double u = paramSigmapmax / fpk;
    double pmod = 0.66 * p1000 * pow(EULER, 9.1*u) * pow((t + teq) / 1000, 0.75* (1- u)) * 1e-5;

    paramSigmapr1 = pmod * paramSigmapmax;
    paramPpr1 = pmod * calculateP0max();
}

double mathFormulas::calculateDeltaPTheta(double dT, double alphaT)
{
    return 0.5 * dT * alphaT * paramEp * areaApc * 1e6;
}
