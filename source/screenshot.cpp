#include "screenshot.h"
#include <QApplication>
#include <QtWidgets>
#include <cmath>

Screenshot::Screenshot()
{}

void Screenshot::takeShot(QRect selectionBox) {
    QScreen *screen = QApplication::primaryScreen();

    PixelMap = screen->grabWindow(
        QApplication::desktop()->winId(),
        selectionBox.normalized().x(),
        selectionBox.normalized().y(),
        selectionBox.width(),
        selectionBox.height()
    );

    if (selectionBox.area == 0) {
        screen->grabWindow(0);
    }

    PixelMap.save("/tmp/scrubshot.png");
//    saveScreenshot();
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
