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

    try {
        bool connectedOk = db.open();
        if (connectedOk)
            qDebug() << "Udało się połączyć z bazą danych";
        else
        {
            throw (connectedOk);
        }
    } catch (bool error) {
        qDebug() << "Nie można się połączyć z bazą danych!";
        //qDebug() << db.lastError();
    }


}
