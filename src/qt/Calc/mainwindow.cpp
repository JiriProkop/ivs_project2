#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setMaxLength(22);

        connect(ui->one, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("1"); });
        connect(ui->two, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("2"); });
        connect(ui->three, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("3"); });
        connect(ui->four, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("4"); });
        connect(ui->five, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("5"); });
        connect(ui->six, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("6"); });
        connect(ui->seven, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("7"); });
        connect(ui->eight, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("8"); });
        connect(ui->nine, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("9"); });
        connect(ui->zero, &QPushButton::clicked ,this, [this] {MainWindow::putNumber("0"); });

        connect(ui->del, &QPushButton::clicked ,this, [this] {ui->lineEdit->backspace(); });
        connect(ui->ac, &QPushButton::clicked ,this, [this] {ui->lineEdit->clear(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::putNumber(const QString &number)
{
    ui->lineEdit->insert(number);
}
