#include <iostream>
#include <fstream>

#include <string>
using namespace std;
	ofstream fout;
	ifstream fin;
	fstream fshare;
	fstream fsem;
	int sSignal;
	int semaphore;
	int prvmSignal,mSignal;
	string command;
	string result;
		
void mRead(){
	fin.open("/home/atul/shared_files/microcontrollerSignal.txt");
	fin>>mSignal;
	fin.close();
}
void mWrite(){
	fout.open("/home/atul/shared_files/microcontrollerSignal.txt");
	fout<<mSignal;
	fout.close();
}		
void sRead(){
	fin.open("/home/atul/shared_files/simulatorSignal.txt");
	fin>>sSignal;
	fin.close();
}
void sWrite(){
	fout.open("/home/atul/shared_files/simulatorSignal.txt");
	fout<<sSignal;
	fout.close();
}		
void semRead(){
	fin.open("/home/atul/shared_files/semaphore.txt");
	fin>>semaphore;
	fin.close();
}
void semWrite(){
	fout.open("/home/atul/shared_files/semaphore.txt");
	fout<<semaphore;
	fout.close();
}
void readCommand(){
	fin.open("/home/atul/shared_files/share.txt");
	getline(fin,command);
	fin.close();
}
void writeCommand(){
		fout.open("/home/atul/shared_files/share.txt");
		fout<<command<<endl;
		fout.close();
}
void writeResult(){
		fout.open("/home/atul/shared_files/share.txt");
		fout<<result<<endl;
		fout.close();
}
int main()
{
	sRead();
	mRead();	
	prvmSignal=sSignal;
	while(1)
	{
		while(prvmSignal==mSignal){mRead();}
		prvmSignal=mSignal;
		semRead();
		while(semaphore){semRead();}
		semaphore=1;sWrite();
		readCommand();
		semaphore=0;semWrite();
cout<<command<<endl;
		semRead();
		while(semaphore){semRead();}
		semaphore=1;sWrite();
		cin>>result;
		//~ result="atul";
		writeResult();
		semaphore=0;semWrite();

		sSignal=!sSignal;
		sWrite();
if(command=="exit"){break;}
		}
	return 0;
}