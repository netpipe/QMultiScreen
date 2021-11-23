#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;


    //xrandr | grep " connected"


}



void MainWindow::on_pushButton_clicked()
{
    QProcess::execute("bash", QStringList() << "-c" << "xrandr --output HDMI-2 --brightness 1.0 --gamma 1.0:1.00:1.00"  );

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    //qDebug() << arg1.toLatin1();
    QProcess::execute("bash", QStringList() << "-c" << "xrandr --output HDMI-2 --gamma " + arg1.toLatin1() );

            //xrandr --output "HDMI-2" --brightness 1.2


}

void MainWindow::on_brightness_sliderReleased()
{
    float k = ui->brightness->value();
    k = k / 100;
  //  ui->brightlbl->setText(QString::number(QString::number(ui->brightness->value()/100).toFloat()) );
    QProcess::execute("bash", QStringList() << "-c" << "xrandr --output HDMI-2 --brightness " + QString::number(k) );

}

void MainWindow::on_brightness_valueChanged(int value)
{
    float k = value;
    k = k / 100;
    ui->brightlbl->setText(QString::number(k) );

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}
