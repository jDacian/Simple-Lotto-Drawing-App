#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <time.h>
#include <QThread>

using namespace std;

int draw_number = 0;

int drawed_number[58] = {};
int draw_marker = 0;

//int d;

string numbers = "";
string num;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->textEdit->setText(QString::fromStdString("dasdasdasdasd \n asdasdadasd"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for(int n=0; n < 58; n++)
        {
            srand((unsigned)time(NULL));        // Generate Random Numbers
            for(int d = 0; d< 5; d++)
            {
                draw_number = 1 + rand()%58;
            }

            if(draw_number == drawed_number[n])
            {
                srand((unsigned)time(NULL));        // Generate Random Numbers
                draw_number = 1 + rand()%58;
                n = 0;
            }
            cout << n << endl << endl;
        }

    drawed_number[draw_marker] = draw_number;
    draw_marker++;

    num = to_string(draw_number);

    numbers = numbers + "\n" + num;

    ui->screen->setText(QString::number(draw_number));
    ui->textEdit->setText(QString::fromStdString(numbers));

    for(int c=0; c < 56; c++)
    {
        cout << drawed_number[c] << " ";
    }
    cout<<endl;
    cout<<drawed_number<<endl;
    QThread::msleep(500);
}

void MainWindow::on_pushButton_2_clicked()
{
    draw_number = 0;
    for(int p=0; p<58; p++)
    {
        drawed_number [p]= 0;
    }
    draw_marker = 0;
    numbers = "";
    ui->screen->setText(QString::fromStdString(""));
    ui->textEdit->setText(QString::fromStdString(""));
}
