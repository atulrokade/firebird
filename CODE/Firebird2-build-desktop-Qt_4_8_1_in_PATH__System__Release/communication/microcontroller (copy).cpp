#include <iostream>
#include <fstream>
#include <string>
using namespace std;
		ofstream fout;
		ifstream fin;
		fstream fshare;
		fstream fsem;
		string command;
		int s;
		int prvsSignal,sSignal;
		int mSignal;
		
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
	mRead();
	sRead();
	prvsSignal=sSignal;
	getline(cin,command);
	cout<<command;
	{
		semRead();
cout<<"waiting for semaphore"<<endl;
		while(s){semRead();}
		s=1;semWrite();			
		writeCommand();
		s=0;semWrite();
		mSignal=!mSignal;
		mWrite();			
cout<<"wait"<<endl;
		while(prvsSignal==sSignal){sRead();}
cout<<"wait over"<<endl;
		prvsSignal=sSignal;
		semRead();
cout<<"waiting for semaphore"<<endl;
		while(s){semRead();}
		s=1;semWrite();
		readCommand();
		s=0;semWrite();
cout<<"return command = "<<command<<endl;
	}
	return 0;
}