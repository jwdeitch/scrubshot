#ifndef SSMAIN_H
#define SSMAIN_H

#include <QMainWindow>
#include <QRubberBand>
#include <QMouseEvent>

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

    QPoint *init_cords;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // SSMAIN_H
