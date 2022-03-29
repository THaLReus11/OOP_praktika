#ifndef TPOLINOM_H
#define TPOLINOM_H

#include "number.h"
#include "iostream"
#include "QString"

enum EPrintMode { EPrintCModeClassic, EPrintCModeCannonic};

using namespace std;

class TPolinom
{
private:
    EPrintMode printMode;
    number a, b, c;
public:
    TPolinom(number, number, number);
    number value(number);
    void setPrintMode(EPrintMode);
    number* roots ();
    friend QString& operator<< (QString&, TPolinom&);
};

#endif // TPOLINOM_H
