#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H

#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

class ConnectionDB
{
public:
    ConnectionDB();

private:
    QSqlDatabase db;
    const QString DRIVER = "QMYSQL";
    const QString HOST = "localhost";
    const QString PASSWORD = "";
    const QString USER = "root";
    const QString DB_NAME = "phonebook";
    const int PORT = 3306;

    void connectDB();
};

#endif // CONNECTIONDB_H
