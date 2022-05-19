#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnBeenden_clicked()
{
    close();
}

void MainWindow::init()
{
    connect(ui->horizontalSlider, &QAbstractSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
}


void MainWindow::on_checkConnect_toggled(bool checked)
{
    if(checked)
    {
        connect(ui->horizontalSlider, &QAbstractSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);

        ui->progressBar->setValue(ui->horizontalSlider->value());
    }
    else
        disconnect(ui->horizontalSlider, &QAbstractSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
}

