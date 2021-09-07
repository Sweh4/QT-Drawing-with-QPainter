#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    QPen mPen;
    mPen.setColor(Qt::black);
    mPen.setWidth(3);
    painter.setPen(mPen);

    //Definisan crveni brush
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);

    //Pozadina
    painter.begin(this);
    painter.fillRect(rect(),Qt::yellow);

    //Sajba
    QPainterPath pathS;
    pathS.moveTo(600, 130);
    pathS.arcTo(QRect(300,40,200,180),0,180);
    pathS.moveTo(300, 130);
    pathS.lineTo(245, 135);
    pathS.lineTo(240, 200);
    pathS.lineTo(290, 197);
    pathS.arcTo(QRect(290,155.5,90,90), 180, -180);
    pathS.lineTo(380,205);
    pathS.lineTo(470,205);
    pathS.lineTo(470,205);
    pathS.arcTo(QRect(470,155.5,90,90), 180, -180);
    pathS.lineTo(620,200);
    pathS.lineTo(600,130);

    painter.fillPath(pathS, brush);
    painter.drawPath(pathS);

    //Prozori
    QPainterPath pathP1;
    pathP1.moveTo(310, 130);
    pathP1.arcTo(QRectF(310,50,182,170), 175, -81);
    pathP1.lineTo(395, 130);
    pathP1.lineTo(310, 130);
    painter.fillPath(pathP1, Qt::cyan);
    painter.drawPath(pathP1);

    QPainterPath pathP2;
    pathP2.moveTo(405, 130);
    pathP2.arcTo(QRectF(310,50,182,170), 3, 84);
    pathP2.lineTo(405, 130);
    painter.fillPath(pathP2, Qt::cyan);
    painter.drawPath(pathP2);

    //Guma - lijeva
    painter.setBrush(Qt::gray);
    painter.drawEllipse(300,165,70,70);
    painter.setBrush(Qt::black);
    painter.drawEllipse(310,175,50,50);

    //Guma - desna
    painter.setBrush(Qt::gray);
    painter.drawEllipse(480,165,70,70);
    painter.setBrush(Qt::black);
    painter.drawEllipse(490,175,50,50);

    painter.end();
}
