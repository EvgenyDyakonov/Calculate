#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_number;
char sumbol;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/icon/icon.ico"));
    connect(ui->pushButton_0,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this, SLOT(digit_numbers()));
    connect(ui->pushButton_revers, SIGNAL(clicked()),this, SLOT(digit_operations()));
    connect(ui->pushButton_procent, SIGNAL(clicked()),this, SLOT(digit_operations()));
    connect(ui->pushButton_clear, SIGNAL(clicked()),this, SLOT(digit_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()),this, SLOT(digit_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()),this, SLOT(digit_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()),this, SLOT(digit_operations()));
    connect(ui->pushButton_del, SIGNAL(clicked()),this, SLOT(digit_operations()));
    connect(ui->pushButton_result, SIGNAL(clicked()),this, SLOT(digit_operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_numbers()
{
    QPushButton *button = (QPushButton*)sender();
    double all_numbers;
    QString new_label;

    if(ui->Show_result->text().contains('.')&&button->text()=="0")
        new_label = ui->Show_result->text()+button->text();
    else{

    all_numbers = (ui->Show_result->text()+button->text()).toDouble();
    new_label = QString::number(all_numbers,'g',15);
    }
    ui->Show_result->setText(new_label);
}

void MainWindow::on_pushButton_point_clicked()
{
    if(!(ui->Show_result->text().contains('.')))
    {
        ui->Show_result->setText(ui->Show_result->text()+".");
    }
}

void MainWindow::digit_operations()
{
    QPushButton *button = (QPushButton*)sender();
    double all_numbers;
    QString new_label;
    all_numbers = (ui->Show_result->text()).toDouble();
    if(button->text() == "+/-")
    {
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers,'g',15);
        ui->Show_result->setText(new_label);
    }
    else if(button->text() == "%")
    {
        all_numbers = all_numbers / 100;
        new_label = QString::number(all_numbers,'g',15);
        ui->Show_result->setText(new_label);
    }

    else if(button->text() == "AC")
    {
        new_label = "0";
        ui->Show_result->setText(new_label);
        first_number = 0;
        sumbol = 0;
    }
    else if(button->text()== "+")
    {
        first_number = all_numbers;
        ui->Show_result->setText("");
        sumbol = '+';
    }
    else if(button->text()== "-")
    {
        first_number = all_numbers;
        ui->Show_result->setText("");
        sumbol = '-';
    }
    else if(button->text()== "x")
    {
        first_number = all_numbers;
        ui->Show_result->setText("");
        sumbol = 'x';
    }
    else if(button->text()== "/")
    {
        first_number = all_numbers;
        ui->Show_result->setText("");
        sumbol = '/';
    }
    else if(button->text()== "=")
    {
        switch (sumbol) {
        case '+':
            all_numbers = all_numbers+first_number;
            new_label = QString::number(all_numbers,'g',15);
            ui->Show_result->setText(new_label);
            break;
        case '-':
            all_numbers = first_number-all_numbers;
            new_label = QString::number(all_numbers,'g',15);
            ui->Show_result->setText(new_label);
            break;
        case 'x':
            all_numbers = all_numbers*first_number;
            new_label = QString::number(all_numbers,'g',15);
            ui->Show_result->setText(new_label);
            break;
        case '/':
            if(all_numbers != 0)
            {
                all_numbers = first_number/all_numbers;
                new_label = QString::number(all_numbers,'g',15);
                ui->Show_result->setText(new_label);
            }
            else
            {
                ui->Show_result->setText("0");
            }
            break;
        default:
           break;
        }
    }
}
