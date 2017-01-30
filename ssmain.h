#ifndef SSMAIN_H
#define SSMAIN_H

#include <QMainWindow>
#include <QRubberBand>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>

namespace Ui {
class ssMain;
}

class ssMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit ssMain(QWidget *parent = 0);
    ~ssMain();

private slots:
    void exit();

private:
    Ui::ssMain *ui;

    QPoint init_cords;
    QPoint end_cords;
    QPainter painter;

    bool inDrag = false;

    QPixmap pixleMap;


protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
};

#endif // SSMAIN_H
