#ifndef TRATIONAL_H
#define TRATIONAL_H

#include "iostream"
#include "math.h"
#include "QString"

using namespace std;

class TRational
{
private:
    int a,b;
    int GCD();
    void Reduce();
    static QChar SEPARATOR;
public:
    TRational();
    TRational(const int&, const int&);
    TRational(const int&);
    TRational(const QByteArray&);

    friend TRational operator* (const TRational&, const TRational&);
    TRational operator+ (const TRational&);
    TRational operator- (const TRational&);
    TRational operator- ();
    TRational operator/ (const TRational&);
    friend TRational sqrt(const TRational&);

    static void setSeparator(QChar);

    bool operator==(const TRational&);
    bool operator>= (const TRational&);
    bool operator< (const TRational&);
    bool operator!= (const TRational&);

    friend QByteArray& operator>> (QByteArray&, TRational&);
    friend QString& operator<< (QString&, TRational);
    operator QString ();

    int get_a ();
    int get_b ();
};

#endif // TRATIONAL_H
