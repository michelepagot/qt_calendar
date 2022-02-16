#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timeregister.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_calendarWidget_clicked(const QDate &date);

    void on_calendarWidget_currentPageChanged(int year, int month);

    void on_pushButton_setDay_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::MainWindow *ui;
    TimeRegister *m_reg;
};
#endif // MAINWINDOW_H
