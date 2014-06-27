/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */
#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include <QWidget>
#include <QTimer>


#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h> //write

#include "communicate.h"
#include <iostream>
using namespace std;

namespace Ui {
class communicate;
}

class communicate : public QWidget
{
    Q_OBJECT

private:
    Ui::communicate *ui;
    QTimer *timer;

public:
    communicate(QWidget *parent = 0);
    void send(string str);
    string receive();
    ~communicate();
    void startTimer();
    int count;

    int portNumber;
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[100],msg[100];

public slots:
    void timerSlot();
};

#endif // COMMUNICATE_H
