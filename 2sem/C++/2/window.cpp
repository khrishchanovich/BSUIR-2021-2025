#include "window.h"

Window::Window(QWidget *parent)
    : QWidget{parent}
{

    resize(400, 400);
    show();

}

