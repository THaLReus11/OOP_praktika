#include "polinom.h"
#include "math.h"


TPolinom::TPolinom(number a, number b, number c)
{
    this->printMode = EPrintCModeClassic;
    this->a = a;
    this->b = b;
    this->c = c;
}

number TPolinom::value (number x)
{
    return a*x*x + b*x + c;
}

number* TPolinom::roots()
{
    number delta = b*b - 4*a*c;
    if(delta>=0)
    {
        number* xroots = new number[2];
        xroots[0]=(-b+sqrt(delta))/(2*a);
        xroots[1]=(-b-sqrt(delta))/(2*a);
        if(value(xroots[0])==0&&value(xroots[1])==0)
            return xroots;
        if(value(xroots[0])==0)
        {
            xroots[1]=xroots[0];
            return xroots;
        }
        if(value(xroots[1])==0)
        {
            xroots[0]=xroots[1];
            return xroots;
        }
        delete[]xroots;
    }
    return NULL;
}

void TPolinom::setPrintMode (EPrintMode e)
{
    printMode = e;
}

ostream& operator<< (ostream& os, TPolinom& p)
{
    if(p.printMode==EPrintCModeClassic)
        os << "p(x) = " << p.a << "x^2" << (p.b>=0?"+":"") << p.b << "x" << (p.c>=0?"+":"") << p.c;
    else
    {
        number* xroots = p.roots();
        if(xroots!=NULL)
        {
            if(xroots[0]!=xroots[1])
                os << "p(x) = " << p.a << "(x" << (xroots[0]<0?"+":"-") << (xroots[0]<0?-xroots[0]:xroots[0]) << ")(x" << (xroots[1]<0?"+":"-") << (xroots[1]<0?-xroots[1]:xroots[1]) <<")";
            else if(p.b*p.b==4*p.a*p.c)
                os << "p(x) = " << p.a << "(x" << (xroots[0]<0?"+":"-") << (xroots[0]<0?-xroots[0]:xroots[0]) << ")^2";
            else
                os << "Can not output canonical form!" << endl;

        }
        else
            os << "Can not output canonical form!" << endl;
        delete[]xroots;
    }
    return os;
}


//THaLReus11
