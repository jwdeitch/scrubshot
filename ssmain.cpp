#include "ssmain.h"
#include "ui_ssmain.h"
#include "qdebug.h"

ssMain::ssMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ssMain)
{
    ui->setupUi(this);
    this->setCursor(Qt::CrossCursor);
    this->setProperty("windowOpacity", 0);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QMainWindow::showMaximized();
    this->setMouseTracking(true);
    qApp->installEventFilter(this);

}

ssMain::~ssMain()
{
    delete ui;
}

void ssMain::exit()
{
    QApplication::quit();
}

void ssMain::mousePressEvent(QMouseEvent *event){



    exit();
}
