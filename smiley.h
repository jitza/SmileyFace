#ifndef SMILEY_H
#define SMILEY_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

//Created a movable smiley face

class Smiley : public QWidget
{
    Q_OBJECT

public:
    Smiley(QWidget *parent = nullptr);
    ~Smiley();

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    QPoint focusPoint;

    void paintEyes(QPainter &);
    void paintSmile(QPainter &);
};
#endif // SMILEY_H
