#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    status(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::status(int boolean){
    ui->pbCoffee->setEnabled(boolean);
    ui->pbTea->setEnabled(boolean);
    ui->pbMilk->setEnabled(boolean);
}

void Widget::changeMoney(int diff){ // enabled or disabled coffe/tea/milk
    money+=diff;
    ui->lcdNumber->display(money);
    if(money>=100){
        ui->pbCoffee->setEnabled(true);
    }
    if(money<100){
        ui->pbCoffee->setEnabled(false);
    }
    if(money>=150){
        ui->pbTea->setEnabled(true);
    }
    if(money<150){
        ui->pbTea->setEnabled(false);
    }
    if(money>=200){
        ui->pbMilk->setEnabled(true);
    }
    if(money<200){
        ui->pbMilk->setEnabled(false);
    }

}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);

}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    QString str_money;
    str_money = str_money.setNum(money);
    m.information(nullptr, "Money", str_money);
    status(false);
    money = 0;
    ui->lcdNumber->display(money);
}
