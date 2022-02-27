#ifndef TRATIONAL_H
#define TRATIONAL_H

#include "iostream"
#include "math.h"

using namespace std;

class TRational
{
private:
    int a,b;
    int GCD();
    void Reduce();
public:
    TRational();
    TRational(const int&, const int&);
    TRational(const int&);

    friend TRational operator* (const TRational&, const TRational&);
    TRational operator+ (const TRational&);
    TRational operator- (const TRational&);
    TRational operator- ();
    TRational operator/ (const TRational&);
    friend TRational sqrt(const TRational&);

    bool operator==(const TRational&);
    bool operator>= (const TRational&);
    bool operator< (const TRational&);
    bool operator!= (const TRational&);

    friend ostream& operator<< (ostream&, TRational);
    friend istream& operator>> (istream&, TRational&);
};

#endif // TRATIONAL_H
