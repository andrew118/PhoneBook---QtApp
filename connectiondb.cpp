#include "connectiondb.h"

connectionDB::connectionDB()
{
    connectDB();
}

void connectionDB::connectDB()
{
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(HOST);
    db.setUserName(USER);
    db.setPassword(PASSWORD);
    db.setPort(PORT);

    qDebug() << "DB status: " << db.open();
}
