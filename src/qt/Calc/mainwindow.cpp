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
    connect(ui->ac, &QPushButton::clicked ,this, [this] {ui->inputField->clear(); ui->prevNum->clear(); ui->prevNum2->clear(); alreadyOperation = 0;});


    connect(ui->plus, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("+"); });
    connect(ui->minus, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("-"); });
    connect(ui->multiply, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("*"); });
    connect(ui->divide, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("/"); });
    connect(ui->modulo, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("mod"); });
    connect(ui->nthPower, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("^"); });
    connect(ui->nthRoot, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("√"); });
    connect(ui->factorial, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("!"); });

    connect(ui->inputField, &QLineEdit::textChanged, this, &MainWindow::checkForOperation);

    connect(ui->equals, &QPushButton::clicked ,this, &MainWindow::evaluateSolution);

    connect(ui->help, &QPushButton::clicked ,this, [this] {system("xdg-open /home/patrik/Skola/IVS/2/ivs_project2/dokumentace.pdf"); }); // TODO

    QRegularExpression rx("-?[0-9]{1,20}(\\.[0-9]{0,8}\\+?\\-?\\*?\\/?)|()");
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

void MainWindow::checkForOperation()
{
    return;
}

void MainWindow::putPrevNum(const QString &operation)
{
    if(QString::compare(ui->inputField->text(), "") == 0 && QString::compare(operation, "-") == 0)
    {
        ui->inputField->insert("-");
    }
    else if(!alreadyOperation)
    {
        ui->prevNum->setText(ui->inputField->text() + " " + operation);
        ui->inputField->clear();
        ui->prevNum2->clear();
        alreadyOperation = 1;
    }
}

int display_result(double result)
{
    if(is_int(result))
    {
        return 0;
    }
    else
    {
        return 8;
    }
}


void MainWindow::evaluateSolution()
{
    if(QString::compare(ui->prevNum->text(), "") == 0 || QString::compare(ui->prevNum->text(), "- -") == 0
       || QString::compare(ui->inputField->text(), "") == 0 || QString::compare(ui->inputField->text(), "-") == 0)
    {
        if(!(QString::compare(ui->prevNum->text(), "") != 0 && QString::compare(ui->prevNum->text().split(" ")[1], "!") == 0
             && QString::compare(ui->inputField->text(), "") == 0))
        {
            ui->prevNum2->setText("Syntax error!");
            alreadyOperation = 0;
            return;
        }
    }
    double a = ui->prevNum->text().split(" ")[0].toDouble();
    double b = ui->inputField->text().toDouble();
    double result = 0;

    if(QString::compare(ui->prevNum->text().split(" ")[1], "+") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        result = plus(a, b);
        if(get_number_length(result) < 21)
        {
            ui->inputField->setText(QString().setNum(result, 'f', display_result(result)));
        }
        else
        {
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "-") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        result = sub(a, b);
        if(get_number_length(result) < 21)
        {
            ui->inputField->setText(QString().setNum(result, 'f', display_result(result)));
        }
        else
        {
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "*") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        result = mul(a, b);
        if(get_number_length(result) < 21)
        {
            ui->inputField->setText(QString().setNum(result, 'f', display_result(result)));
        }
        else
        {
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "/") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        try {
            result = divide(a, b);
            if(get_number_length(result) < 21)
            {
                ui->inputField->setText(QString().setNum(result, 'f', display_result(result)));
            }
            else
            {
                ui->prevNum2->setText("Math error!");
            }
        }
        catch (std::invalid_argument) {
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "mod") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        try {
            result = modulo(a, b);
            if(get_number_length(result) < 21)
            {
                ui->inputField->setText(QString().setNum(result, 'f', display_result(result)));
            }
            else
            {
                ui->prevNum2->setText("Math error!");
            }
        }
        catch (std::invalid_argument) {
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "^") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        try {
            result = nth_power(a, b);
            if(get_number_length(result) < 21)
            {
                ui->inputField->setText(QString().setNum(result, 'f', display_result(result)));
            }
            else
            {
                ui->prevNum2->setText("Math error!");
            }
        }
        catch (std::invalid_argument) {
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "^") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        try {
            result = nth_power(a, b);
            if(get_number_length(result) < 21)
            {
                ui->inputField->setText(QString().setNum(result, 'f', display_result(result)));
            }
            else
            {
                ui->prevNum2->setText("Math error!");
            }
        }
        catch (std::invalid_argument) {
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "√") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        try {
            result = nth_root(b, a);
            if(get_number_length(result) < 21)
            {
                ui->inputField->setText(QString().setNum(result, 'f', display_result(result)));
            }
            else
            {
                ui->prevNum2->setText("Math error!");
            }
        }
        catch (std::invalid_argument) {
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "!") == 0)
    {
        ui->prevNum->setText(ui->prevNum->text() + " =");
        try {
            ui->inputField->setText(QString().setNum(fac(a), 'f', 0));
        }
        catch (std::invalid_argument x) {
            ui->prevNum2->setText("Math error!");
        }
    }
    alreadyOperation = 0;
}

// TODO:
//
//       keyboard control
//
