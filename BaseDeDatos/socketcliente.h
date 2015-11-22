#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <QObject>
#include <arpa/inet.h>

using namespace std;

class SocketCliente
{
private:
    const char* ip;
    int puerto;
    static void * controlador(void *obj);
    int descriptor;
    sockaddr_in info;
public:
    bool connectar();
    void setMensaje(string msn);
    SocketCliente(string ip,string puerto);
};

#endif // SOCKETCLIENTE_H
