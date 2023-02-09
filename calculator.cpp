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

void Calculator::on_pushButton_1_clicked() {
    variable.push_back(1);
    //ui->text_1var->document()->setPlainText("1");
}

void Calculator::on_pushButton_equal_clicked() {
    int hui = ui->comboBox->currentText().toInt();

    QMessageBox::information(this, QString("Shaseasd"), QString::number(hui));
}
