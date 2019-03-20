//Name-Anand Pipaliya
//ID-201601457

#include<bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
	if(argc<4)
	{
		cout<<"Arguments are not enough"<<endl;
		cout<<"Plaese give argument like: Physical_memory_frames Sequence_length File_name"<<endl;
		return 0;	
	}
	int pframe=atoi(argv[1]);
	int length=atoi(argv[2]);
	string file=argv[3];
	vector<int> vpn;

	if(pframe>100)
	{
		cout<<"Plaese enter valid total number of physical memory frames (maximum 100)"<<endl;
		return -1;
	}

	for(int i=0;i<length;i++)
	{
		vpn.push_back(rand()%(pframe));
		if(vpn[i]==vpn[i-1] && i>0)
		{
			if(vpn[i-1]==0)
				vpn[i]++;
			else
				vpn[i]--;
		}
	}

	ofstream myfile (file);
  	if (myfile.is_open())
 	{
  		for(int i=0;i<length;i++)
  			myfile<<vpn[i]<<" ";
  		myfile.close();
  	}	
 	else cout << "Unable to open file";
 	return 0;
}