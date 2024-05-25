#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QTextStream>
#include <QProcess>

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <memory> // Включение заголовочного файла для std::unique_ptr
//########################################################################################################
/// переменные:
std::vector<long long> list_of_synapses={} ;
 // Инициализация указателя на std::vector<long long>
 //   std::vector<long long>* list_of_synapses = new std::vector<long long>;
std::vector<long long> list_of_neurons={};//[201] ;//={};
long long variable_error;
QString  Nazvaniye_fayla_s_neyronami_i_signalom="";
bool Odin_Uchitelia;
bool Odin_Programmi;
int var ;
// Реализация make_unique для C++11
//namespace std {
//    template<typename T, typename... Args>
//    std::unique_ptr<T> make_unique(Args&&... args) {
//        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
//    }
//}

 // Инициализация умного указателя на std::vector<long long> с использованием std::unique_ptr
//    std::unique_ptr<std::vector<long long>> list_of_synapses = std::make_unique<std::vector<long long>>();
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
              tr("Open txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/", tr("Txt Files (*.txt)"));
   }           
//########################################################################################################
// читаем нейроны в вектор
    std::ifstream file(Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str());
    if (!file) {
        // handle error
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
         long long value;
        std::istringstream iss(line);
        if (!(iss >> value)) {
            // handle error
            continue;
        }
        list_of_neurons.push_back(value);
    }
    file.close();
//########################################################################################################              
///#################### считываем синасы из файла в вектор #########################################################
    QFile file2(  "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt");
    if (!file2.open(QFile::ReadOnly | QFile::Text)) {
        throw std::runtime_error("Failed to open file");
    }

    QTextStream in(&file2);
    while (!in.atEnd()-1) {//-1
        QString line = in.readLine();
        bool ok;
         long long synaps = line.toLongLong(&ok);
        if (!ok) {
            throw std::runtime_error("Invalid synaps value in file");
        }
        list_of_synapses.push_back(synaps);
    }

    file2.close();
   // return list_of_neurons;
//########################################################################################################             
// блок вычисления-решения 200 нейрона
   for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)

        {
if(list_of_synapses[synapse_index]>=9223372036854775806 )
 std::cout << "list_of_synapses[synapse_index]>=9223372036854775806"<< std::endl;  
//Segmentation fault
if (list_of_neurons[var]<9223372036854775806 && list_of_neurons[var]>-9223372036854775807 &&
list_of_neurons[neuron_index]<9223372036854775806 && list_of_neurons[neuron_index]>-9223372036854775807
&& list_of_synapses[synapse_index]<9223372036854775806 && list_of_synapses[synapse_index]>-9223372036854775807
&& list_of_synapses[synapse_index]!=0 )
           list_of_neurons[var]=list_of_neurons[var]+  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]); 

//              });
        } // вычитаем нейроны
    }
//########################################################################################################
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {
   //  if(list_of_synapses[synapse_index]!=0)
   // if (list_of_neurons[var]!=0)
  // if ( synapse_index < 10100 )
   list_of_neurons[200] = list_of_neurons[200] + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]); // + на -

    }
//########################################################################################################    
//list_of_neurons[200] -= std::accumulate(list_of_neurons.begin() + 100, list_of_neurons.begin() + 200,
//                                        0ULL,
//                                        [&](unsigned long long sum, unsigned long long neuron) {
//                                            return sum + (neuron / list_of_synapses[++synapse_index]);
//                                        });    
//######################################################################################################## 
  //  variable_error     =   1073741824-list_of_neurons[200] ;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // std::cout << "variable_error = "<< variable_error<< std::endl;
//########################################################################################################
/////////////   показываем что определила программа
    if 
      //  ( variable_error <=0)
        (list_of_neurons[200]<0)

    {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
        Odin_Programmi=true;
    }
                           else {
        ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
          Odin_Programmi=false;
    }
//########################################################################################################
//Odin_Uchitelia=false;  ui->label_2->setText ("Odin_Programmi==true; Odin_Uchitelia=false");
        // bez_1
//        QProcess::startDetached(

//           "/home/viktor/my_projects_qt_2_build/build-bez_1_GUI-Desktop_Qt_5_12_12_GCC_64bit-Debug/bez_1_GUI"
//            , qApp->arguments());  
//########################################################################################################

              
} // Dialog::Dialog(QWidget *parent)

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
 // выбор программы обучения:
    if ( Odin_Programmi==false) // Если не распознана 1:
    {
        Odin_Uchitelia=true; ui->label_2->setText ("Odin_Programmi==false; Odin_Uchitelia=true");
        // cycle_of_distinguishing_a_one_with_vectors_GUI
        QProcess::startDetached(
          
"/home/viktor/my_projects_qt_2_build/build-cycle_of_distinguishing_a_one_with_vectors_GUI_2-Desktop_Qt_5_12_12_GCC_64bit-Debug/cycle_of_distinguishing_a_one_with_vectors_GUI_2"
                                , qApp->arguments());  
//   qApp->quit();
    }
    else // Если не распознана не 1:
    {
        Odin_Uchitelia=false;  ui->label_2->setText ("Odin_Programmi==true; Odin_Uchitelia=false");
        // bez_1
        QProcess::startDetached(

           "/home/viktor/my_projects_qt_2_build/build-bez_1_GUI_3-Desktop_Qt_5_12_12_GCC_64bit-Release/bez_1_GUI_3"
            , qApp->arguments());  
 //          qApp->quit();
    }
    //        Odin_Programmi==false;
    // если одно сочетание запускаем одну программу, если другое - другую   
}

