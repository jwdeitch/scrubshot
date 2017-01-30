#include "screenshot.h"
#include <QApplication>
#include <QtWidgets>

Screenshot::Screenshot()
{

}


void Screenshot::takeShot() {
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

    QPixmap::grabWindow(QApplication::desktop()->winId(),0,0,
                 QApplication::desktop()->screenGeometry().width(),
                 QApplication::desktop()->screenGeometry().height())
          .save("/Users/jordan1/Desktop/screenShot.png");

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
