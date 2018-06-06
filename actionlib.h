#ifndef ACTIONLIB_H
#define ACTIONLIB_H

#include <QObject>
#include "sharedlib_global.h"

class ActionLibPrivate;
class QVariant;
class QString;

class MYSHAREDLIB_EXPORT ActionLib : public QObject
{
    Q_OBJECT

public:
    ActionLib(QObject *parent);
    ~ActionLib();

public:
    bool CreateDBCon();
    bool InsertData(QString name, int points);
    QVariant readData(QString name);

private:
    Q_DECLARE_PRIVATE(ActionLib)
    ActionLibPrivate *d_ptr;


};

#endif // ACTIONLIB_H
