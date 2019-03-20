//Name-Anand Pipaliya
//ID-201601457

#include "Algo.h"
#include<bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
	if(argc<5)
	{
		cout<<"Arguments are not enough"<<endl;
		cout<<"Plaese give argument like: Min_frames Max_frames Increment File_name "<<endl;
		return 0;	
	}
	int Min_frames=atoi(argv[1]);
	int Max_frames=atoi(argv[2]);
	int Increment=atoi(argv[3]);
	string file=argv[4];
	string line;
	vector<int> vpn;


	if(Min_frames<2)
	{
		cout<<"Plaese enter valid minimum number of physical memory frames (minimum 2)"<<endl;
		return -1;
	}
	if(Max_frames>100)
	{
		cout<<"Plaese enter valid maximum number of physical memory frames (maximum 100)"<<endl;
		return -1;
	}
	if(Increment<1)
	{
		cout<<"Plaese enter valid Increment number of physical memory frames (positive)"<<endl;
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
         		cout<<setw(2)<<z<<" ";	
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
	vector<int> data,sequence;
	vector<float> miss_rate_lru,miss_rate_opt,miss_rate_fifo;
	int hit;
	int miss;
	cout << fixed << setprecision(2)<<setw(2); 

	ofstream myfile1 ("vmrates.dat");
  	if (myfile1.is_open())
    		myfile1.close();
 	else cout << "Unable to open file";

	for(int i=Min_frames;i<=Max_frames;i+=Increment)
	{
		sequence.push_back(i);
		data=a.LRU_ALGO_RATE(i,vpn);
		hit=data[0];
		miss=data[1];
		cout<<"lru, "<<i<<" frames: Miss rate = "<<miss<<"/"<<(miss+hit)<<" = "<<miss*100/float(miss+hit)<<"%"<<endl;
		miss_rate_lru.push_back(miss*100/float(miss+hit));
 	}

 	for(int i=Min_frames;i<=Max_frames;i+=Increment)
	{	
		data=a.OPT_ALGO_RATE(i,vpn);
		hit=data[0];
		miss=data[1];
		cout<<"opt, "<<i<<" frames: Miss rate = "<<miss<<"/"<<(miss+hit)<<" = "<<miss*100/float(miss+hit)<<"%"<<endl;
		miss_rate_opt.push_back(miss*100/float(miss+hit));
	}

	for(int i=Min_frames;i<=Max_frames;i+=Increment)
	{
		data=a.FIFO_ALGO_RATE(i,vpn);
		hit=data[0];
		miss=data[1];
		cout<<"fifo, "<<i<<" frames: Miss rate = "<<miss<<"/"<<(miss+hit)<<" = "<<miss*100/float(miss+hit)<<"%"<<endl;
		miss_rate_fifo.push_back(miss*100/float(miss+hit));
	}	
	
	ofstream myfile2 ("vmrates.dat",ios::app);
  		if (myfile2.is_open())
  		{
  			 myfile2 << "Sequ" <<"\t";
  			for (int i = 0; i < sequence.size(); ++i)
  				myfile2 << setw(2)<< sequence[i] <<"\t";
  			 myfile2 << "\nOPT" <<"\t";
  			for (int i = 0; i < sequence.size(); ++i)
  				myfile2 << setprecision(4)<< miss_rate_opt[i] <<"\t";
  			 myfile2 << "\nLRU" <<"\t";
  			for (int i = 0; i < sequence.size(); ++i)
  				myfile2 << setprecision(4)<< miss_rate_lru[i] <<"\t";
  			
  			myfile2 << "\nFIFO" <<"\t";
  			for (int i = 0; i < sequence.size(); ++i)
  				myfile2 << setprecision(4)<< miss_rate_fifo[i] <<"\t";
  			myfile2 <<"\n";
    		myfile2.close();
 		}
 		else cout << "Unable to open file";
	return 0;
}