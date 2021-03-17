#include "interface.h"
#include "ui_interface.h"

#define DBG false

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
}

Interface::~Interface()
{
    delete ui;
}


void Interface::on_pushButton_calc_clicked()
{
    if (ui->spinBox_a_t->value()==0)
    {
        QMessageBox::critical(this, "Ошибка", "коэффициент 'a' не может быть равен нулю");
        return;
    }
    else
    {
        if (DBG) QMessageBox::information(this,"debug","a!=0");
    }

    std::stringstream ss;


    TRational   a(ui->spinBox_a_t->value(),ui->spinBox_a_b->value()),
                b(ui->spinBox_b_t->value(),ui->spinBox_b_b->value()),
                c(ui->spinBox_c_t->value(),ui->spinBox_c_b->value()),
                x(ui->spinBox_x_t->value(),ui->spinBox_x_b->value());

    if (DBG) QMessageBox::information(this,"debug","Значения a,b,c,x считаны");


    p.set(a,b,c);
    if (DBG) QMessageBox::information(this,"debug","Значения a,b,c переданы классу полинома");


    ss.str("");
    short flag;
    number tmp[2];
    p.roots(flag,tmp[0],tmp[1]);
    switch (flag)
    {
    case 1:
        ss << "x1 = " << tmp[0] << std::endl << "x2 = " << tmp[1] << std::endl;
        break;
    case 2:
        ss << "x1,x2 = " << tmp[0] << std::endl;
        break;
    case 3:
        ss << "The polynomial has no real roots" << std :: endl;
        break;
    case 4:
        ss << "Polynomial roots are not rational" << std :: endl;
        break;
    case 5:
        ss << "x1 = " << tmp[0] << ",x2 not rational";
        break;
    default:
        ss << "Unknown error while calculating roots" << std::endl;
        break;
    }
    ui->lineEdit_roots->setText(QString::fromStdString(ss.str()));
    if (DBG) QMessageBox::information(this,"debug","выведено значение корней");



    ss.str("");
    ss << p.value(x);
    ui->lineEdit_value->setText(QString::fromStdString(ss.str()));
    if (DBG) QMessageBox::information(this,"debug","выведено значение P(x)");


    ui->lineEdit_standart->setText(QString::fromStdString(p.standart()));
    if (DBG) QMessageBox::information(this,"debug","выведена стандартная форма полинома");


    ui->lineEdit_canon->setText(QString::fromStdString(p.canon()));
    if (DBG) QMessageBox::information(this,"debug","выведена каноническая форма полинома");


}
