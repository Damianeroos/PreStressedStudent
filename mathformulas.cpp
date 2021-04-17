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
