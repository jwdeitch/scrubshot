#ifndef SSMAIN_H
#define SSMAIN_H

#include <QMainWindow>
#include "selectionbox.h"

namespace Ui {
class ssMain;
}

class ssMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit ssMain(QWidget *parent = 0);
    ~ssMain();
    void mousePressEvent(QMouseEvent *event);

private slots:
    void exit();

private:
    Ui::ssMain *ui;
    RubberBand *selectionBox;

protected:
//    void mousePressEvent(QMouseEvent* event);
//    void mouseReleaseEvent(QMouseEvent * event);
//    void mouseMoveEvent(QMouseEvent *event);
//    bool eventFilter(QObject* object, QEvent* event);
};

#endif // SSMAIN_H
