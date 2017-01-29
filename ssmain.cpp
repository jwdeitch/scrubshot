#include "ssmain.h"
#include "ui_ssmain.h"
#include "qdebug.h"
#include <QMouseEvent>
#include <QRect>
#include <QPoint>

ssMain::ssMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ssMain)
{
    ui->setupUi(this);


    this->setCursor(Qt::CrossCursor);
//    this->setProperty("windowOpacity", 1);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QMainWindow::showMaximized();
    qApp->installEventFilter(this);

    move_rubberband = false;
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    rubberBand->setGeometry(0,0,50,50);
    rubberBand->show();

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
    if(rubberBand->geometry().contains(e->pos()))
    {
        rubberband_offset = e->pos() - rubberBand->pos();
        move_rubberband = true;
    }
}

void ssMain::mouseMoveEvent(QMouseEvent *e)
{
    if(move_rubberband)
    {
        rubberBand->move(e->pos() - rubberband_offset);
    }
}

void ssMain::mouseReleaseEvent(QMouseEvent *e)
{
    move_rubberband = false;
}
