#include "test.h"
#include "ui_test.h"

test::test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    ce=new createEnvironment();
    connect(ce,SIGNAL(envName(string)),this,SLOT(getEnvName(string)));
}
void test::getEnvName(string str){
    cout<<"mAINWINDOW  "<<str<<endl;
    emit setEnvName(str);
}
void test::menuClicked(QAction * menu){
    cout<<menu->text().toStdString()<<endl;

    if(menu->text().toStdString()=="Enviourment"){
        ce->show();
//        emit setEnvName("Atul");
    }
//    else if(menu->text().toStdString()=="Robot"){
//        cr->show();
//    }
//    emit setEnvName("Atul");
}

test::~test()
{
    delete ui;
}
