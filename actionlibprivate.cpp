#include "actionlibprivate.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>


ActionLibPrivate::ActionLibPrivate()
{

}

bool ActionLibPrivate::createDBConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("databaseFile.db");
    db.setConnectOptions("QSQLITE_ENABLE_SHARED_CACHE = 1");
    if (!db.open())
    {
        return false;
    }

    QSqlQuery query;
    return query.exec("create table results (firstname varchar(20), points int)");
}

bool ActionLibPrivate::InsertDBData(QString name, int points)
{
    if(QSqlDatabase::contains())
    {
       if(QSqlDatabase::database().isOpen())
       {
           QSqlQuery query;
           QString str = "insert into results values ('name', points)";
           QString temp = str.replace(str.indexOf("name"), QString("name").length(), name);
           temp = temp.replace(temp.indexOf("points"), QString("points").length(), QString::number(points));
           return query.exec(temp);
           //return query.exec("insert into results values (" + "\"" + name + "\"" + ", " + points + ")");
       }
    }
    return false;

}

void ActionLibPrivate::CloseDB()
{
    if (QSqlDatabase::contains())
    {
        QSqlDatabase::database(false).close();
    }
}

ActionLibPrivate::~ActionLibPrivate()
{
    this->CloseDB();
}
