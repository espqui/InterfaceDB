#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include<QGraphicsScene>
#include <Constants.h>
#include <QGraphicsView>
#include <QListWidget>
#include <QTableWidget>
#include <QPoint>
#include <QTableWidgetItem>
#include "servidor.h"
#include <iostream>
#include <fstream>
#include <QCoreApplication>
#include <pugixml.hpp>
#include <iostream>
#include <fstream>
#include <rapidjson/rapidjson.h>
#include <button.h>
#include <QGraphicsTextItem>
#include <QInputDialog>
#include <linked_list1.h>
#include <linked_list.h>
#include <sstream>
#include <iostream>
#include <string>
#include <socketcliente.h>
#include <pugixml.hpp>


using namespace std;
using namespace rapidjson;
using namespace pugi;

class Interface : public QGraphicsView
{
    Q_OBJECT

public:
    QGraphicsScene* scene;
    QWidget *parent;
    QPoint pos;





      pugi::xml_encoding encoding;
      const char_t* indent;
      QGraphicsTextItem*  titleText;
       int txPos;
       int tyPos;
     QFont titleFont;
     QString profundidad;
     QFrame *back;
     int rowCount=1;
     int rowCount1=1;
     QString registro2="Register";
     void  print();

    List<xml_document*> * esquemas= new List<xml_document*>;


    explicit Interface(QWidget *parent=0 );
      QListWidget *lw;
      QTableWidget *table;
       QTableWidget *fillTable;
      QTableWidgetItem *item;
       QTableWidgetItem *item1;
        QTableWidgetItem *item2;
        string lector;
        pugi::xml_node esquema;
        pugi::xml_node registro;
        pugi::xml_document doc;
         xml_node campos;
         void leerXml();
         string Prueba(string data);
        ~Interface();
public slots:
 void newTable();
 void openScheme();
 void addField();
 void CrearXml();
 void addField1();




};

#endif // INTERFACE_H
