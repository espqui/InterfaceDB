#ifndef MANEJADOR_MENSAJES_H
#define MANEJADOR_MENSAJES_H


#include "rapidjson/reader.h"
#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

#include <iostream>

using namespace std;

class manejador_mensajes
{
public:
    manejador_mensajes();
    void recibir_mensaje(string mensaje);
    void enviar_mensaje(string mensaje);

private:
    bool json_flag;
};

#endif // MANEJADOR_MENSAJES_H
