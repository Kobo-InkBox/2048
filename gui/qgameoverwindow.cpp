#include "qgameoverwindow.h"
#include "qresetbutton.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>
#include <QApplication>

QGameOverWindow::QGameOverWindow(QWidget *parent, int score) :
    QWidget(parent)
{
    QApplication::setFont(QFont("u001"));
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    this->setStyleSheet("background-color: #3b3b3b");
    QLabel* gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel { color: white; font: 40pt; font-weight: bold;} ");
    QLabel * scoreLabel = new QLabel(QString("Score: %1").arg(QString::number(score)));
    scoreLabel->setStyleSheet("QLabel { color: white; font: 20pt; font-weight: bold;}");
    scoreLabel->setAlignment(Qt::AlignCenter);
    // reset button
    reset = new QResetButton(this);
    reset->setStyleSheet("padding: 40px; background-color: white; color: black; border-radius: 20px");
    // Add game over label to window
    layout->insertWidget(0,gameover,0,Qt::AlignCenter);
    // Add score label to window
    layout->insertWidget(1,scoreLabel,0,Qt::AlignCenter);
    // Add reset button to window
    layout->insertWidget(2,reset,0,Qt::AlignCenter);
}

QResetButton* QGameOverWindow::getResetBtn() const
{
    return reset;
}
