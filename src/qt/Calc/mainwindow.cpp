#include "mainwindow.h"
#include "./ui_mainwindow.h"

int alreadyOperation = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    connect(ui->ac, &QPushButton::clicked ,this, [this] {ui->inputField->clear(); ui->prevNum->clear(); alreadyOperation = 0;});


    connect(ui->plus, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("+"); });
    connect(ui->minus, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("-"); });
    connect(ui->multiply, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("X"); });
    connect(ui->divide, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("/"); });
    connect(ui->modulo, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("mod"); });
    connect(ui->nthPower, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("^"); });
    connect(ui->nthRoot, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("√"); });


    connect(ui->equals, &QPushButton::clicked ,this, &MainWindow::evaluateSolution);


    QRegularExpression rx("[0-9]{1,20}(\\.[0-9]{1,8})|()");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->inputField->setValidator(validator);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::putNumber(const QString &number)
{
    ui->inputField->insert(number);
}

void MainWindow::putDot()
{
    ui->inputField->insert(".");
}

void MainWindow::putPrevNum(const QString &operation)
{
    if(!alreadyOperation)
    {
        ui->prevNum->setText(ui->inputField->text() + " " + operation);
        ui->inputField->clear();
        alreadyOperation = 1;
    }
}

void MainWindow::evaluateSolution()
{
    if(QString::compare(ui->prevNum->text(), "") == 0 || QString::compare(ui->inputField->text(), "") == 0)
    {
        ui->prevNum->setText("Error: not enough numbers!"); // TODO
        return;
    }
    double a = ui->prevNum->text().split(" ")[0].toDouble();
    double b = ui->inputField->text().toDouble();


    alreadyOperation = 0;
}
