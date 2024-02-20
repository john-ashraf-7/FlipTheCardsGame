#include "cursor.h"
#include <QDebug>

Cursor::Cursor(MainGame* main1)
{
    rowIndex = 0;
    colIndex = -1;

    QPixmap controlpix(":/new/pics/curor.png");
    controlpix = controlpix.scaledToWidth(40);
    controlpix = controlpix.scaledToHeight(60);

    setPixmap(controlpix);

    this->main1 = main1;
}

void Cursor::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (colIndex > -1)
        {
            setOpacity(100);
            colIndex--;
            setPos(x()-100, y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if(colIndex < 6 - 1)
        {
            setOpacity(100);
            colIndex++;
            setPos(x()+100, y());
        }
    }
    if (event->key() == Qt::Key_Up)
    {
        if (rowIndex > 0)
        {
            setOpacity(100);
            rowIndex--;
            setPos(x(), y()-70);
        }
    }
    else if (event->key() == Qt::Key_Down)
    {
        if (rowIndex < 6 - 1)
        {
            setOpacity(100);
            rowIndex++;
            setPos(x(), y()+70);
        }
    }
    else if (event->key() == Qt::Key_S){

        if(main1->indelay == false){
            if(yFirst){
                setOpacity(0);
                main1->showAllCards();
                yFirst = false;
                spaceFirst = true;
            }
            else{
                setOpacity(100);
                main1->hideAllCards();
                yFirst = true;
                spaceFirst = true;
            }
        }
    }
    else if (event->key() == Qt::Key_Space){
        if(yFirst == true){
            if(spaceFirst){
                main1->firstSpace(rowIndex, colIndex);
                spaceFirst = false;
            }
            else{
                main1->secondSpace(rowIndex, colIndex);
                spaceFirst = true;
            }
        }
    }
}
