#include "CaptureScreen.h"
CaptureScreen::CaptureScreen(QWidget *parent)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    setAttribute(Qt::WA_QuitOnClose, true);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setCursor(Qt::CrossCursor);
    const QList<QScreen*> &screens = QApplication::screens();
    QRegion virBox;
    for(auto *screen : screens)
    {
        virBox += screen->geometry();
    }
    setFixedSize(virBox.boundingRect().size());
    QScreen *screen = QApplication::primaryScreen();
    const QRect &rect = screen->availableGeometry();
    QWidget widget(nullptr, Qt::Desktop);
    widget.setVisible(false);
    widget.setGeometry(geometry());
    m_originPixmap = QApplication::primaryScreen()->grabWindow(widget.winId(),rect.x(), rect.y(), width(), height());
}

void CaptureScreen::pixmapChanged(const QPixmap &pix)
{
    // if(!QDir().exists(DOWNLOAD_DIR_FULL))
    // {
    //     QDir().mkpath(DOWNLOAD_DIR_FULL);
    // }

    // const QString &filename = DOWNLOAD_DIR_FULL + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + JPG_FILE;
    // pix.save(filename, nullptr, 100);

    // OCRThreadItem *item = new OCRThreadItem(this);
    // item->m_index = m_fileList.count();
    // item->m_path = filename;

    // QLabel *ll = new QLabel(m_ui->pixScrollAreaWidget);
    // ll->setPixmap(pix.scaled(405, 405, Qt::KeepAspectRatio));
    // m_ui->pixScrollAreaWidgetLayout->addWidget(ll);
    // item->m_obj = ll;

    // m_fileList << item;
}


void CaptureScreen::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    m_ptCursor.setX(event->pos().x());
    m_ptCursor.setY(event->pos().y());
    update();
}

void CaptureScreen::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    QPen pen(QColor(0x15, 0x8F, 0xE1), 1);
    painter.setPen(pen);

    painter.drawPixmap(0, 0, width(), height(), m_originPixmap);

    int w = 0, h = 0;
    if(m_isDrawing)
    {
        w = m_ptCursor.x() - m_ptStart.x();
        h = m_ptCursor.y() - m_ptStart.y();
        painter.drawRect(m_ptStart.x() - 1, m_ptStart.y() - 1, w + 1, h + 1);
    }
    else if(m_ptEnd != m_ptStart)
    {
        w = m_ptEnd.x() - m_ptStart.x();
        h = m_ptEnd.y() - m_ptStart.y();
        painter.drawRect(m_ptStart.x() - 1, m_ptStart.y() - 1, w + 1, h + 1);
    }

    QPolygon listMarker;
    listMarker.push_back(QPoint(m_ptStart.x(), m_ptStart.y()));
    listMarker.push_back(QPoint(m_ptStart.x() + w, m_ptStart.y()));
    listMarker.push_back(QPoint(m_ptStart.x(), h + m_ptStart.y()));
    listMarker.push_back(QPoint(m_ptStart.x() + w, h + m_ptStart.y()));

    listMarker.push_back(QPoint(m_ptStart.x() + (w >> 1), m_ptStart.y()));
    listMarker.push_back(QPoint(m_ptStart.x() + (w >> 1), h + m_ptStart.y()));
    listMarker.push_back(QPoint(m_ptStart.x(), m_ptStart.y() + (h >> 1)));
    listMarker.push_back(QPoint(m_ptStart.x() + w, m_ptStart.y() + (h >> 1)));

    pen.setWidth(4);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawPoints(listMarker);
}

void CaptureScreen::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(event->button() == Qt::LeftButton)
    {
        m_ptStart = event->pos();
        m_ptCursor = m_ptStart;
        m_isDrawing = true;
    }
    update();
}

void CaptureScreen::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    if(event->button() == Qt::LeftButton)
    {
        m_ptEnd = event->pos();
        m_isDrawing = false;
    }
}

void CaptureScreen::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        const int width = m_ptEnd.x() - m_ptStart.x();
        const int height = m_ptEnd.y() - m_ptStart.y();
        QScreen *screen = QApplication::primaryScreen();
        const QRect &rect = screen->availableGeometry();
        const QPixmap &pix = QApplication::primaryScreen()->grabWindow(m_ptStart.x() + rect.x(), m_ptStart.y() + rect.y(), width, height);
        pixmapChanged(pix);
        close();
    }
    else if(event->key() == Qt::Key_Escape)
    {
        close();
    }
}
