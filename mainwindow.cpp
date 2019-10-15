#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(550, 350);

    ui->title_lable->setText(QString("容斥原理-重集的r-组合"));
    ui->combination_label->setText(QString("集合序列,eg: k1*a1,k2*a2,k3*a3,..."));
    ui->r_lable->setText(QString("组合数r"));
    ui->answer->setText(QString(""));

    connect(ui->calculate, SIGNAL(triggered()), this, SLOT(onClickedSubmit));
}

MainWindow::~MainWindow()
{
    delete ui;
}
