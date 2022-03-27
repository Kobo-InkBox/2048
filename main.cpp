#include "gui/mainwindow.h"
#include <QApplication>

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QScreen>
#include <QFile>
#include "core/board.h"
#include "gui/qgameboard.h"

#include "gui/qgameoverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));
    QGameBoard board;
    QApplication::setFont(QFont("u001"));
    const QScreen * screen = qApp->primaryScreen();
    board.setGeometry(QRect(QPoint(0,0), screen->geometry ().size()));
    board.show();

    QApplication::setStyle("windows");
    QFile stylesheetFile(":/eink.qss");
    stylesheetFile.open(QFile::ReadOnly);
    board.setStyleSheet(stylesheetFile.readAll());
    stylesheetFile.close();

    return a.exec();
}
