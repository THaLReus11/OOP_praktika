#include "rational.h"

TRational::TRational()
{

}

TRational::TRational(const int& a, const int& b)
{
    this->a=a;
    this->b=b;
    this->Reduce();
}

TRational::TRational(const int& a)
{
    this->a=a;
    this->b=1;
}

int TRational::GCD()
{
    int x=a, y=b;
    while(y!=0)
    {
        int p = y;
        y=x%y;
        x=p;
    }
    return x;
}

void TRational::Reduce()
{
    int k=GCD();
    a/=k;
    b/=k;
    if(b<0)
    {
        b=-b;
        a=-a;
    }
}

TRational operator* (const TRational& q, const TRational& p)
{
    TRational result(q.a*p.a,q.b*p.b);
    return result;
}

TRational TRational::operator- (const TRational& p)
{
    TRational result(a*p.b-p.a*b, b*p.b);
    return result;
}

TRational TRational::operator+ (const TRational& p)
{
    TRational result (a*p.b+p.a*b,b*p.b);
    return result;
}

TRational TRational::operator- ()
{
    TRational result (-a,b);
    return result;
}

TRational TRational::operator/ (const TRational& p)
{
    TRational result (a*p.b, b*p.a);
    return result;
}

bool TRational::operator==(const TRational& p)
{
    return (a==p.a)&&(b==p.b);
}

bool TRational::operator>= (const TRational& p)
{
    return ((a*p.b-p.a*b)>=0);
}

bool TRational::operator!= (const TRational& p)
{
    return (a!=p.a)||(b!=p.b);
}

bool TRational::operator< (const TRational& p)
{
    return ((a*p.b-p.a*b)<0);
}

TRational sqrt (const TRational& p)
{
    TRational result(sqrt(p.a), sqrt(p.b));
    return result;
}

ostream& operator<< (ostream& os, TRational q)
{
    if (q<0)
        os << "-(" <<-q.a << "/" << q.b << ")";
    else
        os << "(" << q.a << "/" << q.b << ")";
    return os;
}

istream& operator>> (istream& is, TRational& q)
{
    char ch;
    is >> q.a >> ch >> q.b;
    while(ch != '/')
    {
        cout << "Enter in format a/b: ";
        is >> q.a >> ch >> q.b;
    }
    while(q.b==0)
    {
        cout << "Denominator cant be 0. Reenter: ";
        is >> q.a >> ch >> q.b;
        while (ch != '/')
        {
            cout << "Enter in format a/b: ";
            is >> q.a >> ch >> q.b;
         }
    }
    q.Reduce();
    return is;
}

