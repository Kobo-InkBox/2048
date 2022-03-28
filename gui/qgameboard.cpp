#include "gui/qgameboard.h"
#include "core/board.h"
#include "core/game.h"
#include "gui/qtile.h"
#include "core/tile.h"
#include "gui/qresetbutton.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>
#include <QApplication>

#include <QDebug>

QGameBoard::~QGameBoard()
{
    delete game;
}

QGameBoard::QGameBoard(QWidget *parent) :
    QWidget(parent)
{
    // set default size
    resize(650,450);

    // create the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // will be created in drawBoard()
    boardLayout = NULL;

    // create the game and register as observer
    game = new Game(4);
    game->registerObserver(this);

    // create the gui board and draw it
    gui_board.resize(game->getGameBoard()->getDimension());
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i)
        gui_board[i].resize(game->getGameBoard()->getDimension());
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i)
        for (int j = 0; j < game->getGameBoard()->getDimension(); ++j)
            gui_board[i][j] = NULL;
    drawBoard();

    // create the score widget and add it to the board
    score = new QLabel(QString("SCORE: %1").arg(game->getScore()));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignCenter);

    QHBoxLayout * buttonLayout = new QHBoxLayout(this);
    QHBoxLayout * quitLayout = new QHBoxLayout(this);
    QPushButton * leftBtn = new QPushButton(this);
    QPushButton * rightBtn = new QPushButton(this);
    QPushButton * upBtn = new QPushButton(this);
    QPushButton * downBtn = new QPushButton(this);
    QPushButton * quitBtn = new QPushButton(this);

    leftBtn->setFont(QFont("Noto Mono"));
    rightBtn->setFont(QFont("Noto Mono"));
    upBtn->setFont(QFont("Noto Mono"));
    downBtn->setFont(QFont("Noto Mono"));

    leftBtn->setStyleSheet("padding: 30px");
    rightBtn->setStyleSheet("padding: 30px");
    upBtn->setStyleSheet("padding: 30px");
    downBtn->setStyleSheet("padding: 30px");
    quitBtn->setStyleSheet("padding-left: 40px; padding-right: 40px");

    leftBtn->setText("←");
    rightBtn->setText("→");
    upBtn->setText("↑");
    downBtn->setText("↓");
    quitBtn->setText("Quit");
    connect(leftBtn, SIGNAL(clicked()), SLOT(moveLeft()));
    connect(rightBtn, SIGNAL(clicked()), SLOT(moveRight()));
    connect(upBtn, SIGNAL(clicked()), SLOT(moveUp()));
    connect(downBtn, SIGNAL(clicked()), SLOT(moveDown()));
    connect(quitBtn, SIGNAL(clicked()), SLOT(close()));

    buttonLayout->insertWidget(1, leftBtn, 0);
    buttonLayout->insertWidget(1, rightBtn, 0);
    buttonLayout->insertWidget(1, upBtn, 0);
    buttonLayout->insertWidget(1, downBtn, 0);
    quitLayout->insertWidget(1, quitBtn, 0, Qt::AlignCenter);
    mainLayout->addLayout(buttonLayout, 1);
    mainLayout->addLayout(quitLayout, 2);


    // style sheet of the board
    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
}

void QGameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        game->move(UP);
        break;
    case Qt::Key_Left:
        game->move(LEFT);
        break;
    case Qt::Key_Right:
        game->move(RIGHT);
        break;
    case Qt::Key_Down:
        game->move(DOWN);
        break;
    }
}

void QGameBoard::notify()
{
    if (game->isGameOver())
        gameOverWindow.show();

    if (game->won())
        score->setText(QString("You hit 2048, congratulations! Keep playing to increase your score.\t\t SCORE: %1").arg(game->getScore()));
    else
        score->setText(QString("SCORE: %1").arg(game->getScore()));

    drawBoard();
}

void QGameBoard::drawBoard()
{
    delete boardLayout;
    boardLayout = new QGridLayout();
    for (int i = 0; i < game->getGameBoard()->getDimension(); ++i) {
        for (int j = 0; j < game->getGameBoard()->getDimension(); ++j) {
            delete gui_board[i][j];
            gui_board[i][j] = new QTile(game->getGameBoard()->getTile(i,j));
            boardLayout->addWidget(gui_board[i][j], i, j);
            gui_board[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}


void QGameBoard::resetGame()
{
    game->restart();
    drawBoard();
    score->setText(QString("SCORE: %1").arg(game->getScore()));
    gameOverWindow.hide();
}

void QGameBoard::moveLeft() {
    game->move(LEFT);
}

void QGameBoard::moveRight() {
    game->move(RIGHT);
}

void QGameBoard::moveUp() {
    game->move(UP);
}

void QGameBoard::moveDown() {
    game->move(DOWN);
}
