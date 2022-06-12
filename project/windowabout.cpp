#include "windowabout.h"
#include "ui_windowabout.h"
#include <QPainter>

WindowAbout::WindowAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowAbout)
{
    ui->setupUi(this);
    setFixedSize(QSize(450, 250));
    ui->aboutEdt->setDisabled(false);
}

WindowAbout::~WindowAbout()
{
    delete ui;
}

static const QPointF firstSide[4] =
{
    QPointF(30, 170),
    QPointF(30, 70),
    QPointF(90, 20),
    QPointF(90, 120)
};

static const QPointF secondSide[4] =
{
    QPointF(100, 120),
    QPointF(100, 20),
    QPointF(160, 70),
    QPointF(160, 170)
};

static const QPointF stat[4] =
{
    QPointF(90, 120),
    QPointF(90, 20),
    QPointF(100, 20),
    QPointF(100, 120)
};

void WindowAbout::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, true);

        QColor colour;

        colour.setNamedColor("#fff8dc");
        QBrush bookCol(colour);
        painter.setBrush(bookCol);
        painter.drawConvexPolygon(firstSide, 4);
        painter.drawConvexPolygon(secondSide, 4);

        colour.setNamedColor("#c68e17");
        bookCol = colour;
        painter.setBrush(bookCol);
        painter.drawConvexPolygon(stat, 4);

//        colour.setNamedColor("#000000");
//        bookCol = colour;
//        painter.setBrush(bookCol);
//        painter.drawLine(40, 80, 100, 30);
}
