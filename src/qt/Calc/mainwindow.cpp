/**
 * @file mainwindow.cpp
 * @author Patrik Čerbák (xcerba00), Jiří Prokop (xproko47)
 * @brief  the main window of the calculator
 */
#include "mainwindow.h"
#include "./ui_mainwindow.h"

int alreadyOperation = 0; // a variable to check if there is already an operation inserted

/**
 * The main window constructor.
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // lock the window size
    this->setFixedSize(this->width(),this->height());

    // connect the number and dot buttons to putNumber() and putDot() functions
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

    // connect backspace and clear button
    connect(ui->del, &QPushButton::clicked ,this, [this] {ui->inputField->backspace(); });
    connect(ui->ac, &QPushButton::clicked ,this, [this] {ui->inputField->clear(); ui->prevNum->clear(); ui->prevNum2->clear(); alreadyOperation = 0;});

    // connect the operations with the putPrevNum() function
    connect(ui->plus, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("+"); });
    connect(ui->minus, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("-"); });
    connect(ui->multiply, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("*"); });
    connect(ui->divide, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("/"); });
    connect(ui->modulo, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("mod"); });
    connect(ui->nthPower, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("^"); });
    connect(ui->nthRoot, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("√"); });
    connect(ui->factorial, &QPushButton::clicked, this, [this] {MainWindow::putPrevNum("!"); });

    // when the text changes, check if the user inserted a operation symbol (+, -, *, /)
    connect(ui->inputField, &QLineEdit::textChanged, this, &MainWindow::checkForOperation);
    // when return is pressed, call the evaluateSolution() function
    connect(ui->inputField, &QLineEdit::returnPressed, this, &MainWindow::evaluateSolution);

    // evaluate the solution when user clicks the equals button (=)
    connect(ui->equals, &QPushButton::clicked ,this, &MainWindow::evaluateSolution);

    // connect the help button
    connect(ui->help, &QPushButton::clicked ,this, [this] {system("xdg-open /usr/share/calc/documentation.pdf"); });

    // regular expression to validate the input
    QRegularExpression rx("-?[0-9]{1,20}((\\.[0-9]{0,8}[+,\\-,*,/,=]?)|([+,\\-,*,/,=]?))");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->inputField->setValidator(validator);

}
/**
 * @brief The main window destructor.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * A function to put a number into the input field.
 *
 * @param number The number to add to the input filed (in a QString type).
 */
void MainWindow::putNumber(const QString &number)
{
    ui->inputField->insert(number);
}

/**
 * A function for inserting dot into the input field.
 */
void MainWindow::putDot()
{
    ui->inputField->insert(".");
}

/**
 * This function is for checking the keyboard input and determinig if an operation character was inserted.
 * If so, call the function putPrevNum() with the symbol.
 */
void MainWindow::checkForOperation()
{
    QString str = ui->inputField->text();
    // go through the whole string and look for these symbols
    int i = 0;
    while(i < str.size())
    {
        if(str[i] == '+')
        {
            ui->inputField->backspace();
            MainWindow::putPrevNum("+");
            return;
        }
        else if(str[i] == '-')
        {
            // ignore the first minus (so the user can input negative numbers)
            if(str[0] != '-')
            {
                ui->inputField->backspace();
                MainWindow::putPrevNum("-");
            }
            return;
        }
        else if(str[i] == '*')
        {
            ui->inputField->backspace();
            MainWindow::putPrevNum("*");
            return;
        }
        else if(str[i] == '/')
        {
            ui->inputField->backspace();
            MainWindow::putPrevNum("/");
            return;
        }
        else if(str[i] == '=')
        {
            ui->inputField->backspace();
            MainWindow::evaluateSolution();
            return;
        }
        i++;
    }
}

/**
 * A function that takes the input from input field and puts it to the prevNum label with given operation symbol.
 *
 * @param operation A QString symbol of operation (+,-,*,/ etc.).
 */
void MainWindow::putPrevNum(const QString &operation)
{
    // insert the minus without putting the function into the label, if it is the first character on line
    if(QString::compare(ui->inputField->text(), "") == 0 && QString::compare(operation, "-") == 0)
    {
        ui->inputField->insert("-");
    }
    else if(!alreadyOperation) // check if the user is trying to input more than one operation
    {
        ui->prevNum->setText(ui->inputField->text() + " " + operation);
        ui->inputField->clear();
        ui->prevNum2->clear();
        alreadyOperation = 1;
    }
}

/**
 * A function for determining how many numbers after the decimal dot to display.
 * Checks if the result number is integer and if so, displays zero numbers after decimal dot, otherwise displays 8.
 *
 * @param result Result of function.
 * @return Returns the number of characters after the decimal dot to display.
 */
int displayResult(double result)
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

/**
 * This function is called after the = button is pressed and it evaluates the equation, adds the secont number to the
 * label prevNum2 and puts the result into the input field. (It also catches and displays errors.)
 */
void MainWindow::evaluateSolution()
{
    // do not do anything if there is already a text in prevNum2
    if(QString::compare(ui->prevNum2->text(), "") != 0)
    {
        return;
    }
    // check for invalid values inputed
    if(QString::compare(ui->prevNum->text(), "") == 0 || QString::compare(ui->prevNum->text(), "- -") == 0
       || QString::compare(ui->inputField->text(), "") == 0 || QString::compare(ui->inputField->text(), "-") == 0)
    {
        // factorial puts no number into prevNum2, so only it is correct
        if(!(QString::compare(ui->prevNum->text(), "") != 0 && QString::compare(ui->prevNum->text().split(" ")[1], "!") == 0
             && QString::compare(ui->inputField->text(), "") == 0))
        {
            // clear the calc, display error and return
            ui->prevNum->clear();
            ui->inputField->clear();
            ui->prevNum2->setText("Syntax error!");
            alreadyOperation = 0;
            return;
        }
    }

    // convert the numbers from QString to doubles
    double a = ui->prevNum->text().split(" ")[0].toDouble();
    double b = ui->inputField->text().toDouble();
    double result = 0;

    // determine which operation to do by the text in the prevNum
    if(QString::compare(ui->prevNum->text().split(" ")[1], "+") == 0)
    {
        // set the label prevNum2 do display the second number with =
        ui->prevNum2->setText(ui->inputField->text() + " =");
        // calculate the result
        result = plus(a, b);
        // check if the size of the number is ok
        if(get_number_length(result) < 21)
        {
            // if so, display the result
            ui->inputField->setText(QString().setNum(result, 'f', displayResult(result)));
        }
        else
        {
            // if not, clear the calc and display Math error!
            ui->prevNum->clear();
            ui->inputField->clear();
            ui->prevNum2->setText("Math error!");
        }
    }
    // continue with all the other operations...
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "-") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        result = sub(a, b);
        if(get_number_length(result) < 21)
        {
            ui->inputField->setText(QString().setNum(result, 'f', displayResult(result)));
        }
        else
        {
            ui->prevNum->clear();
            ui->inputField->clear();
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "*") == 0)
    {
        ui->prevNum2->setText(ui->inputField->text() + " =");
        result = mul(a, b);
        if(get_number_length(result) < 21)
        {
            ui->inputField->setText(QString().setNum(result, 'f', displayResult(result)));
        }
        else
        {
            ui->prevNum->clear();
            ui->inputField->clear();
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
                ui->inputField->setText(QString().setNum(result, 'f', displayResult(result)));
            }
            else
            {
                ui->prevNum->clear();
                ui->inputField->clear();
                ui->prevNum2->setText("Math error!");
            }
        }
        // catch dividing by zero
        catch (std::invalid_argument) {
            ui->prevNum->clear();
            ui->inputField->clear();
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
                ui->inputField->setText(QString().setNum(result, 'f', displayResult(result)));
            }
            else
            {
                ui->prevNum->clear();
                ui->inputField->clear();
                ui->prevNum2->setText("Math error!");
            }
        }
        // catch dividing by zero
        catch (std::invalid_argument) {
            ui->prevNum->clear();
            ui->inputField->clear();
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
                ui->inputField->setText(QString().setNum(result, 'f', displayResult(result)));
            }
            else
            {
                ui->prevNum->clear();
                ui->inputField->clear();
                ui->prevNum2->setText("Math error!");
            }
        }
        // catch errors
        catch (std::invalid_argument) {
            ui->prevNum->clear();
            ui->inputField->clear();
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
                ui->inputField->setText(QString().setNum(result, 'f', displayResult(result)));
            }
            else
            {
                ui->prevNum->clear();
                ui->inputField->clear();
                ui->prevNum2->setText("Math error!");
            }
        }
        // catch errors
        catch (std::invalid_argument) {
            ui->prevNum->clear();
            ui->inputField->clear();
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
                ui->inputField->setText(QString().setNum(result, 'f', displayResult(result)));
            }
            else
            {
                ui->prevNum->clear();
                ui->inputField->clear();
                ui->prevNum2->setText("Math error!");
            }
        }
        // catch errors
        catch (std::invalid_argument) {
            ui->prevNum->clear();
            ui->inputField->clear();
            ui->prevNum2->setText("Math error!");
        }
    }
    else if(QString::compare(ui->prevNum->text().split(" ")[1], "!") == 0)
    {
        ui->prevNum->setText(ui->prevNum->text() + " =");
        try {
            ui->inputField->setText(QString().setNum(fac(a), 'f', 0));
        }
        // catch errors
        catch (std::invalid_argument x) {
            ui->prevNum->clear();
            ui->inputField->clear();
            ui->prevNum2->setText("Math error!");
        }
    }
    alreadyOperation = 0; // reset
}
