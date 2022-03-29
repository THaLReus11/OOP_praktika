#include "rational.h"
#include "common.h"

QChar TRational::SEPARATOR = separator;

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

QString& operator<< (QString& s, TRational q)
{
    if (q<0)
    {
        s += "-(";
        s += QString().setNum(-q.a);
        s += "/";
        s += QString().setNum(q.b);
        s += ")";
    }
    else
    {
        s += "(";
        s += QString().setNum(q.a);
        s += "/";
        s += QString().setNum(q.b);
        s += ")";
    }
    return s;
}

TRational::TRational(const QByteArray& arr)
{
    int p = arr.indexOf(TRational::SEPARATOR);
    a = arr.left(p).toInt();
    b = arr.right(arr.length()-p-1).toInt();
    this->Reduce();
}

QByteArray& operator>> (QByteArray& arr, TRational& q)
{
    int p = arr.indexOf(TRational::SEPARATOR);
    p = arr.indexOf(TRational::SEPARATOR,p+1);
    if(p>0)
    {
        q = TRational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

TRational::operator QString ()
{
    QString s;
    if (*this<0)
    {
        s += "-(";
        s += QString().setNum(-a);
        s += "/";
        s += QString().setNum(b);
        s += ")";
    }
    else
    {
        s += "(";
        s += QString().setNum(a);
        s += "/";
        s += QString().setNum(b);
        s += ")";
    }
    return s;
}

void TRational::setSeparator(QChar ch)
{
    SEPARATOR = ch;
}

int TRational::get_a ()
{
    return a;
}

int TRational::get_b ()
{
    return b;
}
