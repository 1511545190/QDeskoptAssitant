#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isFocusing(false) // Initially, not focusing
{
    ui->setupUi(this);
    ui->btnStartFocus->setText("开始专注"); // Set initial button text
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStartFocus_clicked()
{
    if (isFocusing) {
        // Already focusing, now stop focus
        isFocusing = false;
        ui->btnStartFocus->setText("开始专注");
        QMessageBox::information(this, "提示", "专注结束！");
    } else {
        // Not focusing, now start focus
        isFocusing = true;
        ui->btnStartFocus->setText("结束专注");
        QMessageBox::information(this, "提示", "开始专注啦！");
    }
}
