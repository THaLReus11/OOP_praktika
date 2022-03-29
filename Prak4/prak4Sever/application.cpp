#include "application.h"
#include "number.h"
#include "common.h"

TApplication::TApplication(int argc, char* argv[]) : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000, QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(received(QByteArray)),this,SLOT(receive(QByteArray)));
}

void TApplication::receive(QByteArray msg)
{
    QString answer, s;
    number a,b,c,x,v;
    msg >> a >> b >> c;
    TPolinom p(a,b,c);
    int pos = msg.indexOf(separator);
    int t = msg.left(pos).toInt();
    switch (t) {
    case VALUE_REQUEST:
    {
        if (a.get_b()==0||b.get_b()==0||c.get_b()==0)
        {
            s << "Denominator can't be 0. Reenter.";
            answer << QString().setNum(ERROR);
        }
        else
        {
            if (a.get_a()==0)
            {
                s << "Value of 'a' cant be 0! Reenter!";
                answer << QString().setNum(ERROR);
            }
            else
            {
                msg = msg.right(msg.length()-pos-1);
                msg >> x;
                v = p.value(x);
                s << (QString)x << (QString)v;
                answer << QString().setNum(VALUE_ANSWER);
            }
        }
        answer += s;
        break;
    }
    case PRINT_CLASSIC_REQUEST:
    {
        if (a.get_b()==0||b.get_b()==0||c.get_b()==0)
        {
            s += "Denominator can't be 0. Reenter.";
            answer << QString().setNum(ERROR);
        }
        else
        {
            if (a.get_a()==0)
            {
                s += "Value of 'a' cant be 0! Reenter!";
                answer << QString().setNum(ERROR);
            }
            else
            {
                p.setPrintMode(EPrintCModeClassic);
                s<<p;
                answer << QString().setNum(PRINT_ANSWER);
            }
        }
        answer << s;
        break;
    }
    case PRINT_CANONIC_REQUEST:
    {
        if (a.get_b()==0||b.get_b()==0||c.get_b()==0)
        {
            s += "Denominator can't be 0. Reenter.";
            answer << QString().setNum(ERROR);
        }
        else
        {
            if (a.get_a()==0)
            {
                s += "Value of 'a' cant be 0! Reenter!";
                answer << QString().setNum(ERROR);
            }
            else
            {
                p.setPrintMode(EPrintCModeCannonic);
                s<<p;
                answer << QString().setNum(PRINT_ANSWER);
            }
        }
        answer << s;
        break;
    }
    case ROOT_REQUEST:
    {
        if (a.get_b()==0||b.get_b()==0||c.get_b()==0)
        {
            s << "Denominator can't be 0. Reenter. ";
            answer << QString().setNum(ERROR);
        }
        else
        {
            if (a.get_a()==0)
            {
                s << "Value of 'a' cant be 0! Reenter!";
                answer << QString().setNum(ERROR);
            }
            else
            {
                number* roots = p.roots();
                if (roots != NULL )
                {
                    if(roots[0]==roots[1])
                    {
                        s << QString().setNum(1);
                        s << (QString)roots[0];
                    }
                    else
                    {
                        s << QString().setNum(2);
                        s << (QString)roots[0] << (QString)roots[1];
                    }
                }
                else
                    s << QString().setNum(0);
                delete[]roots;
                answer << QString().setNum(ROOT_ANSWER);
            }
        }
        answer += s;
        break;
    }
    default:
        break;
    }
    comm->send(QByteArray().append(answer));
}
