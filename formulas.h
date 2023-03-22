#ifndef FORMULAS_H
#define FORMULAS_H

#include <QDebug>
#include <doubleP.h>

template <class T>
class formulas
{
public:
    formulas();
    formulas(T b1,
             T b2,
             T b3,
             T h1,
             T h2,
             T h3,
             T h4,
             T h5):
        paramB1(b1),
        paramB2(b2),
        paramB3(b3),
        paramH1(h1),
        paramH2(h2),
        paramH3(h3),
        paramH4(h4),
        paramH5(h5) {};

    T calculateAreaAc();

private:
    T paramB1;
    T paramB2;
    T paramB3;
    T paramH1;
    T paramH2;
    T paramH3;
    T paramH4;
    T paramH5;

    T areaA1;
    T areaA2;
    T areaA3;
    T areaA4;
    T areaA5;
    T areaAc;

    T paramH;
};

template <class T>
T formulas<T>::calculateAreaAc(){
    qInfo()<< "B2: " << paramB2.get();

    areaA1 = paramB1*paramH1;
          qInfo()<< "B2: " << paramB2.get();
    areaA2 = ((paramB1+paramB3)*paramH2)/2;
          qInfo()<< "B2: " << paramB2.get();
    areaA3 = paramB3*paramH3;
          qInfo()<< "B2: " << paramB2.get();
    areaA4 = ((paramB2+paramB3)*paramH4)/2;
          qInfo()<< "B2: " << paramB2.get();
    areaA5 = paramB2*paramH5;
    qInfo()<< "A1: " << areaA1.get();

    qInfo()<< "A2: " << areaA2.get();

    qInfo()<< "A3: " << areaA3.get();
    qInfo()<< "A4: " << areaA4.get();
    qInfo()<< "B2: " << paramB2.get();

    areaAc = areaA1+areaA2+areaA3+areaA4+areaA5;
    return areaAc;
}


#endif // FORMULAS_H
