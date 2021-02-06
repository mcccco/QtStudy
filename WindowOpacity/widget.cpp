#include "widget.h"
#include "ui_widget.h"
#include <QImage>
#include <QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QImage img("./cat.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->setLineWidth(1);
    //全窗体透明
//    setWindowOpacity(0.5);
    //
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
//    Q_UNUSED(event);

    QPainter painter(this);

    // QColor最后一个参数80代表alpha通道，一般用作透明度
    painter.fillRect(rect(), QColor(0,255, 0, 70));
}

