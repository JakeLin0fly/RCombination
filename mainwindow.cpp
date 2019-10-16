#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChar>

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

    connect(ui->calculate, SIGNAL(clicked()), this, SLOT(onClickedSubmit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onClickedSubmit(){
    //组合数r 输入验证
    QString rString = ui->r_lineEdit->text();
    foreach (QChar c, rString) {
        if(c < '0' || c > '9'){
            QMessageBox::warning(this, QString("错误"), QString("数字r输入错误！请重新输入."),QMessageBox::Ok);
            return;
        }
    }
    myObj = new RCombination(ui->combination_lineEdit->text(), rString);
    if(-1 == myObj->getAnswer()){
        QMessageBox::warning(this, QString("错误"), QString("集合字符串输入错误！请重新输入."),QMessageBox::Ok);
    }else {
        long long sum = myObj->calculate();
        //    ui->answer->setText();
    }

    delete myObj;
}
