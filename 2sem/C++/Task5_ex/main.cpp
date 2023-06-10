#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qDebug() << "* : \n";
    Expression *multiplication = new BinaryOperation(new Number(4), '*', new Number(3));
    qDebug() << multiplication->evaluate();
    putchar('\n');

    qDebug() << multiplication->evaluate() << " " << CheckEquals(new Number(4), new Number(3));
    putchar('\n');

    qDebug() << "\n/ : \n";
    Expression *division = new BinaryOperation(new Number(12), '/', new Number(6));
    qDebug() << division->evaluate();
    putchar('\n');

    qDebug() << division->evaluate() << " " << CheckEquals(new Number(12), new Number(6));
    putchar('\n');

    qDebug() << "\n+ : \n";
    Expression *sum = new BinaryOperation(new Number(5), '+', new Number(10));
    qDebug() << sum->evaluate();
    putchar('\n');

    qDebug() << sum->evaluate() << " " << CheckEquals(new BinaryOperation(new Number(3), '+', new Number(4)), new BinaryOperation(new Number(2), '-', new Number(1)));
    putchar('\n');

    qDebug() << "\n- : \n";
    Expression *sub = new BinaryOperation(new Number(9), '-', new Number(4));
    qDebug() << sub->evaluate();
    putchar('\n');

    qDebug() << sub->evaluate() << " " << CheckEquals(new BinaryOperation(new Number(3), '+', new Number(4)), new Number(4));
    putchar('\n');


    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);
    // вычисляем и выводим результат: 25.5
    qDebug() << expr->evaluate();
    putchar('\n');


    delete multiplication;
    delete division;
    delete sum;
    delete sub;

    return 0;

    w.show();
    return a.exec();
}
