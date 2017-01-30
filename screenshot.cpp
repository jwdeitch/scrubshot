#include "screenshot.h"
#include <QApplication>
#include <QtWidgets>
#include <cmath>

Screenshot::Screenshot()
{

}


void Screenshot::takeShot(QPoint init_coords, QPoint end_coords) {
    qDebug() << "0";
//    QScreen *screen = QApplication::primaryScreen();
//    if (const QWindow *window = windowHandle()) {
//         qDebug() << "1";
//        screen = window->screen();
//    } else if (!screen) {
//         qDebug() << "2";
//        return;
//    }
// qDebug() << "2";
//    PixelMap = screen->grabWindow(0);

    qDebug() << "iX " << init_coords.x() << "iY" << init_coords.y() << endl;
    qDebug() << "fX " << end_coords.x() << "fY" << end_coords.y() << endl;
    qDebug() << "areaX " << abs(init_coords.x() - end_coords.x()) << "areaY " << abs(init_coords.y() - end_coords.y());
    QScreen *screen = QApplication::primaryScreen();
    PixelMap = screen->grabWindow(QApplication::desktop()->winId(),
    init_coords.x(),
    init_coords.y(),
    30,
    30
    );
    PixelMap.save("/tmp/scrubshot.png");
//    saveScreenshot();

//    PixelMap = screen->grabWindow(QApplication::desktop()->winId(),
//    init_coords.x(),
//    init_coords.y(),
//    abs(init_coords.x() - end_coords.x()),
//    abs(init_coords.y() - end_coords.y())
//    );

}

void Screenshot::grabWholeScreen() {
    QScreen *screen = QApplication::primaryScreen();
    PixelMap = screen->grabWindow(QApplication::desktop()->winId(),0,0);
}

void Screenshot::saveScreenshot()
{
    const QString format = "png";
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += tr("/untitled.") + format;

    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);
    QStringList mimeTypes;
    foreach (const QByteArray &bf, QImageWriter::supportedMimeTypes())
        mimeTypes.append(QLatin1String(bf));
    fileDialog.setMimeTypeFilters(mimeTypes);
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fileName = fileDialog.selectedFiles().first();
    if (!PixelMap.save(fileName)) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(fileName)));
    }
}
