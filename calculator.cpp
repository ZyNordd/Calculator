#include "calculator.h"
#include "./ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->text_1var, &QLineEdit::textChanged, this, &Calculator::onTextEdit);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::onTextEdit(const QString& text) {
    //QMessageBox::information(this, text, text);
}


double Calculator::make_var(int system, QString numberQstring) {
    std::string number = numberQstring.toStdString();
    std::vector<int> integer;
    std::vector<int> fractional;
    bool isInt = true;
    int startingPoint = 0;
    if (number[0] == '-') startingPoint = 1;

    for (int i = startingPoint; i < number.size(); ++i) {
        if (number[i] == ',' || number[i] == '.') {
            isInt = false;
            continue;
        }
        if (isInt) {
            if (number[i] == 'A' || number[i] == 'a') integer.push_back(10);
            else if (number[i] == 'B' || number[i] == 'b') integer.push_back(11);
            else if (number[i] == 'C' || number[i] == 'c') integer.push_back(12);
            else if (number[i] == 'D' || number[i] == 'd') integer.push_back(13);
            else if (number[i] == 'E' || number[i] == 'e') integer.push_back(14);
            else if (number[i] == 'F' || number[i] == 'f') integer.push_back(15);
            else integer.push_back((int)number[i] - 48);
        }
        else {
            if (number[i] == 'A' || number[i] == 'a') fractional.push_back(10);
            else if (number[i] == 'B' || number[i] == 'b') fractional.push_back(11);
            else if (number[i] == 'C' || number[i] == 'c') fractional.push_back(12);
            else if (number[i] == 'D' || number[i] == 'd') fractional.push_back(13);
            else if (number[i] == 'E' || number[i] == 'e') fractional.push_back(14);
            else if (number[i] == 'F' || number[i] == 'f') fractional.push_back(15);
            else fractional.push_back((int)number[i] - 48);
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

void Calculator::save_first() {
    first_var = make_var(ui->comboBox->currentText().toInt(), ui->text_1var->text());

    if (operation_type == 2) {
        first_var *= (-1);
    }

    ui->text_1var->setText("");
    variable = "";
}

void Calculator::save_second() {
    second_var = make_var(ui->comboBox->currentText().toInt(), ui->text_1var->text());
    ui->text_1var->setText("");
    variable = "";
}

void Calculator::on_pushButton_1_clicked() {
    variable.push_back('1');
    ui->text_1var->setText(ui->text_1var->text() + "1");
}

void Calculator::on_pushButton_2_clicked() {
    variable.push_back('2');
    ui->text_1var->setText(ui->text_1var->text() + "2");
}

void Calculator::on_pushButton_3_clicked() {
    variable.push_back('3');
    ui->text_1var->setText(ui->text_1var->text() + "3");
}

void Calculator::on_pushButton_4_clicked() {
    variable.push_back('4');
    ui->text_1var->setText(ui->text_1var->text() + "4");
}

void Calculator::on_pushButton_5_clicked() {
    variable.push_back('5');
    ui->text_1var->setText(ui->text_1var->text() + "5");
}

void Calculator::on_pushButton_6_clicked() {
    variable.push_back('6');
    ui->text_1var->setText(ui->text_1var->text() + "6");
}

void Calculator::on_pushButton_7_clicked() {
    variable.push_back('7');
    ui->text_1var->setText(ui->text_1var->text() + "7");
}

void Calculator::on_pushButton_8_clicked() {
    variable.push_back('8');
    ui->text_1var->setText(ui->text_1var->text() + "8");
}

void Calculator::on_pushButton_9_clicked() {
    variable.push_back('9');
    ui->text_1var->setText(ui->text_1var->text() + "9");
}

void Calculator::on_pushButton_A_clicked() {
    variable.push_back('A');
    ui->text_1var->setText(ui->text_1var->text() + "A");
}

void Calculator::on_pushButton_B_clicked() {
    variable.push_back('B');
    ui->text_1var->setText(ui->text_1var->text() + "B");
}

void Calculator::on_pushButton_C_clicked() {
    variable.push_back('C');
    ui->text_1var->setText(ui->text_1var->text() + "C");
}

void Calculator::on_pushButton_D_clicked() {
    variable.push_back('D');
    ui->text_1var->setText(ui->text_1var->text() + "D");
}

void Calculator::on_pushButton_E_clicked() {
    variable.push_back('E');
    ui->text_1var->setText(ui->text_1var->text() + "E");
}

void Calculator::on_pushButton_F_clicked() {
    variable.push_back('F');
    ui->text_1var->setText(ui->text_1var->text() + "F");
}

void Calculator::on_pushButton_0_clicked() {
    variable.push_back('0');
    ui->text_1var->setText(ui->text_1var->text() + "0");
}

void Calculator::on_pushButton_AC_clicked() {
    while(!variable.empty()) variable.pop_back();
    ui->text_1var->clear();
}

void Calculator::on_pushButton_delete_clicked() {
    if (!variable.empty()) {
        variable.pop_back();
    }
    ui->text_1var->backspace();
}

void Calculator::on_pushButton_plus_clicked() {
    save_first();
    operation_type = 1;
}

void Calculator::on_pushButton_minus_clicked() {
    if (operation_type == 2) {
        save_first();
    }
    else {
        if (ui->text_1var->text() != "") {
            operation_type = 2;
            save_first();
        }
        else {
            operation_type = 2;
            ui->text_1var->setText(ui->text_1var->text() + "-");
        }
    }
}

void Calculator::on_pushButton_multiply_clicked() {
    save_first();
    operation_type = 3;
}

void Calculator::on_pushButton_divide_clicked() {
    save_first();
    operation_type = 4;
}

void Calculator::on_pushButton_point_clicked() {
    variable.push_back('.');
    ui->text_1var->setText(ui->text_1var->text() + "."); 
}

void Calculator::on_pushButton_equal_clicked() {
    save_second();
    switch (operation_type) {
    case 1:
        answer = first_var + second_var;
        break;
    case 2:
        answer = first_var - second_var;
        break;
    case 3:
        answer = first_var * second_var;
        break;
    case 4:
        answer = first_var / second_var;
        break;
    }
    ui->text_1var->setText(QString::number(answer));
    QMessageBox::information(this, QString("Shaseasd"), QString::number(first_var) + " " + QString::number(second_var) + " " + QString::number(answer));
    operation_type = 0;
}
