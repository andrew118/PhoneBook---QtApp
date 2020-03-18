#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = new ConnectionDB();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_showAllButton_clicked()
{
    QString showAllQuery("SELECT * FROM contacts");
    showResults(showAllQuery);
}

void Widget::on_addButton_clicked()
{
    QString phoneNumber = ui->phoneNumberLine->text();
    QString name = ui->nameLine->text();

    if (phoneNumber.isEmpty() || name.isEmpty())
    {
        qDebug() << "czegoś brak";
        return;
    }
    else
    {
        QString insertQuery = "INSERT INTO contacts VALUES (NULL, \"" + name + "\", \"" + phoneNumber + "\")";
        QSqlQuery query(insertQuery);
    }
}

void Widget::on_searchButton_clicked()
{
    QString searchQuery = "SELECT * FROM contacts WHERE";
    QString phoneNumber = ui->phoneNumberLine->text();
    QString name = ui->nameLine->text();
    bool isNumberGiven = phoneNumber.isEmpty();     // true for empty, false if not
    bool isNameGiven = name.isEmpty();

    if (!isNameGiven && isNumberGiven)
    {
        searchQuery += " name LIKE \"%" + name + "%\"";
        showResults(searchQuery);
    }
    else if (isNameGiven && !isNumberGiven)
    {
        searchQuery += " phone LIKE \"%" + phoneNumber + "%\"";
        showResults(searchQuery);


    }
    else if (!isNameGiven && !isNumberGiven)
    {
        searchQuery += " phone LIKE \"%" + phoneNumber + "%\" AND name LIKE \"%" + name + "%\"";
        showResults(searchQuery);
    }
    else
    {
        qDebug() << "Nie podano danych";
        return;
    }
}

void Widget::showResults(QString dbQuery)
{
    ui->listWidget->clear();
    QSqlQuery query(dbQuery);

    while(query.next())
    {
    ui->listWidget->addItem(new QListWidgetItem(query.value(0).toString() + " " +
                                                query.value(1).toString() + " " +
                                                query.value(2).toString() ));
    }
}

