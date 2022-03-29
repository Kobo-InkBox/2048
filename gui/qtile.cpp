#include "gui/qtile.h"
#include "core/tile.h"

#include <QGraphicsDropShadowEffect>

QTile::QTile(Tile* tile)
{
    setAlignment(Qt::AlignCenter);
    this->tile = tile;
}

void QTile::draw()
{
    if (tile == NULL) {
        setText("");
        setStyleSheet("QTile { background: rgb(204,192,179); color: rgb(204,192,179); font: bold; border-radius: 10px; font: 40pt; }");
    } else {
        setText(QString::number(tile->getValue()));
        switch (tile->getValue()) {
        case 2: {
            setStyleSheet("QTile { background: rgb(238,228,218); color: rgb(0,0,0); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 4: {
            setStyleSheet("QTile { background: rgb(209, 182, 134); color: rgb(0,0,0); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 8: {
            setStyleSheet("QTile { background: rgb(236,69,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 16: {
            setStyleSheet("QTile { background: rgb(173,37,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 32: {
            setStyleSheet("QTile { background: rgb(73,37,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 64: {
            setStyleSheet("QTile { background: rgb(0,37,75); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 128: {
            setStyleSheet("QTile { background: rgb(237,131,79); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; }");
            break;
        }
        case 256: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(20);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("QTile { background: rgb(237,110,156); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; }");
            break;
        }
        case 512: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(30);
            dse->setOffset(-1);
           setGraphicsEffect(dse);
            setStyleSheet("QTile { background: rgb(237,110,156); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; }");
            break;
        }
        case 1024: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(40);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("QTile { background: rgb(237,110,156); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 23pt; }");
            break;
        }
        case 2048: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(50);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("QTile { background: rgb(237,110,156); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 23pt; }");
            break;
        }
        default: {
            setStyleSheet("QTile { background: rgb(238,228,218); color: rgb(0,0,0); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        }
    }
}
