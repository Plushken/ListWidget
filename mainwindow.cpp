#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lc->addItem("mom");
    ui->lc->addItem("dad");
    ui->lc->addItem("son");
    ui->lc->addItem("qom");
    ui->lc->addItem("fad");
    ui->lc->addItem("jon");
    ui->lc->addItem("grandmother");

    ui->rc->addItem("daughter");
    ui->rc->addItem("aunt");
    ui->rc->addItem("uncle");
    ui->rc->addItem("raughter");
    ui->rc->addItem("iunt");
    ui->rc->addItem("kkcle");


    select(ui->rc);
    select(ui->lc);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sortleft_clicked()
{
    check_column(ui->lc);
    ui->lc->sortItems(Qt::AscendingOrder);
    select(ui->rc);
    select(ui->lc);
}

void MainWindow::on_movetoright_clicked()
{
    check_column(ui-> lc);
    ui->rc->addItem(ui->lc->takeItem(ui->lc->currentRow()));
    select(ui->rc);
    select(ui->lc);

}

void MainWindow::on_movetoleft_clicked()
{
    check_column(ui-> rc);
    ui->lc->addItem(ui->rc->takeItem(ui->rc->currentRow()));
    select(ui->rc);
    select(ui->lc);

}

void MainWindow::on_sortright_clicked()
{
        check_column(ui-> rc);
    ui->rc->sortItems(Qt::DescendingOrder);
    select(ui->rc);
    select(ui->lc);

}

bool MainWindow::check_column(QListWidget* l)
{
    if(l->count()==0)
        QMessageBox::warning(0, "Ошибка!", "Данный список пуст!");
}

void MainWindow::select(QListWidget* l)
{
    l->setCurrentRow(-1);
}



void MainWindow::on_lc_itemClicked()
{
    select(ui->rc);
}

void MainWindow::on_rc_itemClicked()
{
    select(ui->lc);
}
