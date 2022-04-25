#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include "../../calc_funcs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void putNumber(const QString &number);
    void putDot();
    void putPrevNum(const QString &operation);
    void evaluateSolution();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
