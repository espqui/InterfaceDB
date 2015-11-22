#include "interface.h"
#include "ui_interface.h"


using namespace std;
Interface::Interface(QWidget *parent){

    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);
    scene = new QGraphicsScene();


    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);
    scene->setSceneRect(0,0,WINDOWS_WIDTH,WINDOWS_HEIGHT);
    QPixmap pix(BACKGROUND_IMAGE);
     scene->addPixmap(pix);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Button * files = new Button(QString("newScheme"));
    files->setPos(20, 550);
    connect(files,SIGNAL(clicked()),this,SLOT(newTable()));
    scene->addItem(files);

    Button * quit = new Button(QString("Quit"));
    quit->setPos(800, 550);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);



{


    titleText= new QGraphicsTextItem(QString("Instituto Tecnologico de Costa Rica"));
    titleFont.setStyleName("comic sans");
    titleText->setDefaultTextColor(QColor(255,255,255));
    titleFont.setPixelSize(30);
    titleText->setFont(titleFont);
     txPos = this->width()/2 - titleText->boundingRect().width()/2;
     tyPos=5;
    titleText->setPos(txPos,tyPos);

    scene->addItem(titleText);


    titleText= new QGraphicsTextItem(QString("Algoritmos y Estructuras de datos 2"));
    titleText->setDefaultTextColor(QColor(255,255,255));
    titleFont.setPixelSize(25);
    titleText->setFont(titleFont);
    txPos = this->width()/2 - titleText->boundingRect().width()/2;
    tyPos=60;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    titleText= new QGraphicsTextItem(QString("Profesor"));
    titleText->setDefaultTextColor(QColor(255,255,255));
    titleText->setFont(titleFont);
    txPos = this->width()/2 - titleText->boundingRect().width()/2;
    tyPos=120;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    titleText= new QGraphicsTextItem(QString("Marco Rivera Meneses:"));
    titleText->setDefaultTextColor(QColor(255,255,255));
    titleText->setFont(titleFont);
    txPos = this->width()/2 - titleText->boundingRect().width()/2;
    tyPos=150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

     titleText= new QGraphicsTextItem(QString("inmemDB"));
     titleText->setDefaultTextColor(QColor(255,255,255));
    titleFont.setPixelSize(30);
    titleText->setFont(titleFont);
    txPos = this->width()/2 - titleText->boundingRect().width()/2;
    tyPos=290;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    titleText= new QGraphicsTextItem(QString("Integrantes"));
    titleText->setDefaultTextColor(QColor(255,255,255));
    titleFont.setPixelSize(25);
   titleText->setFont(titleFont);
   txPos = this->width()/2 - titleText->boundingRect().width()/2;
   tyPos=390;
   titleText->setPos(txPos,tyPos);
   scene->addItem(titleText);

  titleText= new QGraphicsTextItem(QString("Bryan Masís Mora"));
  titleText->setDefaultTextColor(QColor(255,255,255));
  titleFont.setPixelSize(20);

  titleText->setFont(titleFont);
  txPos = this->width()/2 - titleText->boundingRect().width()/2;
  tyPos=450;
  titleText->setPos(txPos,tyPos);
  scene->addItem(titleText);

  titleText= new QGraphicsTextItem(QString("Cristian Castillo Mcquiddy"));
    titleFont.setPixelSize(20);
  titleText->setDefaultTextColor(QColor(255,255,255));
  titleText->setFont(titleFont);
  txPos = this->width()/2 - titleText->boundingRect().width()/2;
  tyPos=490;
  titleText->setPos(txPos,tyPos);
  scene->addItem(titleText);


  titleText= new QGraphicsTextItem(QString("Geovanny Espinoza Quiros"));
    titleFont.setPixelSize(20);
  titleText->setDefaultTextColor(QColor(255,255,255));
  titleText->setFont(titleFont);
  txPos = this->width()/2 - titleText->boundingRect().width()/2;
  tyPos=530;
  titleText->setPos(txPos,tyPos);
  scene->addItem(titleText);


  titleText= new QGraphicsTextItem(QString("Santiago Gamboa Ramírez"));
    titleFont.setPixelSize(20);
  titleText->setDefaultTextColor(QColor(255,255,255));
  titleText->setFont(titleFont);
  txPos = this->width()/2 - titleText->boundingRect().width()/2;
  tyPos=570;
  titleText->setPos(txPos,tyPos);
  scene->addItem(titleText);

}

}

void Interface::newTable(){

    {
    titleText= new QGraphicsTextItem(QString("inmemDB"));
    titleText->setDefaultTextColor(QColor(255,255,255));
    titleFont.setPixelSize(30);
   titleText->setFont(titleFont);
   txPos = this->width()/2 - titleText->boundingRect().width()/2;
   tyPos=290;
   titleText->setPos(txPos,tyPos);
   scene->addItem(titleText);

    }


    {
        table=new QTableWidget(this);
        table->setColumnCount(3);
        table->setColumnWidth(0,140);
        table->setColumnWidth(1,140);
        table->setColumnWidth(2,140);
        table->setRowCount(rowCount);
        pos.setX(365);
        pos.setY(100);
        table->setFixedSize(450,200);
        table->move(pos);
        item= new QTableWidgetItem();
        item->setText("Field Name");
        table->setHorizontalHeaderItem(0,item);

        //table->setItem(0,0,item);

       item1= new QTableWidgetItem();
       item1->setText("Data Type");
       table->setHorizontalHeaderItem(1,item1);
       //table->setItem(0,0,item);

       item2= new QTableWidgetItem();
       item2->setText("Allow Null");
       item2->setBackgroundColor(Qt::lightGray);
       table->setHorizontalHeaderItem(2,item2);
    }

    bool value;
    profundidad = QInputDialog::getText(NULL ,"inmemDB",  "Scheme Name:", QLineEdit::Normal,"", &value);



    scene->clear();
    lw = new QListWidget(this);
    pos.setX(52);
    pos.setY(100);
    lw->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    lw->move(pos);
    lw->setFixedSize(160,390);
    lw->setVisible(true);
    lw->addItem(profundidad);//Insertar Nombre de Tablas

    QPixmap pix(BACKGROUND_IMAGE1);
     scene->addPixmap(pix);

     Button * files = new Button(QString("OpenScheme"));
     files->setPos(50, 550);
     connect(files,SIGNAL(clicked()),this,SLOT(openScheme()));
     scene->addItem(files);

     Button * quit = new Button(QString("Quit"));
     quit->setPos(800, 550);
     connect(quit,SIGNAL(clicked()),this,SLOT(close()));
     scene->addItem(quit);


}


void Interface::openScheme(){

    {

    QPixmap pix(BACKGROUND_IMAGE2);

     scene->addPixmap(pix);
      titleText= new QGraphicsTextItem("Table name:");
        titleText->setDefaultTextColor(QColor(255,255,255));
        titleFont.setPixelSize(17);
       titleText->setFont(titleFont);
       txPos =330;
       tyPos= 63;
       titleText->setPos(txPos,tyPos);
       scene->addItem(titleText);

       titleText= new QGraphicsTextItem(lw->currentItem()->text());

       titleText->setDefaultTextColor(QColor(255,255,255));
      titleFont.setPixelSize(17);
      txPos = 430;
      tyPos=65;
      titleText->setPos(txPos,tyPos);
      scene->addItem(titleText);

   //table->setItem(0,0,item);


    table->setVisible(true);

    }

    {

{
            pugi::xml_node mensaje= doc.append_child("mensaje");
             mensaje.append_child("protocolo").append_attribute("comando").set_value("crearesquema");
             mensaje.append_child("esquema");
             xml_node esquema= mensaje.child("esquema");
             xml_node config= esquema.append_child("config");
             config.append_attribute("nombre").set_value(lw->currentItem()->text().toStdString().c_str());
             config.append_attribute("clave").set_value("1234");
             config.append_attribute("raid").set_value("noRaid");
              campos =config.append_child("campos");



        }
    Button * addField = new Button(QString("Add Field"));
    addField->setPos(400, 400);
    connect(addField,SIGNAL(clicked()),this,SLOT(addField()));
    scene->addItem(addField);

    Button * quit = new Button(QString("Quit"));
    quit->setPos(800, 550);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);

    Button *  xml = new Button(QString("SetRegister"));
    xml->setPos(700, 400);
    connect(xml,SIGNAL(clicked()),this,SLOT(CrearXml()));
    scene->addItem(xml);


}

}

void Interface::addField(){

    campos.append_child("campo").append_attribute("nombrecampo").set_value(table->item(rowCount-1,0)->text().toStdString().c_str());
    xml_node campo= campos.first_child();

    for(int i=1;i<rowCount;i++){
        campo=campo.next_sibling();
    }

    campo.append_attribute("tipo").set_value(table->item(rowCount-1,1)->text().toStdString().c_str());

    rowCount++;
    table->setRowCount(rowCount);
}

void Interface::addField1(){

    esquema.append_child("registro");

    registro2="Register";

    stringstream c;
    int num=rowCount1;
    rowCount1++;

    QString num1=QString::number(num);

    registro2=registro2+num1;
    string prueba=registro2.toStdString().c_str();
    cout<<prueba<<endl;
    fillTable->setRowCount(rowCount1);

    QTableWidgetItem *item2= new QTableWidgetItem();

    item2->setText(registro2);
    fillTable->setVerticalHeaderItem(rowCount1-1,item2);


      registro.append_child(registro2.toStdString().c_str());
     pugi::xml_node registro1=registro.child(registro2.toStdString().c_str());
     registro1.print(cout);


//      cout<<registro2.toStdString().c_str()<<"*"<<endl;
//      cout<<rowCount<<"**"<<endl;
//      cout<<rowCount1<<"***"<<endl;


     for(int n=0;n<rowCount;n++){

         registro1.append_attribute(fillTable->horizontalHeaderItem(n)->text().toStdString().c_str()).set_value(fillTable->item(rowCount1-2,n)->text().toStdString().c_str());

//         doc.print(cout);
//        string nombre="/home/geovanny/git/Base_Datos (1)/base_datos/mensajes/";
//        nombre=nombre.append(lw->currentItem()->text().toStdString().c_str());
//        nombre=nombre.append(".xml");
//         const char* path(nombre.c_str());
//        const char_t* indent = "\t";

//        unsigned int flags = format_default;
//        pugi::xml_encoding encoding=encoding_auto;
//        cout<<doc.save_file(path,indent,flags,encoding)<<endl;
//         cout<<fillTable->horizontalHeaderItem(n)->text().toStdString().c_str()<<"**"<<endl;
//         cout<<fillTable->item(rowCount1-2,n)->text().toStdString().c_str()<<"***"<<endl;
//         registro1.print(cout);
     }
/*
        for(int n=0;n<rowCount;n++){
             cout<<fillTable->item(rowCount1-2,n)->text().toStdString().c_str()<<"******"<<endl;
              registro1.append_attribute(fillTable->item(rowCount1-2,n)->text().toStdString().c_str()).set_value()

           }

      //cout<<fillTable->item(0,rowCount1+1)->text().toStdString().c_str()<<"***"<<endl;
     /*
      for(int n=0;n<rowCount;n++){
         registro1.append_attribute(fillTable->item(n,rowCount1)->text().toStdString().c_str()).set_value(fillTable->item(n,rowCount1+1)->text().toStdString().c_str());
     }
     */



}

void Interface::CrearXml(  ){

    stringstream ss;
    ss << rowCount;
    string str = ss.str();
     campos.append_attribute("numcampos").set_value(str.c_str());
     cout<<str.c_str()<<"**"<<endl;
     addField();
     campos.print(cout);
     string nombre="/home/geovanny/git/Base_Datos (1)/base_datos/mensajes/";
     nombre=nombre.append(lw->currentItem()->text().toStdString().c_str());
     nombre=nombre.append(".xml");
      const char* path(nombre.c_str());
     const char_t* indent = "\t";

     unsigned int flags = format_default;
     pugi::xml_encoding encoding=encoding_auto;
     cout<<doc.save_file(path,indent,flags,encoding)<<endl;





      string puerto="7080";


          SocketCliente *cliente_xml=new SocketCliente("192.168.1.137",puerto);
          string data="";

          if(cliente_xml->connectar()){
              cout<<"conexion con exito "<<endl;
          }
          else{
              cout<<"Error no se conectaron"<<endl;
          }

              cout<<"data:"<<data<<endl;
              cliente_xml->setMensaje(Prueba(data));










     scene->clear();
     QPixmap pix(BACKGROUND_IMAGE2);
      scene->addPixmap(pix);

    Button * files = new Button(QString("OpenScheme"));
    files->setPos(50, 550);
    connect(files,SIGNAL(clicked()),this,SLOT(openScheme()));
    scene->addItem(files);

    Button * addField1 = new Button(QString("Add Field"));
    addField1->setPos(400, 400);
    connect(addField1,SIGNAL(clicked()),this,SLOT(addField1()));
    scene->addItem(addField1);

    Button * quit = new Button(QString("Quit"));
    quit->setPos(800, 550);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);


    fillTable=new QTableWidget(this);
    fillTable->setRowCount(1);
    fillTable->setColumnCount(table->rowCount());
    pos.setX(365);
    pos.setY(100);
    fillTable->setFixedSize(450,200);
    fillTable->move(pos);

    QTableWidgetItem *item= new QTableWidgetItem();
    item->setText("Registers");
    fillTable->setHorizontalHeaderItem(0,item);

     table->setVisible(false);
     fillTable->setVisible(true);

     esquemas->insert_tail(&doc);


}


void Interface::leerXml(){

}

string Interface::Prueba(string data){

    std::stringstream s;
     doc.save(s,"  ");
     std::cout << "stream contents are:\n" << s.str() << std::endl;
      return s.str().c_str();
}
Interface::~Interface()
{

}
