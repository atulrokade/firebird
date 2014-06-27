/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */
#include "FireBird.h"
#include <iostream>
using namespace std;

void myMain()
{
	InitPeripherals(NULL);
	DelaymSec(NULL,2000);

	setLineSensorON(NULL);
	DelaymSec(NULL,100);

	int val=5;
	int first;
		uint8 lsvalue1,ls1=2;
		uint8 lsvalue2,ls2=3;
		uint8 lsvalue3,ls3=4;
		int l,m,r;

	while(1)
	{
		getLineSensor(NULL,ls1,&lsvalue1);
		getLineSensor(NULL,ls2,&lsvalue2);
		getLineSensor(NULL,ls3,&lsvalue3);
		cout<<(int)lsvalue1<<" ";
		cout<<(int)lsvalue2<<" ";
		cout<<(int)lsvalue3<<" "<<endl;
		l=(int)lsvalue1;
		m=(int)lsvalue2;
		r=(int)lsvalue3;
		if(l== 0 && m==1 && r==0){
			forward(NULL);
			DelaymSec(NULL,100);
			first=val*3;
		}
		else if(l== 1 &&m==1 &&r==0){
			left(NULL);
			DelaymSec(NULL,10);
			first=val*3;
		}
		else if(l== 0 &&m==1 &&r==1){
			right(NULL);
			DelaymSec(NULL,10);
			first=val*3;
		}
		else if(m==0 ){
			if(first>val*2){
				right(NULL);
				first--;
				DelaymSec(NULL,10);
			}
			else if(first>0){
				left(NULL);
				DelaymSec(NULL,10);
				first--;
			}
			else{
				first=val*4;
				DelaymSec(NULL,10);
			}
		}
		else
		{
			stop(NULL);
			cout<<"stop"<<endl;
			break;
		}
	}	
	
}
