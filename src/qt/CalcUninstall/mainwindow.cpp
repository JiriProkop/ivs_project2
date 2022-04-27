/**
 * @file mainwindow.cpp
 * @author Patrik Čerbák (xcerba00)
 * @brief  calculator uninstaller
 */
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // lock the window size
    this->setFixedSize(this->width(),this->height());

    // run the system command to uninstall calc
    connect(ui->yes, &QPushButton::clicked ,this, [this] {system("sudo dpkg -r calc"); QApplication::quit();});

    // exit this uninstaller
    connect(ui->no, &QPushButton::clicked, this, QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

