#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int Button1 = 0;
    int Button2 = 0;
    int Button3 = 0;
    int Button4 = 0;
    int numbers[4];
    int trynum = 0;
private slots:
    void on_btnEins_clicked();

    void on_btnZwei_clicked();

    void on_btnDrei_clicked();

    void on_btnVier_clicked();

    void setNumbers();

    void on_btnNew_clicked();

    void on_btnGuess_clicked();

    void setTryColors();

    void clearTryColors();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
