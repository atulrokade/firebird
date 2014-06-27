#include <iostream>
#include <fstream>
#include <string>
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
		
int count=0;		
void mRead(){
	string tt="../shared_files/microcontrollerSignal.txt";
	fin.open(tt.c_str());
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
		fout.open("../shared_files/share.txt");
			
	//~ stringstream ss;
    //~ ss<<count<<" atul"<<count;
    //~ command=ss.str();
    //~ 
		//~ fout<<command<<endl;
		fout<<count<<" atul  "<<count<<endl;
		fout.close();
}
void writeResult(){
		fout.open("../shared_files/share.txt");
		fout<<result<<endl;
		fout.close();
}
int main()
{
	mRead();
	sRead();
	prvsSignal=sSignal;
	//~ cout<<command;
	while(1)
	{
		//~ cout<<"prvsSignal-->"<<prvsSignal<<endl;
		//~ cout<<"sSignal----->"<<sSignal<<endl;
		//~ cout<<"mSignal----->"<<mSignal<<endl;
		
	//~ getline(cin,command);
	count++;
		semRead();
		while(semaphore){semRead();}
		semaphore=1;semWrite();			
		writeCommand();
		semaphore=0;semWrite();
		
		mRead();
		mSignal=!mSignal;
		
		mWrite();			
		while(prvsSignal==sSignal){
					//~ cout<<"prvsSignal-->"<<prvsSignal<<endl;
		//~ cout<<"sSignal----->"<<sSignal<<endl;
		//~ mRead();
		//~ cout<<"mSignal----->"<<mSignal<<endl;
			sRead();}
		prvsSignal=sSignal;
		
		semRead();
		while(semaphore){semRead();}
		semaphore=1;semWrite();
		readCommand();
		semaphore=0;semWrite();
cout<<command<<endl;
	}
	return 0;
}
