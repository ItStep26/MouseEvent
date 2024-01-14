#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTimer>
#include <QEventLoop>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    void pollMouse();

private slots:
    void on_pushButton_clicked();
    void buttonOkIsPressed();
    void buttonOkIsReleased();

    void on_cursorTrackingButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer timerForPollMouse;
    QEventLoop pollMouseWaiting;
};
#endif // MAINWINDOW_H
