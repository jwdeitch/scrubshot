#include "ssmain.h"
#include "ui_ssmain.h"
#include "qdebug.h"
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QPainter>

ssMain::ssMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ssMain)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QMainWindow::showMaximized();
    this->setCursor(Qt::CrossCursor);

}

ssMain::~ssMain()
{
    delete ui;
}

void ssMain::exit()
{
    QApplication::quit();
}

void ssMain::mousePressEvent(QMouseEvent *e)
{
    if (!inDrag){
        inDrag = true;
        QPoint init(e->x() - 3, e->y()-2);
        init_cords = init;
    }

}

void ssMain::mouseMoveEvent(QMouseEvent *e)
{
    QPoint final(e->x() - 3, e->y()-2);
    end_cords = final;
    update();
}

void ssMain::mouseReleaseEvent(QMouseEvent *e)
{
    inDrag = false;
}

void ssMain::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QRect box(init_cords, end_cords);
    painter.drawRect(box);
}
