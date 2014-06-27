/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */
#include "FireBird.h"
#include "unistd.h"
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "iostream"
#include <time.h>


using namespace std;
	ofstream fout;
	ifstream fin;
	fstream fshare;
	fstream fsem;
	int semaphore;
	int prvsSignal,sSignal;
	int mSignal;
	string command;
	string result;

BOOL DelaymSec(HANDLE hComm, unsigned int mSec){
	//~ mSec*=1000;
	//~ for(long long int i=0;i<mSec*100000;i++);
	//~ usleep(mSec*1000);
	
	clock_t endwait;
	//~ mSec=mSec*0.001;
	endwait = clock () + mSec * CLOCKS_PER_SEC *0.001;
	while (clock() < endwait) ;
	
}
		
void mRead(){
	//~ string tt="/home/atul/shared_files/microcontrollerSignal.txt";
	fin.open("/home/atul/shared_files/microcontrollerSignal.txt");
	fin>>mSignal;
	fin.close();
}
void mWrite(){
	fout.open("../shared_files/microcontrollerSignal.txt");
	fout<<mSignal;
	fout.close();
}		
void sRead(){
	fin.open("../shared_files/simulatorSignal.txt");
	fin>>sSignal;
	fin.close();
}
void sWrite(){
	fout.open("../shared_files/simulatorSignal.txt");
	fout<<sSignal;
	fout.close();
}		
void semRead(){
	fin.open("../shared_files/semaphore.txt");
	fin>>semaphore;
	fin.close();
}
void semWrite(){
	fout.open("../shared_files/semaphore.txt");
	fout<<semaphore;
	fout.close();
}
void readCommand(){
	fin.open("../shared_files/share.txt");
	getline(fin,command);
	fin.close();
}
void writeCommand(){
		semRead();
		while(semaphore){semRead();}
		semaphore=1;semWrite();
		
		fout.open("../shared_files/share.txt");
		fout<<command<<endl;
		fout.close();
				
		semaphore=0;semWrite();
		//~ mRead();
		mSignal=!mSignal;
		mWrite();		
}
void readResult(){
	semRead();
	while(semaphore){semRead();}
	semaphore=1;semWrite();

	fin.open("../shared_files/share.txt");
	getline(fin,result);
	fin.close();
	
	semaphore=0;semWrite();
	
}
void writeResult(){
		fout.open("../shared_files/share.txt");
		fout<<result<<endl;
		fout.close();
}
BOOL InitPeripherals (HANDLE hComm){
	mRead();
	sRead();
	prvsSignal=sSignal;
}
void myfun(){
	//~ appa();
	cout<<"im im firebirds cpp"<<endl;
}
BOOL forward(HANDLE hComm){
	command="forward";
	writeCommand();
	
	DelaymSec(NULL,100);
}
BOOL backward(HANDLE hComm){
	
	command="backward";
	writeCommand();
	DelaymSec(NULL,100);
}
BOOL left(HANDLE hComm){
	command="left";
	writeCommand();
	DelaymSec(NULL,100);
}
BOOL right(HANDLE hComm){
	command="right";
	writeCommand();
	DelaymSec(NULL,100);
}
BOOL stop(HANDLE hComm){
	command="stop";
	writeCommand();
	DelaymSec(NULL,100);
}
BOOL goTo(HANDLE hComm, uint8 r, uint8 c){
	stringstream ss;
    ss<<"goto "<<r<<" "<<c;
    command=ss.str();
	writeCommand();
	DelaymSec(NULL,100);
}

BOOL getLineSensorStatus(HANDLE hComm, uint8 *status){
	sRead();
	//~ prvsSignal=sSignal;

	command="glss";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	
	readResult();
	cout<<result;
	if(result=="on")
		*status=1;//1-49
	else
		*status=0;//0-48
}
BOOL setLineSensorON(HANDLE hComm){

	command="slss on";
	writeCommand();
	DelaymSec(NULL,100);
}
BOOL setLineSensorOFF(HANDLE hComm){
	
	command="slss off";
	writeCommand();
	DelaymSec(NULL,100);

}
BOOL getLineSensor(HANDLE hComm, uint8 sensorNumber, uint8 *lineSensorValue){
	sRead();
	prvsSignal=sSignal;
	command="gls";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	readResult();
	//~ cout<<result<<"---|";
    istringstream iss(result);
	vector<string> arguments;
            arguments.clear();
            do
            {
                string tempSub;
                iss >> tempSub;
                //~ getline(iss,tempSub);
                arguments.push_back(tempSub);
            }while(iss);
     //~ cout<<atoi(arguments[0].c_str())<<" "<<atoi(arguments[1].c_str())<<" "<<atoi(arguments[2].c_str())<<" "<<endl;
		*lineSensorValue=atoi(arguments[sensorNumber].c_str());
}
BOOL getlineSensorArray(HANDLE hComm, uint8 *allLineSensorData){
	sRead();
	prvsSignal=sSignal;
	command="gls";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	readResult();
	//~ cout<<result<<"---|";
    istringstream iss(result);
	vector<string> arguments;
            arguments.clear();
            do
            {
                string tempSub;
                iss >> tempSub;
                //~ getline(iss,tempSub);
                arguments.push_back(tempSub);
            }while(iss);
     //~ cout<<atoi(arguments[0].c_str())<<" "<<atoi(arguments[1].c_str())<<" "<<atoi(arguments[2].c_str())<<" "<<endl;
     for(int i=0;i<3;i++){
		allLineSensorData[i]=atoi(arguments[i].c_str());
	}

}


BOOL getIRProximitySensorStatus(HANDLE hComm, uint8 *status){
		sRead();
	//~ prvsSignal=sSignal;

	command="girpss";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	
	readResult();
	cout<<result;
	if(result=="on")
		*status=1;//1-49
	else
		*status=0;//0-48

}
BOOL setIRProximitySensorON(HANDLE hComm){
	command="sirpss on";
	writeCommand();
	DelaymSec(NULL,100);
}
BOOL setIRProximitySensorOFF(HANDLE hComm){
	command="sirpss off";
	writeCommand();
	DelaymSec(NULL,100);

}
BOOL getIRProximitySensor(HANDLE hComm, uint8 sensorNumber, uint8 *irProximityValue){
		sRead();
	prvsSignal=sSignal;
	command="girps";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	readResult();
	//~ cout<<result<<"---|";
    istringstream iss(result);
	vector<string> arguments;
            arguments.clear();
            do
            {
                string tempSub;
                iss >> tempSub;
                //~ getline(iss,tempSub);
                arguments.push_back(tempSub);
            }while(iss);
     //~ cout<<atoi(arguments[0].c_str())<<" "<<atoi(arguments[1].c_str())<<" "<<atoi(arguments[2].c_str())<<" "<<endl;
		*irProximityValue=atoi(arguments[sensorNumber].c_str());

}
BOOL getIRProximitySensorArray(HANDLE hComm, uint8 *allIRProximityData){
		sRead();
	prvsSignal=sSignal;
	command="girps";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	readResult();
	//~ cout<<result<<"---|";
    istringstream iss(result);
	vector<string> arguments;
            arguments.clear();
            do
            {
                string tempSub;
                iss >> tempSub;
                //~ getline(iss,tempSub);
                arguments.push_back(tempSub);
            }while(iss);
     //~ cout<<atoi(arguments[0].c_str())<<" "<<atoi(arguments[1].c_str())<<" "<<atoi(arguments[2].c_str())<<" "<<endl;
     for(int i=0;i<5;i++){
		allIRProximityData[i]=atoi(arguments[i].c_str());
	}

}



BOOL getIRDistanceSensorStatus(HANDLE hComm, uint8 *status){
		sRead();
	//~ prvsSignal=sSignal;

	command="girdss";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	
	readResult();
	cout<<result;
	if(result=="on")
		*status=1;//1-49
	else
		*status=0;//0-48

}
BOOL setLeftMotorVelocity(HANDLE hComm, uint8 velocity){
}
BOOL setRightMotorVelocity(HANDLE hComm, uint8 velocity){
}
BOOL setVelocity(HANDLE hComm, uint8 leftMotorVelocity, uint8 rightMotorVelocity){
	stringstream ss;
	ss <<"sv "<<int(leftMotorVelocity)<<" "<<int(rightMotorVelocity);
	command=ss.str();
	writeCommand();
	DelaymSec(NULL,100);
}
BOOL setIRDistanceSensorON(HANDLE hComm){
	command="sirdss on";
	writeCommand();
	DelaymSec(NULL,100);
}
BOOL setIRDistanceSensorOFF(HANDLE hComm){
	command="sirdss off";
	writeCommand();
	DelaymSec(NULL,100);
	DelaymSec(NULL,100);

}
BOOL getIRDistance(HANDLE hComm, uint8 sensorNumber, uint16 *irDistanceValue){
		sRead();
	prvsSignal=sSignal;
	command="girds";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	readResult();
	//~ cout<<result<<"---|";
    istringstream iss(result);
	vector<string> arguments;
            arguments.clear();
            do
            {
                string tempSub;
                iss >> tempSub;
                //~ getline(iss,tempSub);
                arguments.push_back(tempSub);
            }while(iss);
     //~ cout<<atoi(arguments[0].c_str())<<" "<<atoi(arguments[1].c_str())<<" "<<atoi(arguments[2].c_str())<<" "<<endl;
		*irDistanceValue=atoi(arguments[sensorNumber].c_str());

}
BOOL getIRDistanceSensorArray(HANDLE hComm, uint8 *allIRDistanceData){
		sRead();
	prvsSignal=sSignal;
	command="girds";
	writeCommand();

	while(prvsSignal==sSignal){sRead();}
	prvsSignal=sSignal;

	result=command;
	while(result==command)	readResult();
	//~ cout<<result<<"---|";
    istringstream iss(result);
	vector<string> arguments;
            arguments.clear();
            do
            {
                string tempSub;
                iss >> tempSub;
                //~ getline(iss,tempSub);
                arguments.push_back(tempSub);
            }while(iss);
     //~ cout<<atoi(arguments[0].c_str())<<" "<<atoi(arguments[1].c_str())<<" "<<atoi(arguments[2].c_str())<<" "<<endl;
     for(int i=0;i<5;i++){
		allIRDistanceData[i]=atoi(arguments[i].c_str());
	}

}


