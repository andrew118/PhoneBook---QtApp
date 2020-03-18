#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->show();

    ConnectionDB db;
}

Widget::~Widget()
{
    delete ui;
}

