#include "smiley.h"

Smiley::Smiley(QWidget *parent)
    : QWidget(parent)
{
}

Smiley::~Smiley()
{
}

void Smiley::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(e->rect(), QBrush(Qt::gray));

//    painter.translate(300, 300);
//    painter.scale(0.75, 0.75);
//    painter.rotate(45);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);

    painter.setPen(pen);
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(focusPoint, 300, 300);

    paintEyes(painter);
    paintSmile(painter);
}

void Smiley::mousePressEvent(QMouseEvent *e)
{
    focusPoint = e->pos();
    update();
}

void Smiley::mouseMoveEvent(QMouseEvent *e)
{
    focusPoint = e->pos();
    update();
}

void Smiley::mouseReleaseEvent(QMouseEvent *e)
{
    focusPoint = e->pos();
    update();
}

void Smiley::paintEyes(QPainter &painter)
{
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);

    painter.setPen(pen);
    painter.setBrush(Qt::white);
    painter.drawEllipse(QPoint(focusPoint.rx() - 100 - 15, focusPoint.ry() - 150 - 15), 30, 50);
    painter.drawEllipse(QPoint(focusPoint.rx() + 100 + 15, focusPoint.ry() - 150 - 15), 30, 50);
}

void Smiley::paintSmile(QPainter &painter)
{
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);

    painter.setPen(pen);
    painter.drawArc(QRect(focusPoint.rx() - 200, focusPoint.ry() - 100, 400, 300), 0, -180*16);
}

