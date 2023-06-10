#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
    bool CheckEquals(Expression const *left, Expression const *right) // СЛЕДУЕТ РАЗОБРАТЬСЯ С ЭТИМ
    {
        return (*((size_t*)left) == *((size_t*)right));
    }
};

struct Number : public Expression
{
private:
    double value;
public:
    Number(double value) : value(value) {}
    double evaluate() const
    {
        return value;
    }

    ~Number() {}
};

struct BinaryOperation : public Expression
{
    BinaryOperation(Expression const *left, char op, Expression const *right)
        : left(left), op(op), right(right) {}

    double evaluate() const
    {
        switch (op)
        {
        case '+' :
            return (left->evaluate() + right->evaluate());
        case '-' :
            return (left->evaluate() - right->evaluate());
        case '*' :
            return (left->evaluate() * right->evaluate());
        case '/' :
            return (left->evaluate() / right->evaluate());
        }
    }

    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

private:
    Expression const* left;
    char op;
    Expression const* right;
};

// ПРИВОДИТ К САЙЗ Т, РАЗЫМЕНОВЫВАЕТ И СРАВНИВАЕТ ТО, ЧТО СТОИТ ПОД УКАЗАТЕЛЕМ ДРУГ С ДРУГОМ, И БЕРЕТ ЭТИ ЗНАЧЕНИЯ ИЗ ВИРТУАЛЬНОЙ ТАБЛИЦЫ
//(СОЗДАЕТСЯ ОДНА ПОД ВЕСЬ КЛАСС)
#endif // MAINWINDOW_H
