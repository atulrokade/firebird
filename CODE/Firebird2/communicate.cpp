/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */

#include "communicate.h"
#include "ui_communicate.h"

communicate::communicate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::communicate)
{
    ui->setupUi(this);
    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),SLOT(timerSlot()));
    count=0;
    bzero((char*)&server,sizeof(server));
    portNumber=5003;
     timer->start(500);
}
void communicate::startTimer(){
//    timer->start(500);
}

void communicate::timerSlot(){

    //    timer->start(500);
    timer->stop();
    while(1){
        cout<<count++<<endl;
    }

/*

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        //        printf("Could not create socket");
        cout<<"Could not create socket"<<endl;
    }
    //    printf("Socket created");
    cout<<"Socket created"<<endl;

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( portNumber );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        //        perror("bind failed. Error");
        cout<<"bind failed. Error"<<endl;

        return ;
    }

    //    printf("Bind done at socket number : %d",portNumber);
    cout<<"Bind done at socket number : "<<portNumber<<endl;

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    //    printf("\n\nWaiting for incoming connections...");
    cout<<"Waiting for incoming connections..."<<endl;

    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);

    if (client_sock < 0)
    {
        //        perror("accept failed");
        cout<<"accept failed"<<endl;
        return ;
    }
    //    puts("Connection accepted");
    cout<<"Connection accepted"<<endl;

    //Receive a message from client
    bzero(&client_message, sizeof(client_message));
    while( (read_size = recv(client_sock , client_message , 100 , 0)) > 0 )

    {

        //        puts("B: ");
        cout<<"B: "<<endl;
        //        puts(client_message);
        cout<<client_message<<endl;
        //        printf("A: ");
        cout<<"A: "<<endl;
        bzero(&msg, sizeof(msg));
        gets(msg);
        //Send the message back to client
        if(write(client_sock , msg , sizeof(msg)) < 0)
        {
            //            puts("Sorry message failed, Client disconnected");
            cout<<"Sorry message failed, Client disconnected"<<endl;
            break;
        }
        bzero(&client_message, sizeof(client_message));
    }

    if(read_size == 0)
    {
        //        puts("Client disconnected");
        cout<<"Client disconnected"<<endl;
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        //        perror("recv failed");
        cout<<"recv failed"<<endl;
    }

*/
}

void communicate::send(string str){
    while(1){
        cout<<"atul"<<endl;
    }
}

communicate::~communicate()
{
    delete ui;
}
