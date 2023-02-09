#include "calculator.h"
#include "./ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_pushButton_equal_clicked() {
    QMessageBox::information(this, QString("Shaseasd"), ui->comboBox->currentText());
}
