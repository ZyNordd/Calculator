#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMessageBox>
#include <QPlainTextEdit>
#include <QMainWindow>
#include <algorithm>
#include <cmath>
#include <cctype>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    double make_var(int system, QString number);
    void save_first();
    void save_second();

    void showAnswer(int ansSeconds);
    void save_firstMixed();
    void save_secondMixed();
    bool var_sign = 0;
    bool invalidDigit = 0;
    bool invalidSymbol = 0;
    //0 - plus
    //1 - minus
    double first_var = 0;
    double second_var = 0;
    double answer = 0;
    const std::vector<char> validDigit = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
        'A', 'B', 'C', 'D', 'E', 'F'};
    const std::vector<char> validValues = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
        'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F' };
    int operation_type = 0; 
    int first_operandSeconds = 0;
    int second_operandSeconds = 0;
    //1 - сложение
    //2 - вычитание
    //3 - умножение
    //4 - деление
    Ui::Calculator *ui;
    void buttonControl();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_A_clicked();
    void on_pushButton_B_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_D_clicked();
    void on_pushButton_E_clicked();
    void on_pushButton_F_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_multiply_clicked();
    void on_pushButton_divide_clicked();
    void on_pushButton_point_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_ChangeSign_clicked();
    void on_pushButton_minusMixed_clicked();
    void on_pushButton_plusMixed_clicked();
    void on_pushButton_ACMixed_clicked();
};
#endif // CALCULATOR_H
