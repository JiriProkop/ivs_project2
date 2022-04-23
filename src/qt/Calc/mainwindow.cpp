#include "mainwindow.h"
#include "./ui_mainwindow.h"

int decimals = 0;
int numOfCharacters = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->inputField->setMaxLength(29);

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
    connect(ui->dot, &QPushButton::clicked ,this, &MainWindow::putDot);

    connect(ui->del, &QPushButton::clicked ,this, [this] {ui->inputField->backspace(); });
    connect(ui->ac, &QPushButton::clicked ,this, [this] {ui->inputField->clear(); });

    connect(ui->equals, &QPushButton::clicked ,this, [this] {ui->prevNum->setText(ui->inputField->text()); });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::putNumber(const QString &number)
{
    if(decimals == 0 && numOfCharacters < 20)
    {
        ui->inputField->insert(number);
        numOfCharacters++;
    }
    else if(decimals == 1 && numOfCharacters < 28)
    {
        ui->inputField->insert(number);
        numOfCharacters++;
    }

}


void MainWindow::putDot()
{
    if(decimals == 0)
    {
        ui->inputField->insert(".");
        decimals = 1;
    }
}
