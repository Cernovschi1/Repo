#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H
#include<iostream>
#include<cmath>
class complexz
{
private:
    double imagT,realT;
public:

    complexz();
    complexz(double r,double i);
    void show_comp1();
    double getReal();
    double getImag();
    complexz add(complexz elem);
    complexz mult(complexz elem);
    complexz quot(complexz elem);
    double abs();
    void compute_polar();
    friend bool operator<(complexz c1, complexz c2);
};
#endif
