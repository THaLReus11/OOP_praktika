#include "interface.h"
#include "QString"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Работа №3");
    setFixedSize(300,250);

    lb_a = new QLabel("a = ",this);
    lb_a->setGeometry(50,40,30,25);
    lb_b = new QLabel("b = ",this);
    lb_b->setGeometry(50,70,30,25);
    lb_c = new QLabel("c = ",this);
    lb_c->setGeometry(50,100,30,25);
    lb_x = new QLabel("x = ",this);
    lb_x->setGeometry(50,130,30,25);

    le_aNumerator = new QLineEdit("1",this);
    le_aNumerator->setGeometry(90,40,30,25);
    le_bNumerator = new QLineEdit("2",this);
    le_bNumerator->setGeometry(90,70,30,25);
    le_cNumerator = new QLineEdit("1",this);
    le_cNumerator->setGeometry(90,100,30,25);
    le_xNumerator = new QLineEdit("1",this);
    le_xNumerator->setGeometry(90,130,30,25);

    lb_delimeter_a = new QLabel("/",this);
    lb_delimeter_a->setGeometry(120,40,10,25);
    lb_delimeter_b = new QLabel("/",this);
    lb_delimeter_b->setGeometry(120,70,10,25);
    lb_delimeter_c = new QLabel("/",this);
    lb_delimeter_c->setGeometry(120,100,10,25);
    lb_delimeter_x = new QLabel("/",this);
    lb_delimeter_x->setGeometry(120,130,10,25);

    le_aDenominator = new QLineEdit("1",this);
    le_aDenominator->setGeometry(130,40,30,25);
    le_bDenominator = new QLineEdit("1",this);
    le_bDenominator->setGeometry(130,70,30,25);
    le_cDenominator = new QLineEdit("1",this);
    le_cDenominator->setGeometry(130,100,30,25);
    le_xDenominator = new QLineEdit("1",this);
    le_xDenominator->setGeometry(130,130,30,25);

    btn_value = new QPushButton("Знач.", this);
    btn_value->setGeometry(200,20,60,30);
    btn_root = new QPushButton("Корни", this);
    btn_root->setGeometry(200,60,60,30);
    btn_print_classic = new QPushButton("Класс.", this);
    btn_print_classic->setGeometry(200,100,60,30);
    btn_print_canonic = new QPushButton("Канон.", this);
    btn_print_canonic->setGeometry(200,140,60,30);

    lb_output = new QLabel(this);
    lb_output->setGeometry(30,180,250,60);

    connect(btn_value,SIGNAL(pressed()),this,SLOT(value()));
    connect(btn_print_classic,SIGNAL(pressed()),this,SLOT(print_classic()));
    connect(btn_print_canonic,SIGNAL(pressed()),this,SLOT(print_cannonic()));
    connect(btn_root,SIGNAL(pressed()),this,SLOT(root()));
}

TInterface::~TInterface()
{
    delete lb_a;
    delete le_aNumerator;
    delete lb_delimeter_a;
    delete le_aDenominator;
    delete lb_b;
    delete le_bNumerator;
    delete lb_delimeter_b;
    delete le_bDenominator;
    delete lb_c;
    delete le_cNumerator;
    delete lb_delimeter_c;
    delete le_cDenominator;
    delete lb_x;
    delete le_xNumerator;
    delete lb_delimeter_x;
    delete le_xDenominator;
    delete btn_value;
    delete btn_root;
    delete btn_print_classic;
    delete btn_print_canonic;
    delete lb_output;
}

void TInterface::value()
{
    QString result("");
    if (le_aDenominator->text().toInt()==0 || le_bDenominator->text().toInt()==0 || le_cDenominator->text().toInt()==0 || le_xDenominator->text().toInt()==0)
    {
        result += "Denominator cannot be zero!";
    }
    else
    {
        if (le_aNumerator->text().toInt()==0)
        {
            result += "The coefficient a cannot be zero!";
        }
        else
        {
            number a(le_aNumerator->text().toInt(),le_aDenominator->text().toInt());
            number b(le_bNumerator->text().toInt(),le_bDenominator->text().toInt());
            number c(le_cNumerator->text().toInt(),le_cDenominator->text().toInt());
            TPolinom p(a,b,c);
            number x(le_xNumerator->text().toInt(),le_xDenominator->text().toInt());
            number v = p.value(x);
            result += "p";
            result << x;
            result += "=";
            result << v;
        }
    }
    lb_output->setText(result);
}
void TInterface::print_classic()
{
    QString result("");
    if (le_aDenominator->text().toInt()==0 || le_bDenominator->text().toInt()==0 || le_cDenominator->text().toInt()==0 || le_xDenominator->text().toInt()==0)
    {
        result += "Denominator cannot be zero!";
    }
    else
    {
        if (le_aNumerator->text().toInt()==0)
        {
            result += "The coefficient a cannot be zero!";
        }
        else
        {
            number a(le_aNumerator->text().toInt(),le_aDenominator->text().toInt());
            number b(le_bNumerator->text().toInt(),le_bDenominator->text().toInt());
            number c(le_cNumerator->text().toInt(),le_cDenominator->text().toInt());
            TPolinom p(a,b,c);
            result << p;
        }
    }
    lb_output->setText(result);
}

void TInterface::print_cannonic()
{
    QString result("");
    if (le_aDenominator->text().toInt()==0 || le_bDenominator->text().toInt()==0 || le_cDenominator->text().toInt()==0 || le_xDenominator->text().toInt()==0)
    {
        result += "Denominator cannot be zero!";
    }
    else
    {
        if (le_aNumerator->text().toInt()==0)
        {
            result += "The coefficient a cannot be zero!";
        }
        else
        {
            number a(le_aNumerator->text().toInt(),le_aDenominator->text().toInt());
            number b(le_bNumerator->text().toInt(),le_bDenominator->text().toInt());
            number c(le_cNumerator->text().toInt(),le_cDenominator->text().toInt());
            TPolinom p(a,b,c);
            p.setPrintMode(EPrintCModeCannonic);
            result << p;
        }
    }
    lb_output->setText(result);
}

void TInterface::root()
{
    QString result("");
    if (le_aDenominator->text().toInt()==0 || le_bDenominator->text().toInt()==0 || le_cDenominator->text().toInt()==0 || le_xDenominator->text().toInt()==0)
    {
        result += "Denominator cannot be zero!";
    }
    else
    {
        if (le_aNumerator->text().toInt()==0)
        {
            result += "The coefficient a cannot be zero!";
        }
        else
        {
            number a(le_aNumerator->text().toInt(),le_aDenominator->text().toInt());
            number b(le_bNumerator->text().toInt(),le_bDenominator->text().toInt());
            number c(le_cNumerator->text().toInt(),le_cDenominator->text().toInt());
            TPolinom p(a,b,c);
            number* root = p.roots();
            if(root!=NULL)
            {
                if(root[0]==root[1])
                {
                    result += "The equation has an solution:\nx = ";
                    result << root[0];
                }
                else
                {
                    result += "The equation has two solutions:\nx1 = ";
                    result << root[0];
                    result += "\nx2 = ";
                    result << root[1];
                }

            }
            else
                result += "The equation has no solution!";
            delete[]root;
        }
    }
    lb_output->setText(result);
}

