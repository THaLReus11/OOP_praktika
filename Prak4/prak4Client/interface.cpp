#include "interface.h"
#include "QString"
#include "common.h"

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

    connect(btn_value,SIGNAL(pressed()),this,SLOT(createRequest()));
    connect(btn_print_classic,SIGNAL(pressed()),this,SLOT(createRequest()));
    connect(btn_print_canonic,SIGNAL(pressed()),this,SLOT(createRequest()));
    connect(btn_root,SIGNAL(pressed()),this,SLOT(createRequest()));
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

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t) {
    case VALUE_ANSWER:
        text = "p(";
        p = msg.indexOf(separator);
        text += msg.left(p);
        text += ") = ";
        text += msg.right(msg.length()-p-1);
        lb_output->setText(text);
        break;
    case ERROR:
        text = msg;
        lb_output->setText(text);
        break;
    case ROOT_ANSWER:
    {
        p = msg.indexOf(separator);
        int k = msg.left(p).toInt();
        if (k==0)
        {
            text += "The equation has no solution!";
        }
        if (k==1)
        {
            text += "The equation has an solution:\nx = ";
            text += msg.right(msg.length()-p-1);
        }
        if (k==2)
        {
            text += "The equation has two solutions:\nx1 = ";
            msg = msg.right(msg.length()-p-1);
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += "\nx2 = ";
            text += msg.right(msg.length()-p-1);
        }
        lb_output->setText(text);
        break;
    }
    case PRINT_ANSWER:
        text = msg;
        lb_output->setText(text);
        break;
    default:
        break;
    }
}

void TInterface::createRequest()
{
    QString msg;
    msg << le_aNumerator->text() << le_aDenominator->text();
    msg << le_bNumerator->text() << le_bDenominator->text();
    msg << le_cNumerator->text() << le_cDenominator->text();
    QPushButton *btn = (QPushButton*)sender();
    if (btn == btn_value)
    {
        msg << QString().setNum(VALUE_REQUEST);
        msg << le_xNumerator->text() << le_xDenominator->text();
    }
    if(btn == btn_print_classic)
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    if(btn == btn_print_canonic)
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
    if(btn == btn_root)
        msg << QString().setNum(ROOT_REQUEST);
    emit request(msg);
}
