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

void Calculator::show_var() {
    std::vector<char> real_var(variable);
    //std::reverse(real_var.begin(), real_var.end());
    std::string str(real_var.begin(), real_var.end());
    ui->text_1var->setText(QString::fromStdString(str));
}

double Calculator::make_var(int system, std::vector<char> number) {
    std::vector<int> integer;
    std::vector<int> fractional;
    bool isInt = true;
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] == ',' || number[i] == '.') {
            isInt = false;
            continue;
        }
        if (isInt) {
            integer.push_back((int)number[i] - 48);
        }
        else {
            fractional.push_back((int)number[i] - 48);
        }
    }
    std::reverse(integer.begin(), integer.end());
    double var = 0;
    for (int i = 0; i < integer.size(); ++i) {
        var += (integer[i] * pow(system, i));
    }
    if (!isInt) {
        for (int i = 0; i < fractional.size(); ++i) {
            var += (fractional[i] * pow(system, -(i + 1)));
        }
    }
    return var;
}

void Calculator::on_pushButton_1_clicked() {
    variable.push_back('1');
    show_var();
    //ui->text_1var->document()->setPlainText("1");
}

void Calculator::on_pushButton_2_clicked() {
    variable.push_back('2');
    show_var();
}

void Calculator::on_pushButton_3_clicked() {
    variable.push_back('3');
    show_var();
}

void Calculator::on_pushButton_4_clicked() {
    variable.push_back('4');
    show_var();
}

void Calculator::on_pushButton_5_clicked() {
    variable.push_back('5');
    show_var();
}

void Calculator::on_pushButton_6_clicked() {
    variable.push_back('6');
    show_var();
}

void Calculator::on_pushButton_7_clicked() {
    variable.push_back('7');
    show_var();
}

void Calculator::on_pushButton_8_clicked() {
    variable.push_back('8');
    show_var();
}

void Calculator::on_pushButton_9_clicked() {
    variable.push_back('9');
    show_var();
}

void Calculator::on_pushButton_A_clicked() {
    variable.push_back('A');
    show_var();
}

void Calculator::on_pushButton_B_clicked() {
    variable.push_back('B');
    show_var();
}

void Calculator::on_pushButton_C_clicked() {
    variable.push_back('C');
    show_var();
}

void Calculator::on_pushButton_D_clicked() {
    variable.push_back('D');
    show_var();
}

void Calculator::on_pushButton_E_clicked() {
    variable.push_back('E');
    show_var();
}

void Calculator::on_pushButton_F_clicked() {
    variable.push_back('F');
    show_var();
}

void Calculator::on_pushButton_0_clicked() {
    variable.push_back('0');
    show_var();
}

void Calculator::on_pushButton_AC_clicked() {
    while(!variable.empty()) variable.pop_back();
    show_var();
}

void Calculator::on_pushButton_delete_clicked() {
    variable.pop_back();
    show_var();
}

void Calculator::on_pushButton_plus_clicked() {

}

void Calculator::on_pushButton_point_clicked() {
    variable.push_back('.');
    show_var();
}

void Calculator::on_pushButton_equal_clicked() {
    int hui = ui->comboBox->currentText().toInt();
    make_var(ui->comboBox->currentText().toInt(), variable);
    //
    QMessageBox::information(this, QString("Shaseasd"), QString::number(make_var(ui->comboBox->currentText().toInt(), variable)));
}
