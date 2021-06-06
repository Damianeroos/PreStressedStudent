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
    paramDeltaPTheta = 0.5 * dT * alphaT * paramEp * areaApc * 1e6;
    return paramDeltaPTheta;
}

double mathFormulas::calculatePm01()
{
    paramPm01 = calculateP0max() - paramPpr1 - paramDeltaPTheta;
    return  paramPm01;
}

double mathFormulas::calculateDeltaPel()
{
    double rhoRho = areaApc / areaAcs;
    paramZpc = (paramApc0 * (sumF3d - sumF3g)) / areaApc;

    paramDeltaPel = paramAlphaE * rhoRho * (1 + pow(paramZpc,2)* (areaAcs/paramIcs)) * paramPm01;

    return paramDeltaPel;
}

double mathFormulas::calculatePm02()
{
    paramPm02 = paramPm01 - paramDeltaPel;
    return  paramPm02;
}

double mathFormulas::calculateSigmaPm02()
{
    paramSigmaPM02 = (paramPm02 * 0.001) / areaApc;
    return  paramSigmaPM02;
}

double mathFormulas::calculateH0()
{
    paramH0 = ((2*areaAc) / paramU) * 1000;
    return paramH0;
}

double mathFormulas::calculateFcm()
{
    paramFcm = paramFck + 8;
    return paramFcm;
}

std::vector<double> mathFormulas::calculateParametersA()
{
    std::vector<double> a(3, 0.0);

    a[0] = pow(35/paramFcm, 0.7);
    a[1] = pow(35/paramFcm, 0.2);
    a[2] = pow(35/paramFcm, 0.5);

    paramsA = a;

    return paramsA;
}

double mathFormulas::calculateBetaH()
{
    double temp1, result;
    double rh = static_cast<double>(paramRH);

    if(paramFcm <= 35){
        temp1 = 1.5 * (1 + pow(0.012 * rh, 18)) * paramH0 + 250;
        temp1 < 1500 ? result = temp1 : result = 1500;
    }
    else{
        temp1 = 1.5 * (1 + pow(0.012 * rh, 18)) * paramH0 + 250 * paramsA[a3];
        temp1 < 1500*paramsA[a3] ? result = temp1 : result = 1500*paramsA[a3];
    }

    return result;
}

std::vector<double> mathFormulas::calculateBetas()
{
    std::vector<double> beta(6, 0.0);

    beta[bH] = calculateBetaH();

    int dT = paramTEnd - paramTStart;
    beta[bC] = pow(dT/(beta[bH] + dT), 0.3);

    beta[bT0] = 1/(0.1+pow(paramTStart, 0.2));

    beta[bFcm] = 16.8/pow(paramFcm, 0.5);

    beta[bRH] = 1.55*(1-pow(static_cast<double>(paramRH)/100,3));

    beta[bAS] = 1 - pow(EULER, -0.2*pow(dT,0.5));

    paramsBeta = beta;
    return paramsBeta;
}

double mathFormulas::calculatePhiRH(){
    double phiRH;
    double rh = static_cast<double>(paramRH);

    if(paramFcm <= 35){
        phiRH = 1 + ((1 - rh/100)/(0.1*pow(paramH0,0.33333)))*paramsA[a1];
    }
    else{
        phiRH = (1 + ((1 - rh/100)/(0.1*pow(paramH0,0.33333)))*paramsA[a1])*paramsA[a2];
    }

    return phiRH;
}

std::vector<double> mathFormulas::calculateEpsilons(double fcmo, double kh)
{
    std::vector<double> eps(5, 0.0);

    eps[0] = 0.85*(220+110*paramAlphaDS1)*pow(EULER,-paramAlphaDS2*paramFcm/fcmo)*paramsBeta[bRH]*1e-6;
    eps[1] = kh*eps[0];
    eps[2] = 2.5*(paramFck-10)*1e-6;
    eps[3] = paramsBeta[bAS]*eps[2];
    eps[4] = eps[1]+eps[3];

    paramsEpsilons = eps;
    return paramsEpsilons;
}

std::vector<double> mathFormulas::calculateSigmas(double Meqp, double P1000)
{
    std::vector<double> sigma(5, 0.0);

    sigma[0] = abs(-paramPm02/areaApc - (paramAlphaE*Meqp*paramZpc)/paramIcs);
    sigma[0] = sigma[0]/1000; //from kPa to MPa

    double t = 500000;
    double u = sigma[0]/paramFpk;
    double pmod = 0.66 * P1000 * pow(EULER, 9.1*u) * pow(t / 1000, 0.75* (1- u)) * 1e-5;

    sigma[1] = pmod*sigma[0]-paramSigmapr1;

    sigma[2] = paramPm02/areaAcs + (paramPm02*pow(paramZpc,2))/paramIcs - (Meqp*paramZpc)/paramIcs;
    sigma[2] = sigma[2]/1000; //from kPa to MPa


    double l = (paramsEpsilons[4]*paramEp*1000+0.8*sigma[1]+paramAlphaE*paramsPhis[p0T]*sigma[2]);
    double m = 1+paramAlphaE*(areaApc/areaAc)*(1+areaAc/paramIc*pow(paramZpc,2))*(1+0.8*paramsPhis[p0T]);
    sigma[3] = l/m;

    calculatePcsr(sigma[3]);
    calculatePmt();

    sigma[4] = paramPmt/areaApc/1000;

    paramsSigmas = sigma;
    return paramsSigmas;
}

double mathFormulas::calculatePcsr()
{
    paramPcsr = paramsSigmas[3]*areaApc*1000;
    return paramPcsr;
}

double mathFormulas::calculatePcsr(double sigmaPCSR)
{
    paramPcsr = sigmaPCSR*areaApc*1000;
    return paramPcsr;
}

double mathFormulas::calculatePmt()
{
    paramPmt = paramPm02 - paramPcsr;
    return paramPmt;
}

std::vector<double> mathFormulas::calculateXs(double Xi, double ad, double ag, double areaApLower, double areaApUpper)
{
    std::vector<double> x(3, 0.0);

    x[0] = (paramFpd*areaApc)/(paramFcd*paramB1S);

    if(x[0] <= paramH1S){
        x[1] = x[0];
    }
    else{
        double l = paramFpd*areaApLower-paramFcd*paramH1S*(paramB1S-paramB3S)-areaApUpper*(400-paramSigmaPM02);
        x[1] = l / (paramB3S*paramFcd);
    }

    double d = paramH1S+paramH2S+paramH3S-(ad+ag);

    x[2] = d*Xi;

    paramMrd = (paramB1S-paramB3S)*paramH1S*paramFcd*(d-0.5*paramH1S)+paramB3S*x[1]*paramFcd*(d-0.5*x[1])+
            areaApUpper*(400-paramSigmaPM02)*(d-ag);

    paramMrd *= 1000;

    paramsXs = x;
    return paramsXs;
}

std::pair<double, double> mathFormulas::calculatePk(double rSup, double rInf)
{
    std::pair<double, double> p;

    p.first = rSup*paramPmt;
    p.second = rInf*paramPmt;

    paramsPk = p;
    return paramsPk;
}

double mathFormulas::calculateEceff()
{
    paramEceff = paramEcm/(1+paramsPhis[p0T]);
    return paramEceff;
}

double mathFormulas::calculateB()
{
    paramB = paramEceff*paramIcs*1000;
    return paramB;
}

std::pair<double, double> mathFormulas::calculateA(double Meqp_2, double leff)
{
    std::pair<double, double> a;

    a.first = (5.0/48.0)*(Meqp_2/1000)*pow(leff,2)*(1.0/paramB)-(1.0/8.0)*(paramsPk.second/1000)*paramZpc*pow(leff,2)*(1.0/paramB);
    a.first *= 1000;
    a.second = leff/250;
    a.second *= 1000;

    return a;
}

double mathFormulas::calculateSigmaCpinf()
{
    paramSigmaCpinf = paramsPk.second/areaAcs + (paramsPk.second*paramZpc*paramZd)/paramIcs;
    paramSigmaCpinf /= 1000;
    return paramSigmaCpinf;
}

double mathFormulas::calculateMcr(double fctm)
{
    return ((paramIcs/paramZd)*(paramSigmaCpinf+fctm))*1000;
}

std::vector<double> mathFormulas::calculateStressesInSection_1(double Meqp)
{
    std::vector<double> css(3, 0.0);

    css[0] = 0.7*0.8*paramFck;
    css[1] = paramsPk.first/areaAcs+(paramsPk.first*paramZpc*paramZd)/paramIcs;
    css[1] /= 1000;
    css[2] = paramsPk.first/areaAcs-(paramsPk.first*paramZpc*paramZg)/paramIcs+(Meqp*paramZg)/paramIcs;
    css[2] /= 1000;

    return css;
}

std::vector<double> mathFormulas::calculateStressesInSection_2(double Meqp, double fctm)
{
    std::vector<double> css(3, 0.0);

    css[0] = 0.7*0.8*fctm;
    css[1] = paramsPk.first/areaAcs-(paramsPk.first*paramZpc*paramZg)/paramIcs;
    css[1] /= 1000;
    css[2] = paramsPk.first/areaAcs+(paramsPk.first*paramZpc*paramZd)/paramIcs-(Meqp*paramZd)/paramIcs;
    css[2] /= 1000;

    return css;
}

std::vector<double> mathFormulas::calculateStressesInSection_3(double Meqp)
{
    std::vector<double> css(3, 0.0);

    css[0] = 0.45*paramFck;
    css[1] = paramsPk.first/areaAcs+(paramsPk.first*pow(paramZpc,2))/paramIcs;
    css[1] /= 1000;
    css[2] = paramsPk.first/areaAcs-(paramsPk.first*paramZpc*paramZg)/paramIcs+(Meqp*paramZg)/paramIcs;
    css[2] /= 1000;

    return css;
}

std::vector<double> mathFormulas::calculatePhis()
{
    std::vector<double> phi(3, 0.0);

    phi[pRH] = calculatePhiRH();
    phi[p0] = phi[pRH]*paramsBeta[bFcm]*paramsBeta[bT0];
    phi[p0T] = phi[p0]*paramsBeta[bC];

    paramsPhis = phi;
    return paramsPhis;
}



