#include "qgameoverwindow.h"
#include "qresetbutton.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>
#include <QApplication>

QGameOverWindow::QGameOverWindow(QWidget *parent) :
    QWidget(parent)
{
    QApplication::setFont(QFont("u001"));
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    QLabel* gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel { color: white; font: 40pt; font: bold;} ");
    // reset button
    reset = new QResetButton(this);
    reset->setStyleSheet("padding: 40px; background-color: white; color: black; border-radius: 20px");
    // add game over label to window
    layout->insertWidget(0,gameover,0,Qt::AlignCenter);
    // add reset button to window
    layout->insertWidget(1,reset,0,Qt::AlignCenter);
}

QResetButton* QGameOverWindow::getResetBtn() const
{
    return reset;
}
