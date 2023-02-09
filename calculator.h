#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMessageBox>
#include <QMainWindow>

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
    Ui::Calculator *ui;

private slots:
    void on_pushButton_equal_clicked();
};
#endif // CALCULATOR_H
