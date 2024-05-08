#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
#include <iostream>
#include <fstream>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    std::cout << "Funktsiya_Resheniya_3"<< std::endl;   
}

Dialog::~Dialog()
{
    delete ui;
}

