#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H

#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

class connectionDB
{
public:
    connectionDB();

private:
    QSqlDatabase db;
    const QString DRIVER = "QMYSQL";
    const QString HOST = "localhost";
    const QString PASSWORD = "";
    const QString USER = "root";
    const int PORT = 3306;

    void connectDB();
};

#endif // CONNECTIONDB_H
