#include "dialog.h"
#include "ui_dialog.h"
//########################################################################################################
#include <QApplication>
#include <QFile>
#include <QImage>
#include <QTextEdit>
#include <QDebug>
#include <QTextStream>

//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//########################################################################################################
// Теперь это надо в цикле файлы с 1 по 117
// Надо записать число в название
QString str;
  //  for (int bmp_number = 1; bmp_number < 117; ++bmp_number)
    {
    ui->textEdit->clear();
  // str = QString::number(bmp_number);
    str ="1";
    // Открываем файл изображения .bmp
    QFile file("/home/viktor/Загрузки/imageye2/scale_peyzaji/black-white/"+str+".bmp");
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Ошибка открытия файла";
     //   return 1;
    }

    // Создаем объект QImage из файла
    QImage img;
    if (!img.load(&file, "BMP")) {
        qDebug() << "Ошибка загрузки изображения";
       // return 1;
    }
//########################################################################################################
    // Перебираем пиксели изображения
    for (int y = 0; y < img.height(); ++y) 
    {
        for (int x = 0; x < img.width(); ++x) 
        {
ui->textEdit->append(QString::number(img.pixel(x, y)));
        }
    }
//########################################################################################################
// Теперь надо из начальных случайно сгенерированных нейронов от 100 до 250 дописать в textedit в конец
   QFile file2("/home/viktor/my_projects_qt_2/zapolnenie_nejronov_sluchajnymi_nachalnymi_zaryadami_4/neyroni.txt"); // имя файла с числами
if (file2.open(QFile::ReadOnly | QFile::Text)) {
    QTextStream stream(&file2);
    int lineNumber = 0;
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        lineNumber++;
        if (lineNumber >= 100 && lineNumber <= 250) {
            bool ok;
            int number = line.toInt(&ok);
            if (ok) {
                ui->textEdit->append(QString::number(number) //+ "\n"
                );
            } else {
                qDebug() << "Invalid number at line" << lineNumber;
            }
        }
    }
    file2.close();
} 
//########################################################################################################
// Теперь надо в файл     
    
    
    } // for файлы
} // Dialog::Dialog(QWidget *parent)

Dialog::~Dialog()
{
    delete ui;
}

