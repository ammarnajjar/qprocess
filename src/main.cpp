/*!
    \file    main.cpp
    \author  Ammar Najjar <najjarammar@gmail.com>
    \date    Wed Oct  5 18:12:18 CEST 2016
*/

#include <QApplication>
#include "Form.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Form* form = new Form;
    form->show();

    return app.exec();
}

/* vim: set ft=cpp ts=4 sw=4 et ai : */
