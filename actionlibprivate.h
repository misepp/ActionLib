#ifndef ACTIONLIBPRIVATE_H
#define ACTIONLIBPRIVATE_H

#include <QObject>
#include "actionlib.h"

class ActionLibPrivate : public QObject
{
public:
    explicit ActionLibPrivate();
    ~ActionLibPrivate();

private:
    bool InitializeDB();

public:
    bool createDBConnection();
    bool insertDBData(QString name, int points);
    QVariant readDBData(QString name);
    void CloseDB();

private:

};

#endif // ACTIONLIBPRIVATE_H
