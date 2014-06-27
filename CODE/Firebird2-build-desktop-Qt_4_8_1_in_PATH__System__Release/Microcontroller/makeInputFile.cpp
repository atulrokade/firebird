/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */
#include "iostream"
#include "string"
#include "fstream"
#include "vector"
using namespace std;

    string inputFile;
    string codeFile;
    
void makeInputFile(){

    string search_string1 = "int main";
    string replace_string1 = "void myMain";

    string search_string2 = "return 0";
    string replace_string2 = "return";

    string inbuf;
    fstream input_file(inputFile.c_str(), ios::in);
    ofstream output_file(codeFile.c_str());

    bool start=false;
    bool mainFound=false;
    while (!input_file.eof())
    {
        getline(input_file, inbuf);

        if(!mainFound){
            int spot = inbuf.find(search_string1);
            if(spot >= 0)
            {
                string tmpstring = inbuf.substr(0,spot);
                tmpstring += replace_string1;
                tmpstring += inbuf.substr(spot+search_string1.length(), inbuf.length());
                inbuf = tmpstring;
                start=true;
                mainFound=true;
            }
        }
        if(start){
            int spot = inbuf.find(search_string2);
            if(spot >= 0)
            {
                string tmpstring = inbuf.substr(0,spot);
                tmpstring += replace_string2;
                tmpstring += inbuf.substr(spot+search_string2.length(), inbuf.length());
                inbuf = tmpstring;
            }
        }
        output_file << inbuf << endl;
    }
}

int main(){
	cout<<"Robotic File Name :";
    cin>>inputFile;
    cout<<inputFile<<endl;	
    codeFile="input.h";
    
	makeInputFile();
	return 0;
}
