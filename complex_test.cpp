#include "complex_test.h"
#include "complex.h"

//teste pentru adunarea numerelor complexe
void addTest()
{
    complexz aux(1,1);

    aux = aux.add(complexz(2,1));
    assert(aux.getReal() == 3);
    assert(aux.getImag() == 2);
    aux=aux.add(complexz(1.5,2));
    assert(aux.getReal()==4.5);
    assert(aux.getImag()==4);
}

//teste pentru inmultirea numerelor complexe
void multTest()
{
    complexz aux(1,3);
    aux=aux.mult(complexz(2,1));
    assert(aux.getReal()==-1);
    assert(aux.getImag()==7);
}

//teste pentru impartirea numerelor complexe
void quotTest()
{
    complexz aux(3,4);
    aux=aux.quot(complexz(1,1));
    assert(aux.getReal()==3.5);
    assert(aux.getImag()==0.5);

    //handling pentru exceptia DivisionByZero
    bool exceptionThrown = false;
    try
    {
        aux = aux.quot(complexz(0,0));
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown == true);
}

//teste pentru calculul modulului unui numar complex
void absTEst()
{
    complexz aux(3,4);
    assert(aux.abs()==5);
}

void run_all_tests()
{
    addTest();
    multTest();
    quotTest();
    absTEst();
}
