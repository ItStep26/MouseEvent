#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //asdas
    ui->setupUi(this);
    timerForPollMouse.setInterval(100);
    connect(&timerForPollMouse, &QTimer::timeout, &pollMouseWaiting, &QEventLoop::quit);
    ui->lcdNumberCursorPosX->setDecMode();
    ui->lcdNumberCursorPosY->setDecMode();
    ui->lcdNumberCursorPosX->setDigitCount(4);
    ui->lcdNumberCursorPosY->setDigitCount(4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    //qDebug()<<"mouse DoubleClick";
    if (event->button() == Qt::LeftButton)
    {
        ui->labelInfoClick->setText(QString("left button press DoubleClick"));
        //qDebug()<<"left button press DoubleClick";
        //QMessageBox::information(this, "mousePressEvent", "Qt::LeftButton");
    }
    else if(event->button() == Qt::RightButton)
    {
        ui->labelInfoClick->setText(QString("right button press DoubleClick"));
        //qDebug()<<"right button press DoubleClick";
        //QMessageBox::information(this, "mousePressEvent", "Qt::RightButton");
    }
    else if(event->button() == Qt::MiddleButton)
    {
        ui->labelInfoClick->setText(QString("mid button press DoubleClick"));
        //qDebug()<<"mid button press DoubleClick";
        //QMessageBox::information(this, "mousePressEvent", "Qt::MiddleButton");
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    ui->labelInfoCursorePosition->setText("Mouse pos:" + QString::number(event->pos().x()) + " "
                                                                + QString::number(event->pos().y()));
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
//    if (event->button() == Qt::LeftButton)
//    {
//        qDebug()<<"left button press";
//        //QMessageBox::information(this, "mousePressEvent", "Qt::LeftButton");
//    }
//    else if(event->button() == Qt::RightButton)
//    {
//        qDebug()<<"right button press";
//        //QMessageBox::information(this, "mousePressEvent", "Qt::RightButton");
//    }
//    else if(event->button() == Qt::MiddleButton)
//    {
//        qDebug()<<"mid button press";
//        //QMessageBox::information(this, "mousePressEvent", "Qt::MiddleButton");
    //    }
}

void MainWindow::pollMouse()
{


    while ( true )
    {
        QPoint mouseLoc = QCursor::pos();
        ui->lcdNumberCursorPosX->display(mouseLoc.x());
        ui->lcdNumberCursorPosY->display(mouseLoc.y());
        //qDebug() << "Mouse position global: x,y"  << mouseLoc.x() << mouseLoc.y();
        timerForPollMouse.start();
        pollMouseWaiting.exec();
    }
}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"Ok is clicked";
}

void MainWindow::buttonOkIsPressed()
{
    qDebug()<<"Ok is pressed";
}

void MainWindow::buttonOkIsReleased()
{
     qDebug()<<"Ok is released";
}


void MainWindow::on_cursorTrackingButton_clicked()
{
    this->pollMouse();
}

