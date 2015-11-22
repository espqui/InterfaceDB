#include "socketcliente.h"

SocketCliente::SocketCliente(string ip,string puerto)
{
    istringstream num(puerto);
    num>>this->puerto;
    this->ip=ip.c_str();

}

bool SocketCliente::connectar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = ntohs(puerto);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    if((::connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0)
     return false;

    cout<<"Se ha conectado con el servidor"<<endl;
    pthread_t hilo;
    pthread_create(&hilo,0,SocketCliente::controlador,(void *)this);
    pthread_detach(hilo);
    return true;
}


void * SocketCliente::controlador(void *obj)
{
    SocketCliente *padre = (SocketCliente*)obj;
    while (true) {
        string mensaje;
        while (1) {
            char buffer[1000] = {0};
            int bytes = recv(padre->descriptor,buffer,1000,0);
            mensaje.append(buffer,bytes);
            if(bytes <= 0)
            {
                close(padre->descriptor);
                pthread_exit(NULL);
            }
            if(bytes < 1000)
                break;
        }
        cout<<mensaje;
    }
    close(padre->descriptor);
    pthread_exit(NULL);
}

void SocketCliente::setMensaje(string mns)
{
   const char * mess= mns.c_str();
    cout<<"mns: "<<mns<<endl;

    cout << "bytes enviados "<< send(descriptor,mess,mns.size(),0) << endl;
}
