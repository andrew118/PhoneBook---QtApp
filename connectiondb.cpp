#include "connectiondb.h"

ConnectionDB::ConnectionDB()
{
    connectDB();
}

void ConnectionDB::connectDB()
{
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setHostName(HOST);
    db.setUserName(USER);
    db.setPassword(PASSWORD);
    db.setPort(PORT);
    db.setDatabaseName(DB_NAME);

    qDebug() << "DB status: " << db.open();
    qDebug() << db.lastError();
}
