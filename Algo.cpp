//Name-Anand Pipaliya
//ID-201601457

//Here I implement all functions which are in Algo.h file
#include "Algo.h"
#include<bits/stdc++.h>
using namespace std;

/*In all functions I created TLB and Pf(physical_frames) vectors. They contain VPN(Virtual_page_number).
First I checked the vpn[i] element whether it present in tlb or not. If it is present then I update tlb
in only lru algo and not update pf vector. If it is not presetn then I will add vpn[i] in tlb and pf
vector and if pf is full then we will remove vpn from tlb and pf according to algorithm */
vector<int> Algo::LRU_ALGO(int pframe,vector<int> vpn)
{
	vector<int> tlb;
	vector<int> pf(pframe,-1);
	int hit=0;
	int miss=0;
	int n=vpn.size();
	for(int i=0;i<n;i++)
	{
		int temp,flag_h=0;
   		std::vector<int>::iterator position = std::find(tlb.begin(), tlb.end(), vpn[i]);
		if (position != tlb.end()) // == myVector.end() means the element was not found
    	{
    		temp=vpn[i];
    		tlb.erase(position);
    		tlb.push_back(vpn[i]);
    		if(tlb.size()==pframe)
   				hit++;
   				flag_h=1;
   		}
		else
   		{
   			if(tlb.size()>pframe-1)
   			{
   				temp=tlb[0];
				tlb.erase(tlb.begin());
				miss++;
   			}
   			tlb.push_back(vpn[i]);
   		}

   		for(int j=0;j<pframe;j++)
		{
			if(pf[j]==-1 || pf[j]==temp)
			{
				pf[j]=vpn[i];
				break;
			}
		}

   		cout<< setw(2)<<vpn[i]<<": [";
   		for (int i = 0; i < pframe; ++i)
		{
			if(pf[i]!=-1)	cout<< setw(2)<<pf[i];
			if(i!=pframe-1) 	cout<<"|";
		}
   		cout<<"]";
   		if (!flag_h)	cout<<" F";
		//else	cout<<" H";
   		cout<<endl;
   		flag_h=0;
   		temp=-1;
	}
	//cout<<hit<<" "<<miss<<endl;
	std::vector<int> data;
	data.push_back(hit);
	data.push_back(miss);
	return data;
}
vector<int> Algo::LRU_ALGO_RATE(int pframe,vector<int> vpn)
{
	vector<int> tlb;
	int hit=0;
	int miss=0;
	int n=vpn.size();
	for(int i=0;i<n;i++)
	{
   		std::vector<int>::iterator position = std::find(tlb.begin(), tlb.end(), vpn[i]);
		if (position != tlb.end()) // == myVector.end() means the element was not found
    	{
    		tlb.erase(position);
    		tlb.push_back(vpn[i]);
    		if(tlb.size()==pframe)
   				hit++;
   		}
		else
   		{
   			if(tlb.size()>pframe-1)
   			{
				tlb.erase(tlb.begin());
				miss++;
   			}
   			tlb.push_back(vpn[i]);
   		}
	}
	std::vector<int> data;
	data.push_back(hit);
	data.push_back(miss);
	return data;
}
vector<int> Algo::FIFO_ALGO(int pframe,vector<int> vpn)
{
	vector<int> tlb;
	vector<int> pf(pframe,-1);
	int hit=0;
	int miss=0;
	int n=vpn.size();
	for(int i=0;i<n;i++)
	{
		int temp,flag_h=0;
   		std::vector<int>::iterator position = std::find(tlb.begin(), tlb.end(), vpn[i]);
		if (position != tlb.end()) // == myVector.end() means the element was not found
    	{
    		temp=vpn[i];
    		if(tlb.size()==pframe)
   				hit++;
   				flag_h=1;
   		}
		else
   		{
   			if(tlb.size()>pframe-1)
   			{
   				temp=tlb[0];
				tlb.erase(tlb.begin());
				miss++;
   			}
   			tlb.push_back(vpn[i]);
   		}

   		for(int j=0;j<pframe;j++)
		{
			if(pf[j]==-1 || pf[j]==temp)
			{
				pf[j]=vpn[i];
				break;
			}
		}

   		cout<< setw(2)<<vpn[i]<<": [";
   		for (int i = 0; i < pframe; ++i)
		{
			if(pf[i]!=-1)	cout<< setw(2)<<pf[i];
			if(i!=pframe-1) 	cout<<"|";
		}
   		cout<<"]";
   		if (!flag_h)	cout<<" F";
		//else	cout<<" H";
   		cout<<endl;
   		flag_h=0;
   		temp=-1;
	}
	//cout<<hit<<" "<<miss<<endl;
	std::vector<int> data;
	data.push_back(hit);
	data.push_back(miss);
	return data;
}
vector<int> Algo::FIFO_ALGO_RATE(int pframe,vector<int> vpn)
{
	vector<int> tlb;
	int hit=0;
	int miss=0;
	int n=vpn.size();
	for(int i=0;i<n;i++)
	{
   		std::vector<int>::iterator position = std::find(tlb.begin(), tlb.end(), vpn[i]);
		if (position != tlb.end()) // == myVector.end() means the element was not found
    	{
    		if(tlb.size()==pframe)
   				hit++;
   		}
		else
   		{
   			if(tlb.size()>pframe-1)
   			{
				tlb.erase(tlb.begin());
				miss++;
   			}
   			tlb.push_back(vpn[i]);
   		}
	}
	std::vector<int> data;
	data.push_back(hit);
	data.push_back(miss);
	return data;
}
vector<int> Algo::OPT_ALGO(int pframe,vector<int> vpn)
{
	vector<int> tlb;
	vector<int> pf(pframe,-1);
	int hit=0;
	int miss=0;
	int n=vpn.size();
	for(int i=0;i<n;i++)
	{
		int temp,flag_h=0;
   		std::vector<int>::iterator position = std::find(tlb.begin(), tlb.end(), vpn[i]);
		if (position != tlb.end()) // == myVector.end() means the element was not found
    	{
    		temp=vpn[i];
    		if(tlb.size()==pframe)
   				hit++;
   			flag_h=1;
   		}
		else
   		{
   			if(tlb.size()>pframe-1)
   			{
				for(int z=i+1;z<n && tlb.size()!=1;z++)
				{
					std::vector<int>::iterator p = std::find(tlb.begin(), tlb.end(), vpn[z]);
					if (p != tlb.end()) // == myVector.end() means the element was not found
    					tlb.erase(p);
				}
				temp=tlb[0];
				miss++;
   			}
   		}
   		
  		for(int j=0;j<pframe;j++)
		{
			if(pf[j]==-1 || pf[j]==temp)
			{
				pf[j]=vpn[i];
				break;
			}
		}
		tlb.clear();
		for (int j = 0; j < pframe; j++)
   		{
   			if(pf[j]!=-1)
   			tlb.push_back(pf[j]);	
   		}

   		cout<< setw(2)<<vpn[i]<<": [";
   		for (int i = 0; i < pframe; ++i)
		{
			if(pf[i]!=-1)	cout<< setw(2)<<pf[i];
			if(i!=pframe-1) 	cout<<"|";
		}
  		cout<<"]";
   		if (!flag_h)	cout<<" F";
   		//else cout<<" H";
   		cout<<endl;
   		flag_h=0;
   		temp=-1;
	}
	//cout<<hit<<" "<<miss<<endl;
	std::vector<int> data;
	data.push_back(hit);
	data.push_back(miss);
	return data;
}
vector<int> Algo::OPT_ALGO_RATE(int pframe,vector<int> vpn)
{
	vector<int> tlb;
	vector<int> pf(pframe,-1);
	int hit=0;
	int miss=0;
	int n=vpn.size();
	for(int i=0;i<n;i++)
	{
		int temp,flag_h=0;
   		std::vector<int>::iterator position = std::find(tlb.begin(), tlb.end(), vpn[i]);
		if (position != tlb.end()) // == myVector.end() means the element was not found
    	{
    		temp=vpn[i];
    		if(tlb.size()==pframe)
   				hit++;
   		}
		else
   		{
   			if(tlb.size()>pframe-1)
   			{
				for(int z=i+1;z<n && tlb.size()!=1;z++)
				{
					std::vector<int>::iterator p = std::find(tlb.begin(), tlb.end(), vpn[z]);
					if (p != tlb.end()) // == myVector.end() means the element was not found
    					tlb.erase(p);
				}
				temp=tlb[0];
				miss++;
   			}
   		}
  		for(int j=0;j<pframe;j++)
		{
			if(pf[j]==-1 || pf[j]==temp)
			{
				pf[j]=vpn[i];
				break;
			}
		}
		tlb.clear();
		for (int j = 0; j < pframe; j++)
   		{
   			if(pf[j]!=-1)
   			tlb.push_back(pf[j]);	
   		}
	}
	std::vector<int> data;
	data.push_back(hit);
	data.push_back(miss);
	return data;
}