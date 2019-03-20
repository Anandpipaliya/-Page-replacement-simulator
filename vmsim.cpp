//Name-Anand Pipaliya
//ID-201601457

#include "Algo.h"
#include<bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
	if(argc<4)
	{
		cout<<"Arguments are not enough"<<endl;
		cout<<"Plaese give argument like: Physical_memory_frames File_name Algorithm_name"<<endl;
		return 0;	
	}
	int pframe=atoi(argv[1]);
	string file=argv[2];
	string algorithm=argv[3];
	string line;
	vector<int> vpn;


	if(pframe>100)
	{
		cout<<"Plaese enter valid total number of physical memory frames (maximum 100)"<<endl;
		return -1;
	}


	ifstream myfile (file);
	if(myfile.fail())
	{
		cout<<"File does not exist"<<endl;
		return -1;
	}
	else	cout<<"Data from "<<file<<": Virtual Page Number"<<endl;	
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			istringstream is( line );
    			int z;
    			while( is >> z ) {
         		vpn.push_back(z);
         		cout<<z<<" ";	
   			}		
		}
		cout<<endl;
		myfile.close();
	}	
	else 
	{
		cout << "Unable to open file"; 
		return -1;	
	}
	

	Algo a;
	vector<int> data;
	int hit;
	int miss;
	cout << fixed << setprecision(2)<<setw(2); 

	if(algorithm=="lru")	 
		data=a.LRU_ALGO(pframe,vpn);
	else if(algorithm=="opt")
		data=a.OPT_ALGO(pframe,vpn);
	else if(algorithm=="fifo")
		data=a.FIFO_ALGO(pframe,vpn);
	else	cout<<"There is no algorithm name:"<<algorithm<<endl;

	hit=data[0];
	miss=data[1];
	cout<<hit<<" "<<miss<<endl;
	cout<<"Miss rate = "<<miss<<"/"<<(miss+hit)<<" = "<<miss*100/float(miss+hit)<<"%"<<endl;
	
	return 0;
}
