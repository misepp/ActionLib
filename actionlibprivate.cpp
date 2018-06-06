#include "actionlibprivate.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QObject>
#include <QVariant>
#include <QList>
#include <QDir>


ActionLibPrivate::ActionLibPrivate()
{

}

bool ActionLibPrivate::createDBConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath() + "//databaseFile.db");
    qDebug() << "Curent Path: " << QDir::currentPath();
    db.setConnectOptions("QSQLITE_ENABLE_SHARED_CACHE");
//    db.setConnectOptions("QSQLITE_ENABLE_SHARED_CACHE = 1");
    if (!db.open())
    {
        return false;
    }

    QSqlQuery query;
    //bool temp = query.prepare("create table results (id int primary key, firstname varchar(20), points int)");
    return query.exec("create table results (firstname varchar(50), points int)");
}

bool ActionLibPrivate::insertDBData(QString name, int points)
{
    if(QSqlDatabase::contains())
    {
       if(QSqlDatabase::database().isOpen())
       {
           QSqlQuery query;
           QString str = "insert into results values "; // (name, points)";
//           query.prepare("insert into results values (:name, :points)");
//           query.bindValue(":name", name);
//           query.bindValue(":points", points);
           qDebug() << query.lastError();
           str = str + "(" + "\"" + name + "\", " + QString::number(points) + ")";
//           QString temp = str.replace(str.indexOf("name"), QString(name).length() + 1, name + "'");
//           temp = temp.replace(temp.indexOf("points"), QString::number(points).length(), QString::number(points));
//           return query.exec();
           return query.exec(str);
       }
    }
    return false;
}

QVariant ActionLibPrivate::readDBData(QString name)
{
    if(QSqlDatabase::contains())
    {
        if(QSqlDatabase::database().isOpen())
        {
            QList<QVariant> result;
            QVariant data;
            QSqlQuery query;
            QString str = "SELECT firstname, points FROM results WHERE firstname="; //':name'";
//            QString temp = str.replace(str.indexOf(":name"), QString(name).length(), name);
            str = str + "\"" + name + "\"";
//            query.prepare("SELECT * FROM results WHERE firstname='name'");
            //query.bindValue("name", name);
            query.exec(str);
            qDebug() << query.lastError();
            while(query.next()) {
                result.append(QString(query.value(0).toString() + "," + query.value(1).toString()));
            }
            data.setValue<QList<QVariant>>(result);
            return data;
        }
    }
    return QList<QVariant>();
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
