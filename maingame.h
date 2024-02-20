#ifndef MAINGAME_H
#define MAINGAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QObject>
#include <QGraphicsTextItem>

class Cursor;

class MainGame
{
    int game[6][6];
    int randomData[18][2];
    QGraphicsPixmapItem backImage[6][6];
    QGraphicsPixmapItem gameImage[6][6];
    QGraphicsTextItem* score1;
    QGraphicsTextItem* moves1;
    QGraphicsTextItem* winner;
    QString name;
    QGraphicsTextItem* user;
    QGraphicsPixmapItem photo;
    Cursor* cursor1;
    int score = 0;
    int moves = 0;
    int rowFirst, colFirst;

public:
    bool indelay = false;
    MainGame(QString name, QPixmap pic);
    QGraphicsView* view1;
    QGraphicsScene* scene1;
    void generaterandomImage();
    QGraphicsPixmapItem* getGameImage();
    QGraphicsPixmapItem* getBackImage();
    void gameOver();
    int* getGame();
    void showAllCards();
    void hideAllCards();
    void setImage();
    void firstSpace(int row, int col);
    void secondSpace(int row, int col);
    void delay(int sec);
};

#endif // MAINGAME_H
