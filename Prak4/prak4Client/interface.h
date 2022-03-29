#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class TInterface : public QWidget
{
    Q_OBJECT
private:
    QLabel *lb_a, *lb_delimeter_a;
    QLineEdit *le_aNumerator, *le_aDenominator;

    QLabel *lb_b, *lb_delimeter_b;
    QLineEdit *le_bNumerator, *le_bDenominator;

    QLabel *lb_c, *lb_delimeter_c;
    QLineEdit *le_cNumerator, *le_cDenominator;

    QLabel *lb_x, *lb_delimeter_x;
    QLineEdit *le_xNumerator, *le_xDenominator;

    QPushButton *btn_value, *btn_root, *btn_print_classic, *btn_print_canonic;

    QLabel *lb_output;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
signals:
    void request(QString);
public slots:
    void answer(QString);
private slots:
    void createRequest();
};
#endif // TINTERFACE_H
