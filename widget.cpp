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
    QSqlQuery query("SELECT * FROM contacts");
    while(query.next())
    {
        ui->listWidget->addItem(new QListWidgetItem(query.value(0).toString() + " " +
                                                    query.value(1).toString() + " " +
                                                    query.value(2).toString() ));
    }
}
