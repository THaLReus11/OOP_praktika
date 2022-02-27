#include "application.h"
#include "number.h"
#include "iostream"
#include "polinom.h"

using namespace std;

TApplication::TApplication()
{

}

int TApplication::exec()
{
    int ch;
    number a =1, b=2, c=1;
    while(true)
    {
        ch = menu();
        switch (ch)
        {
            case 1:
            {
                do
                {
                    cout << "a = ";
                    cin >> a;
                    cout << "b = ";
                    cin >> b;
                    cout << "c = ";
                    cin >> c;

                    if(a==0)
                        cout << "Value of 'a' cannot be 0! Enter coefficients a!" << endl;
                }while(a==0);
            }
                break;
            case 2:
            {
                number x;
                cout << "x = ";
                cin >> x;
                TPolinom p(a,b,c);
                cout << "p(" << x << ") = " << p.value(x) << endl;
            }
                break;
            case 3:
            {
                TPolinom p(a,b,c);
                number* result = p.roots();
                if(result!=NULL)
                {
                    if(result[0]==result[1])
                    {
                        cout << "the equation has an solution: x = " << result[0]<< endl;
                    }
                    else
                    {
                        cout << "the equation has two solutions: x1 = " << result[0] << "; x2 = " << result[1] << endl;
                    }

                }
                else
                    cout << "the equation has no solution!" << endl;

                delete[]result;
            }
                break;
            case 4:
            {
                TPolinom p(a,b,c);
                cout << p << endl;
            }
                break;
            case 5:
            {
                TPolinom p(a,b,c);
                p.setPrintMode(EPrintCModeCannonic);
                cout << p << endl;
            }
                break;
            case 0:
                return 0;
                break;
            default:
                cout << "No command for this input. Enter number from 0 to 5" << endl;
                break;
        }
    }
    return 0;
}

int TApplication::menu()
{
    int ch;
    cout << "1 - enter coefficients" << endl;
    cout << "2 - calculate value polinom" << endl;
    cout << "3 - find roots" << endl;
    cout << "4 - print polinom (classic form)" << endl;
    cout << "5 - print polinom (canonical form)" << endl;
    cout << "0 - exit" << endl << "> ";
    cin >> ch;
    return ch;
}
