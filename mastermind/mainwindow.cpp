#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand (time(NULL));
    setFixedSize(465,465);
    setNumbers();
    ui->setupUi(this);
    this->ui->lblWin->hide();
    this->ui->lblLose->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnEins_clicked()
{
    if(Button1==0){
            this->ui->btnEins->setStyleSheet("background-color: blue");
            Button1++;
            return;
    }
    if(Button1==1){
            this->ui->btnEins->setStyleSheet("background-color: red");
            Button1++;
            return;
    }
    if(Button1==2){
            this->ui->btnEins->setStyleSheet("background-color: green");
            Button1++;
            return;
    }
    if(Button1==3){
            this->ui->btnEins->setStyleSheet("background-color: yellow");
            Button1=0;
            return;
    }
}

void MainWindow::on_btnZwei_clicked()
{
    if(Button2==0){
            this->ui->btnZwei->setStyleSheet("background-color: blue");
            Button2++;
            return;
    }
    if(Button2==1){
            this->ui->btnZwei->setStyleSheet("background-color: red");
            Button2++;
            return;
    }
    if(Button2==2){
            this->ui->btnZwei->setStyleSheet("background-color: green");
            Button2++;
            return;
    }
    if(Button2==3){
            this->ui->btnZwei->setStyleSheet("background-color: yellow");
            Button2=0;
            return;
    }
}

void MainWindow::on_btnDrei_clicked()
{
    if(Button3==0){
            this->ui->btnDrei->setStyleSheet("background-color: blue");
            Button3++;
            return;
    }
    if(Button3==1){
            this->ui->btnDrei->setStyleSheet("background-color: red");
            Button3++;
            return;
    }
    if(Button3==2){
            this->ui->btnDrei->setStyleSheet("background-color: green");
            Button3++;
            return;
    }
    if(Button3==3){
            this->ui->btnDrei->setStyleSheet("background-color: yellow");
            Button3=0;
            return;
    }
}

void MainWindow::on_btnVier_clicked()
{
    if(Button4==0){
            this->ui->btnVier->setStyleSheet("background-color: blue");
            Button4++;
            return;
    }
    if(Button4==1){
            this->ui->btnVier->setStyleSheet("background-color: red");
            Button4++;
            return;
    }
    if(Button4==2){
            this->ui->btnVier->setStyleSheet("background-color: green");
            Button4++;
            return;
    }
    if(Button4==3){
            this->ui->btnVier->setStyleSheet("background-color: yellow");
            Button4=0;
            return;
    }
    qDebug() << "b4" << Button4;
}


void MainWindow::setNumbers(){
    numbers[0] = 0 + (rand() % 4);
    numbers[1] = 0 + (rand() % 4);
    numbers[2] = 0 + (rand() % 4);
    numbers[3] = 0 + (rand() % 4);
    qDebug() << "n0" << numbers[0];
    qDebug() << "n1" << numbers[1];
    qDebug() << "n2" << numbers[2];
    qDebug() << "n3" << numbers[3];
}

void MainWindow::on_btnNew_clicked()
{
    trynum = 0;
    setNumbers();
    Button1 = 0;
    Button2 = 0;
    Button3 = 0;
    Button4 = 0;
    clearTryColors();
    this->ui->btnGuess->show();
    this->ui->lblCounter->setText("");
    this->ui->lblWin->hide();
    this->ui->lblLose->hide();
    this->ui->btnEins->setStyleSheet("background-color: #e1e1e1");
    this->ui->btnZwei->setStyleSheet("background-color: #e1e1e1");
    this->ui->btnDrei->setStyleSheet("background-color: #e1e1e1");
    this->ui->btnVier->setStyleSheet("background-color: #e1e1e1");
}

void MainWindow::on_btnGuess_clicked()
{
    int complete = 0;
    int color = 0;

    this->ui->btnEins->setStyleSheet("background-color: #e1e1e1");
    this->ui->btnZwei->setStyleSheet("background-color: #e1e1e1");
    this->ui->btnDrei->setStyleSheet("background-color: #e1e1e1");
    this->ui->btnVier->setStyleSheet("background-color: #e1e1e1");

    setTryColors();

    if(Button1 == numbers[0]){
        complete++;
        Button1 = 5;
    }else if(numbers[0] == Button2 ||numbers[0] == Button3 ||numbers[0] == Button4 ){
        color++;
    }

    if(Button2 == numbers[1]){
        complete++;
        Button2= 5;
    }else if(numbers[1] == Button1 ||numbers[1] == Button3 ||numbers[1] == Button4 ){
        color++;
    }

    if(Button3 == numbers[2]){
        complete++;
        Button3 = 5;
    }else if(numbers[2] == Button1 ||numbers[2] == Button2 ||numbers[2] == Button4 ){
        color++;
    }

    if(Button4 == numbers[3]){
        complete++;
        Button4 = 5;
    }else if(numbers[3] == Button1 ||numbers[3] == Button2 ||numbers[3] == Button3 ){
        color++;
    }



    Button1 = 0;
    Button2 = 0;
    Button3 = 0;
    Button4 = 0;

    QString newColor = QString::number(color);
    QString newComplete = QString::number(complete);


    this->ui->lblCounter->setText("Du hast " + newComplete + " richtig, und " + newColor + " an der Falschen Stelle.");

    if(complete == 4){
        this->ui->lblWin->show();
    }
    if(trynum==12){
        this->ui->lblLose->show();
        this->ui->btnGuess->hide();
    }

    qDebug() << "n0" << numbers[0];
    qDebug() << "n1" << numbers[1];
    qDebug() << "n2" << numbers[2];
    qDebug() << "n3" << numbers[3];

    qDebug() << "color" << color;
    qDebug() << "complete" << complete;
}

void MainWindow::setTryColors(){
    trynum++;

    if(trynum==1){
        if(Button1==0){
            this->ui->try1_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try1_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try1_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try1_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try1_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try1_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try1_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try1_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try1_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try1_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try1_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try1_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try1_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try1_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try1_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try1_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==2){
        if(Button1==0){
            this->ui->try2_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try2_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try2_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try2_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try2_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try2_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try2_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try2_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try2_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try2_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try2_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try2_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try2_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try2_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try2_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try2_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==3){
        if(Button1==0){
            this->ui->try3_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try3_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try3_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try3_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try3_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try3_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try3_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try3_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try3_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try3_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try3_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try3_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try3_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try3_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try3_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try3_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==4){
        if(Button1==0){
            this->ui->try4_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try4_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try4_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try4_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try4_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try4_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try4_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try4_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try4_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try4_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try4_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try4_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try4_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try4_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try4_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try4_4->setStyleSheet("background-color: Green");
        }
    }

    if(trynum==5){
        if(Button1==0){
            this->ui->try5_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try5_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try5_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try5_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try5_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try5_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try5_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try5_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try5_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try5_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try5_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try5_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try5_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try5_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try5_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try5_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==6){
        if(Button1==0){
            this->ui->try6_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try6_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try6_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try6_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try6_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try6_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try6_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try6_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try6_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try6_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try6_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try6_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try6_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try6_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try6_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try6_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==7){
        if(Button1==0){
            this->ui->try7_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try7_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try7_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try7_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try7_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try7_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try7_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try7_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try7_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try7_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try7_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try7_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try7_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try7_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try7_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try7_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==8){
        if(Button1==0){
            this->ui->try8_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try8_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try8_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try8_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try8_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try8_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try8_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try8_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try8_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try8_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try8_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try8_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try8_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try8_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try8_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try8_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==9){
        if(Button1==0){
            this->ui->try9_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try9_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try9_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try9_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try9_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try9_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try9_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try9_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try9_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try9_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try9_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try9_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try9_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try9_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try9_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try9_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==10){
        if(Button1==0){
            this->ui->try10_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try10_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try10_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try10_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try10_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try10_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try10_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try10_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try10_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try10_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try10_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try10_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try10_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try10_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try10_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try10_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==11){
        if(Button1==0){
            this->ui->try11_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try11_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try11_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try11_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try11_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try11_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try11_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try11_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try11_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try11_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try11_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try11_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try11_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try11_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try11_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try11_4->setStyleSheet("background-color: Green");
        }
    }
    if(trynum==12){
        if(Button1==0){
            this->ui->try12_1->setStyleSheet("background-color: Yellow");
        }else if(Button1 == 1){
            this->ui->try12_1->setStyleSheet("background-color: Blue");
        }else if(Button1 == 2){
            this->ui->try12_1->setStyleSheet("background-color: Red");
        }else if(Button1 == 3){
            this->ui->try12_1->setStyleSheet("background-color: Green");
        }
        if(Button2==0){
            this->ui->try12_2->setStyleSheet("background-color: Yellow");
        }else if(Button2 == 1){
            this->ui->try12_2->setStyleSheet("background-color: Blue");
        }else if(Button2 == 2){
            this->ui->try12_2->setStyleSheet("background-color: Red");
        }else if(Button2 == 3){
            this->ui->try12_2->setStyleSheet("background-color: Green");
        }
        if(Button3==0){
            this->ui->try12_3->setStyleSheet("background-color: Yellow");
        }else if(Button3 == 1){
            this->ui->try12_3->setStyleSheet("background-color: Blue");
        }else if(Button3 == 2){
            this->ui->try12_3->setStyleSheet("background-color: Red");
        }else if(Button3 == 3){
            this->ui->try12_3->setStyleSheet("background-color: Green");
        }
        if(Button4==0){
            this->ui->try12_4->setStyleSheet("background-color: Yellow");
        }else if(Button4 == 1){
            this->ui->try12_4->setStyleSheet("background-color: Blue");
        }else if(Button4 == 2){
            this->ui->try12_4->setStyleSheet("background-color: Red");
        }else if(Button4 == 3){
            this->ui->try12_4->setStyleSheet("background-color: Green");
        }
    }
}

void MainWindow::clearTryColors(){
    this->ui->try1_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try1_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try1_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try1_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try2_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try2_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try2_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try2_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try3_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try3_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try3_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try3_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try4_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try4_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try4_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try4_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try5_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try5_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try5_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try5_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try6_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try6_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try6_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try6_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try7_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try7_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try7_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try7_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try8_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try8_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try8_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try8_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try9_1->setStyleSheet("background-color: #e1e1e1");
    this->ui->try9_2->setStyleSheet("background-color: #e1e1e1");
    this->ui->try9_3->setStyleSheet("background-color: #e1e1e1");
    this->ui->try9_4->setStyleSheet("background-color: #e1e1e1");
    this->ui->try10_1->setStyleSheet("background-color:#e1e1e1");
    this->ui->try10_2->setStyleSheet("background-color:#e1e1e1");
    this->ui->try10_3->setStyleSheet("background-color:#e1e1e1");
    this->ui->try10_4->setStyleSheet("background-color:#e1e1e1");
    this->ui->try11_1->setStyleSheet("background-color:#e1e1e1");
    this->ui->try11_2->setStyleSheet("background-color:#e1e1e1");
    this->ui->try11_3->setStyleSheet("background-color:#e1e1e1");
    this->ui->try11_4->setStyleSheet("background-color:#e1e1e1");
    this->ui->try12_1->setStyleSheet("background-color:#e1e1e1");
    this->ui->try12_2->setStyleSheet("background-color:#e1e1e1");
    this->ui->try12_3->setStyleSheet("background-color:#e1e1e1");
    this->ui->try12_4->setStyleSheet("background-color:#e1e1e1");
}
