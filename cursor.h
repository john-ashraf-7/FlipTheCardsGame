#ifndef CURSOR_H
#define CURSOR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include "maingame.h"
#include <QKeyEvent>

class Cursor: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Cursor(MainGame* main1);
    bool spaceFirst = true;
public slots:
    void keyPressEvent(QKeyEvent* event);
private:
    int rowIndex, colIndex;
    MainGame* main1;
    bool yFirst = true;

};

#endif // CURSOR_H
