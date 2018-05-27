#ifndef ACTIONLIB_H
#define ACTIONLIB_H

#include <QObject>
#include "sharedlib_global.h"

class ActionLibPrivate;

class MYSHAREDLIB_EXPORT ActionLib : public QObject
{
    Q_OBJECT

public:
    ActionLib(QObject *parent);
    ~ActionLib();

public:
    bool CreateDBCon();
    bool InsertData(QString name, int points);

private:
    Q_DECLARE_PRIVATE(ActionLib)
    ActionLibPrivate *d_ptr;


};

#endif // ACTIONLIB_H
