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

QString& operator<< (QString& s, TPolinom& p)
{
    if(p.printMode==EPrintCModeClassic)
    {
        s += "p(x) = ";
        s << p.a;
        s += "x^2";
        s += (p.b>=0?"+":"");
        s << p.b;
        s += "x";
        s += (p.c>=0?"+":"");
        s << p.c;
    }
    else
    {
        number* xroots = p.roots();
        if(xroots!=NULL)
        {
            if(xroots[0]!=xroots[1])
            {
                s += "p(x) = ";
                s << p.a;
                s += "(x";
                s += (xroots[0]<0?"+":"-");
                s << (xroots[0]<0?-xroots[0]:xroots[0]);
                s += ")(x";
                s += (xroots[1]<0?"+":"-");
                s << (xroots[1]<0?-xroots[1]:xroots[1]);
                s += ")";
            }
            else if(p.b*p.b==4*p.a*p.c)
            {
                s += "p(x) = ";
                s << p.a;
                s += "(x";
                s += (xroots[0]<0?"+":"-");
                s << (xroots[0]<0?-xroots[0]:xroots[0]);
                s += ")^2";
            }
            else
                s += "Can not output canonical form!\n";

        }
        else
            s += "Can not output canonical form!\n";
        delete[]xroots;
    }
    return s;
}

