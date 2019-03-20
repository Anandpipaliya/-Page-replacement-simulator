//Name-Anand Pipaliya
//ID-201601457

//This is just header file which contain all functions defination.
#ifndef Algo_H
#define Algo_H
#include<bits/stdc++.h>
using namespace std;

class Algo
{
private:
    int pframe;
    vector<int> vpn;
 
public:
vector<int> LRU_ALGO(int pframe,vector<int> vpn); 
vector<int> OPT_ALGO(int pframe,vector<int> vpn); 
vector<int> FIFO_ALGO(int pframe,vector<int> vpn);
vector<int> LRU_ALGO_RATE(int pframe,vector<int> vpn); 
vector<int> OPT_ALGO_RATE(int pframe,vector<int> vpn); 
vector<int> FIFO_ALGO_RATE(int pframe,vector<int> vpn);
};
 
#endif