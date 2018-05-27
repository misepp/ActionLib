#ifndef ACTIONLIBPRIVATE_H
#define ACTIONLIBPRIVATE_H

#include <QObject>
#include "actionlib.h"

class ActionLibPrivate
{
public:
    explicit ActionLibPrivate();
    ~ActionLibPrivate();

private:
    bool InitializeDB();

public:
    bool createDBConnection();
    bool InsertDBData(QString name, int points);
    void CloseDB();

private:

};

#endif // ACTIONLIBPRIVATE_H
