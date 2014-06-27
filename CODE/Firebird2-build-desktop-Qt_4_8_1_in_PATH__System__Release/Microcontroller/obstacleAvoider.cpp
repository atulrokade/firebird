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
    
    setIRDistanceSensorON(NULL);
    DelaymSec(NULL,5000);
    
	setVelocity(NULL,155,155);
	DelaymSec(NULL,100);    
    int v=3;
    int first=2*v;
    uint8 lsvalue0,s0=1;
    uint8 lsvalue2,s2=2;
    uint8 lsvalue4,s4=3;
    uint8 lsvalue6,s6=6;
    
    uint16 psvalue0,psvalue2,psvalue4,psvalue6;
    int f,l,r,b;
    
    int rnd=0;
    while(1)
    {
        getIRDistance(NULL,s0,&psvalue0);
        getIRDistance(NULL,s2,&psvalue2);
        getIRDistance(NULL,s4,&psvalue4);
        getIRDistance(NULL,s6,&psvalue6);
        l=(int) psvalue0;
        f=(int) psvalue2;
        r=(int) psvalue4;
        b=(int) psvalue6;
        
        cout<<l<<" "<<f<<" "<<r<<"\t"<<b<<endl;
        if(f>60){
            if(l>30 && r>30){
                forward(NULL);
            }
            else{
                if(r<=30){
                    left(NULL);
                }
                if(l<=30){
                    right(NULL);
                }
            }
        }
        else {
			
			if(l>r)
			{
			 if(l>30){left(NULL);}else if(r>30){right(NULL);}else if(b>30){backward(NULL);}
			}
			else
			{
			if(r>30){right(NULL);}else if(l>30){left(NULL);}else if(b>30){backward(NULL);}
			}
			rnd=(rnd+1)%5;
		}
        DelaymSec(NULL,100);
    }	
}
