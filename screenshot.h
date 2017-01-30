#ifndef SCREENSHOT_H
#define SCREENSHOT_H


#include <QPixmap>
#include <QWidget>

class Screenshot : public QWidget
{
    Q_OBJECT

public:
    Screenshot();
    void takeShot();

private slots:
    void saveScreenshot();

private:
    QPixmap PixelMap;

};






#endif // SCREENSHOT_H
