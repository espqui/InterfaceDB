#include "interface.h"
#include <QApplication>
#include <string>




using namespace std;


Interface* w;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    w= new Interface();
    w->show();


    return a.exec();











    //xml_parse_result xml_document::load(path,parse_default, encoding_auto);
    //cout<<result.description()<<endl;
}
