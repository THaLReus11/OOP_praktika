#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QObject>
#include <QCoreApplication>
#include "communicator.h"
#include "polinom.h"

class TApplication : public QCoreApplication
{
    Q_OBJECT
    TCommunicator *comm;
public:
    TApplication(int, char**);
public slots:
    void receive(QByteArray);
};

#endif // TAPPLICATION_H
