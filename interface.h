#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <polinom.h>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
    polinom p;

private slots:
    void on_pushButton_calc_clicked();

private:
    Ui::Interface *ui;
};
#endif // INTERFACE_H
