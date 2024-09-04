#include "connection.h"
#include<QDebug>
Connection::Connection()
{

}
/*
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("controlqt");
db.setUserName("system");
db.setPassword("thouraya2002");

if (db.open())
test=true;
    return  test;
}
*/

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("test");
    db.setPassword("test");

    if (db.open()) {
        test = true;
    } else {
        qDebug() << "Erreur de connexion:" << db.lastError().text();
    }

    return test;
}
