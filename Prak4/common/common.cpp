#include "common.h"

const QChar separator(';');

QString& operator<< (QString& msg, const QString& str)
{
    msg += str;
    msg.append(separator);
    return msg;
}
