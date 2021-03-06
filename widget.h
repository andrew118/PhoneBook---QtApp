#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlQuery>

#include "connectiondb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_showAllButton_clicked();

    void on_addButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::Widget *ui;

    ConnectionDB *db;
    void showResults(QString dbQuery);
};
#endif // WIDGET_H
