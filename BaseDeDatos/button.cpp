#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>


/*
 *Sirve para crear los botones en la parte del menu del juego
 */

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,160,40);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::transparent);
    setBrush(brush);


    //dibujando el texto
    text = new  QGraphicsTextItem(name,this);
    text->setDefaultTextColor(Qt::darkCyan);
    QFont titleFont("comic sans",15);
    text->setFont(titleFont);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    //permite respuestas de evento hover
    setAcceptHoverEvents(true);
}

/*
 *maneja el evento cuando se presiona el mouse
 */

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

/*
 *Maneja el evento cuando el mouse se encuentra encima de algun boton
 */


void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
   // cambia el color a azul
   QBrush brush;
    brush.setStyle(Qt::SolidPattern);
   brush.setColor(Qt::transparent);
    setBrush(brush);
     text->setDefaultTextColor(Qt::white);
}


/*
 *Maneja el evento cuando el mouse no se encuentra encima de algun boton
 */
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    //cambia el color a celeste
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::transparent);
    text->setDefaultTextColor(Qt::darkCyan);
    setBrush(brush);

}
