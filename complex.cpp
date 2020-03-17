
#include "complex.h"
complexz::complexz()
{
    this->realT=0;
    this->imagT=0;
}
//constructorul cu 2 parametrii
complexz::complexz(double r,double i)
{
    this->realT=r;
    this->imagT=i;
}

//getter pentru partea reala
double complexz::getReal()
{
    return realT;
}

//getter pentru partea imaginara
double complexz::getImag()
{
    return imagT;
}

//afisarea numarului complex in forma a+bi
void complexz::show_comp1()
{
    if(imagT<0)
        std::cout<<realT<<imagT<<"i";
    else
        std::cout<<realT<<"+"<<imagT<<"i";
}

//functia pentru adunarea numerelor complexe
complexz complexz::add(complexz other)
{
    return complexz(realT+other.realT,imagT+other.imagT);
}

//functia pentru inmultirea numerelor complexe
complexz complexz::mult(complexz other)
{
    return complexz(realT*other.realT-imagT*other.imagT,realT*other.imagT+other.realT*imagT);
}

//functia pentru impartirea numerelor complexe
complexz complexz::quot(complexz other)
{
    if (!other.realT or !other.imagT) throw "Division by zero!";
    return complexz((realT*other.realT+imagT*other.realT)/(other.realT*other.realT+other.imagT*other.imagT), (other.realT*imagT-realT*other.imagT)/(other.realT*other.realT+other.imagT*other.imagT));
}

//functia de calcul a modulului numerelor complexe
double complexz::abs()
{
    return sqrt(realT * realT + imagT * imagT );
}

//calcularea formei polare a unui numar
void complexz::compute_polar()
{
    double abs = this->abs();
    std::cout << abs << "("<< realT / abs  << " + i * " << imagT / abs << ")" << '\n';
}

//implementarea operatorului <
bool operator<(complexz c1, complexz c2)
{
    return ( c1.abs() < c2.abs() );
}
