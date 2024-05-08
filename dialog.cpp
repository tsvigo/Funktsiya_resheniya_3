#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QTextStream>
#include <QProcess>
//########################################################################################################
/// переменные:
std::vector<unsigned long long> list_of_synapses ;
std::vector<unsigned long long> list_of_neurons[201] ;//={};
long long variable_error;
QString  Nazvaniye_fayla_s_neyronami_i_signalom="";
bool Odin_Uchitelia;
bool Odin_Programmi;
int var ;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    std::cout << "Funktsiya_Resheniya_3"<< std::endl;  
//########################################################################################################   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Открываем файл для решения

   if (Nazvaniye_fayla_s_neyronami_i_signalom=="")
   {
Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
              tr("Open txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/", tr("Txt Files (*.txt)"));
   }           
              
              
              
} // Dialog::Dialog(QWidget *parent)

Dialog::~Dialog()
{
    delete ui;
}

