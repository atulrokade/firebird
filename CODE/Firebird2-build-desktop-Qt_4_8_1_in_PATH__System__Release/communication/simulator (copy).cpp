#include <iostream>
#include <fstream>

#include <string>
using namespace std;
		ofstream fout;
		ifstream fin;
		fstream fshare;
		fstream fsem;
		int sSignal;
		int s;
		int prvmSignal,mSignal;
		string command;
		
void mRead(){
	fin.open("microcontrollerSignal.txt");
	fin>>mSignal;
	fin.close();
}
void mWrite(){
	fout.open("microcontrollerSignal.txt");
	fout<<mSignal;
	fout.close();
}		
void sRead(){
	fin.open("simulatorSignal.txt");
	fin>>sSignal;
	fin.close();
}
void sWrite(){
	fout.open("simulatorSignal.txt");
	fout<<sSignal;
	fout.close();
}		
void semRead(){
	fin.open("semaphore.txt");
	fin>>s;
	fin.close();
}
void semWrite(){
	fout.open("semaphore.txt");
	fout<<s;
	fout.close();
}
void readCommand(){
	fin.open("share.txt");
	getline(fin,command);
	fin.close();
}
void writeCommand(){
		fout.open("share.txt");
		fout<<command<<endl;
		fout.close();
}
int main()
{
	sRead();
	mRead();	
	prvmSignal=sSignal;
	while(1)
	{
cout<<"wait"<<endl;
		while(prvmSignal==mSignal){mRead();}
cout<<"wait over"<<endl;
		prvmSignal=mSignal;
		semRead();
cout<<"waiting for semaphore"<<endl;
		while(s){semRead();}
		s=1;sWrite();
		readCommand();
		s=0;semWrite();
cout<<"command = "<<command;
		semRead();
cout<<"waiting for semaphore"<<endl;
		while(s){semRead();}
		s=1;sWrite();
		command="read_kar_liyi--";
		writeCommand();
		s=0;semWrite();

		sSignal=!sSignal;
		sWrite();
cout<<" mSignal = "<<mSignal<<" sSignal = "<<sSignal<<endl;
		}
	return 0;
}