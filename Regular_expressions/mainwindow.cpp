#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText){
        QRegularExpression exp("^\\+\\d{11}$");
        if(currentText.isEmpty()) setWaiting();
        else if(exp.match(currentText).hasMatch()) setCorrect();
        else setNonCorrect();
    });
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setCorrect(){
    ui->label->setText("Ок");
    ui->label->setStyleSheet("QLabel {color: green;}");
}

void MainWindow::setNonCorrect(){
    ui->label->setText("Not Ok");
    ui->label->setStyleSheet("QLabel {color: red;}");
}

void MainWindow::setWaiting(){
    ui->label->setText("Waiting");
    ui->label->setStyleSheet("QLabel {color: black;}");
}
