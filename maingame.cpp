#include "maingame.h"
#include "cursor.h"
#include <ctime>
#include <cstdlib>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

MainGame::MainGame(QString name, QPixmap pic)
{
    view1 = new QGraphicsView;
    scene1 = new QGraphicsScene;
    view1->setFixedSize(800, 600);
    scene1->setSceneRect(0,0,800,600);
    view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->name = name;
    photo.setPixmap(pic);

    user = new QGraphicsTextItem;
    user->setFont(QFont("times", 16));
    user->setDefaultTextColor(Qt::black);
    user->setPos(20, 20);
    user->setPlainText("Player Name: " + name);
    scene1->addItem(user);

    photo.setPos(680, 20);
    scene1->addItem(&photo);

    generaterandomImage();
    setImage();

    score1 = new QGraphicsTextItem;
    score1->setFont(QFont("times", 16));
    score1->setDefaultTextColor(Qt::blue);
    score1->setPos(150, 550);
    score1->setPlainText("Score: " + QString::number(score));
    scene1->addItem(score1);

    moves1 = new QGraphicsTextItem;
    moves1->setFont(QFont("times", 16));
    moves1->setDefaultTextColor(Qt::red);
    moves1->setPos(600, 550);
    moves1->setPlainText("Openings: " + QString::number(moves));
    scene1->addItem(moves1);

    winner = new QGraphicsTextItem;
    winner->setFont(QFont("times", 20));
    winner->setPos(350, 250);

    cursor1 = new Cursor(this);
    cursor1->setPos(20, 70);
    scene1->addItem(cursor1);

    cursor1->setFlag(QGraphicsItem::ItemIsFocusable);
    cursor1->setFocus();

    view1->setScene(scene1);
    view1->show();
}

void MainGame::generaterandomImage(){
    std::srand(std::time(0));
    for(int i = 0; i < 18; i++){
        int randomNum = (std::rand()% 5) + 1;
        for(int j = 0; j < 2; j++){
            randomData[i][j] = randomNum;
        }
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            game[i][j] = 0;
        }
    }

    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 2; j++){
            bool put = false;
            do{
                int randomRow = (std::rand()% 6);
                int randomCol = (std::rand()% 6);
                if(game[randomRow][randomCol] == 0){
                    game[randomRow][randomCol] = randomData[i][j];
                    put = true;
                }
            }while(put == false);
        }
    }
}

QGraphicsPixmapItem *MainGame::getGameImage()
{
    return *gameImage;
}

QGraphicsPixmapItem *MainGame::getBackImage(){
    return *backImage;
}

int* MainGame::getGame(){
    return *game;
}

void MainGame::setImage(){
    QPixmap back(":/new/pics/Back.jpg");
    back = back.scaled(40, 60);
    QPixmap Goose(":/new/pics/Goose.jpg");
    Goose = Goose.scaled(40, 60);
    QPixmap Crab(":/new/pics/Crab.jpg");
    Crab = Crab.scaled(40, 60);
    QPixmap Plant(":/new/pics/Plant.jpg");
    Plant = Plant.scaled(40, 60);
    QPixmap Stick(":/new/pics/Stickjpg.jpg");
    Stick = Stick.scaled(40, 60);
    QPixmap Rock(":/new/pics/Rockjpg.jpg");
    Rock = Rock.scaled(40, 60);

    int x = 120, y = 70;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(game[i][j] == 1){
                backImage[i][j].setPixmap(back);
                backImage[i][j].setPos(x, y);
                gameImage[i][j].setPixmap(Goose);
                gameImage[i][j].setPos(x, y);
                scene1->addItem(&gameImage[i][j]);
                scene1->addItem(&backImage[i][j]);
                gameImage[i][j].hide();
            }
            if(game[i][j] == 2){
                backImage[i][j].setPixmap(back);
                backImage[i][j].setPos(x, y);
                gameImage[i][j].setPixmap(Crab);
                gameImage[i][j].setPos(x, y);
                scene1->addItem(&gameImage[i][j]);
                scene1->addItem(&backImage[i][j]);
                gameImage[i][j].hide();
            }
            if(game[i][j] == 3){
                backImage[i][j].setPixmap(back);
                backImage[i][j].setPos(x, y);
                gameImage[i][j].setPixmap(Plant);
                gameImage[i][j].setPos(x, y);
                scene1->addItem(&gameImage[i][j]);
                scene1->addItem(&backImage[i][j]);
                gameImage[i][j].hide();
            }
            if(game[i][j] == 4){
                backImage[i][j].setPixmap(back);
                backImage[i][j].setPos(x, y);
                gameImage[i][j].setPixmap(Stick);
                gameImage[i][j].setPos(x, y);
                scene1->addItem(&gameImage[i][j]);
                scene1->addItem(&backImage[i][j]);
                gameImage[i][j].hide();
            }
            if(game[i][j] == 5){
                backImage[i][j].setPixmap(back);
                backImage[i][j].setPos(x, y);
                gameImage[i][j].setPixmap(Rock);
                gameImage[i][j].setPos(x, y);
                scene1->addItem(&gameImage[i][j]);
                scene1->addItem(&backImage[i][j]);
                gameImage[i][j].hide();
            }
            x+=100;
        }
        x = 120;
        y+= 70;
    }
}

void MainGame::showAllCards(){
    for(int i = 0; i < 6; i++){
        for(int j = 0 ; j < 6; j++){
            backImage[i][j].hide();
            gameImage[i][j].show();
        }
    }
}

void MainGame::hideAllCards(){
    for(int i = 0; i < 6; i++){
        for(int j = 0 ; j < 6; j++){
            gameImage[i][j].hide();
            backImage[i][j].show();
        }
    }
}

void MainGame::firstSpace(int row, int col){
    if(indelay == false){
        if(game[row][col] == 0){
            return;
        }
        backImage[row][col].hide();
        gameImage[row][col].show();
        rowFirst = row;
        colFirst = col;
        cursor1->setOpacity(0);
        moves++;
        moves1->setPlainText("Openings: " + QString::number(moves));
        gameOver();
    }
}

void MainGame::delay(int sec)
{
    QTime dieTime=  QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainGame::secondSpace(int row, int col){

    if(indelay == false){
        if(game[row][col] == 0){
            return;
        }
        cursor1->setOpacity(0);
        if(row == rowFirst && col == colFirst){
            backImage[row][col].show();
            gameImage[row][col].hide();
            return;
        }
        else{
            backImage[row][col].hide();
            gameImage[row][col].show();
            moves++;
            moves1->setPlainText("Openings: " + QString::number(moves));
            indelay = true;
        }
        delay(1);
        if(game[row][col] == game[rowFirst][colFirst] && game[row][col] != 0){
            game[row][col] = 0;
            game[rowFirst][colFirst] = 0;
            scene1->removeItem(&gameImage[row][col]);
            scene1->removeItem(&gameImage[rowFirst][colFirst]);
            scene1->removeItem(&backImage[row][col]);
            scene1->removeItem(&backImage[rowFirst][colFirst]);
            score+=1;
            score1->setPlainText("Score: " + QString::number(score));
            indelay = false;
            gameOver();
            return;
        }
        else if(game[row][col] != game[rowFirst][colFirst]){
            backImage[row][col].show();
            gameImage[row][col].hide();
            backImage[rowFirst][colFirst].show();
            gameImage[rowFirst][colFirst].hide();
            gameOver();
            indelay = false;
            return;
        }
        else{
            return;
        }
    }
}

void MainGame::gameOver(){

    if(score == 18){
        cursor1->hide();
        winner->setDefaultTextColor(Qt::green);
        winner->setPlainText("You Win!");
        scene1->addItem(winner);
    }
    else if(moves >= 40){
        cursor1->hide();
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                gameImage[i][j].hide();
                backImage[i][j].hide();
            }
        }

        winner->setDefaultTextColor(Qt::red);
        winner->setPlainText("You Lose!");
        scene1->addItem(winner);

    }
}
