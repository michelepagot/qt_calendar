#include "mainwindow.h"
#include "daydata.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setCentralWidget(ui->calendarWidget);

    this->m_reg = new TimeRegister(2022);
}

MainWindow::~MainWindow()
{
    delete this->m_reg;
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->label_Day->setText(QString("Day %1").arg(date.day()));
    // load the day of the month data in the edit text if data is available
    QString msg = QString("");
    if(this->m_reg->have(date))
    {
        msg = this->m_reg->getMessage(date);
    }
    ui->textEdit_currentDate->setText(msg);
}


void MainWindow::on_calendarWidget_currentPageChanged(int year, int month)
{
    ui->label_Month->setText(QString("Year %1 Month %2").arg(year).arg(month));
    // load the month data
}


void MainWindow::on_pushButton_save_clicked()
{
    QTextCharFormat format;
    format.setBackground(QBrush(Qt::gray));
    QDate selected_date = ui->calendarWidget->selectedDate();

    if(! this->m_reg->have(selected_date))
    {
        DayData *d = new DayData(selected_date, ui->textEdit_currentDate->toPlainText());
        if(this->m_reg->add(d))
        {
            ui->calendarWidget->setDateTextFormat(selected_date, format);
        }
    }
}


void MainWindow::on_pushButton_delete_clicked()
{
    QTextCharFormat format;
    format.setBackground(QBrush(Qt::white));
    QDate selected_date = ui->calendarWidget->selectedDate();

    ui->textEdit_currentDate->setText(QString(""));

    if(this->m_reg->have(selected_date))
    {
        if(this->m_reg->remove(selected_date))
        {
            ui->calendarWidget->setDateTextFormat(selected_date, format);
        }
    }
}

void MainWindow::on_pushButton_setDay_clicked()
{
    return;
}

