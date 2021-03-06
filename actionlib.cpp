#include "actionlib.h"
#include <QObject>
#include <QVariant>
#include <QList>
//#include <QSqlDatabase>
//#include <QSqlQuery>

#include "actionlibprivate.h"

ActionLib::ActionLib(QObject *parent) : QObject(parent), d_ptr(new ActionLibPrivate())
{

}

bool ActionLib::CreateDBCon()
{
    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("databaseFile.db");
    db.setConnectOptions("QSQLITE_ENABLE_SHARED_CACHE = 1");
    if (!db.open())
    {
        return false;
    }
    QSqlQuery query;
    return query.exec("create table results (firstname varchar(20), points int)");
    */
    //Q_D(ActionLib);
    return d_ptr->createDBConnection();
}

bool ActionLib::InsertData(QString name, int points)
{
    return d_func()->insertDBData(name, points);
}

QVariant ActionLib::readData(QString name)
{
    return d_func()->readDBData(name);
}

ActionLib::~ActionLib()
{
    if(d_ptr) {
        d_ptr->CloseDB();
        delete d_ptr;
    }

}
