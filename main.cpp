/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Enter Here
 *
 * Created on August 10, 2016, 12:38 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return (2*i)+1;
}

int parent(int i)
{
    return i/2;
}

int search(int arr[],int spot, int key)
{
    if(arr[spot]==0 || arr[spot]==key)
    {
        return spot;
    }
    if(key < arr[spot])
    {
        return search(arr,left(spot),key);
    }
    return search(arr,right(spot),key);
}

int max(int arr[], int spot)
{
    while(arr[right(spot)]!= 0)
    {
        spot=right(spot);
    }
    return spot;
}

int min(int arr[], int spot)
{
    while(arr[left(spot)]!= 0)
    {
        spot=left(spot);
    }
    return spot;
}


void insert(int arr[], int val)
{
    int y=0;
    int x=0;
    while(arr[x]!=0)
    {
        y=x;
        if(val,arr[x])
        {
            x=left(x);
        }
        else x = right(x);
    }
    if(val<arr[y])
    {
        arr[left(y)]=val;
    }
    else
    {
        arr[right(y)]=val;
    }
}

void transplant(int arr[], int u, int v)
{
    if(parent(u)==0)
    {
        arr[0]=v;
    }
    else if(u == arr[left(parent(u))])
    {
        arr[left(parent(u))]=v;
    }
    else
    {
        arr[right(parent(u))]=v;
    }
    if(v!=0)
    {
        arr[parent(v)]=arr[parent(u)];
    }
}

void deleter(int arr[],int val)
{
    if(arr[left(val)]==0)
    {
        transplant(arr,val,right(val));
    }
    else if(arr[right(val)]==0)
    {
        transplant(arr,val,left(val));
    }
    else
    {
        int y = min(arr,0);
        if(parent(y)!=val)
        {
            transplant(arr,y,right(y));
            arr[right(y)]=arr[right(val)];
            arr[parent(right(y))]=y;
        }
        transplant(arr,val,y);
        arr[left(y)]=arr[left(val)];
        arr[parent(left(y))]=y;
    }
}


int main(int argc, char** argv) {
    
    int u = 1000;
    int k=10;
    int d[u+1] = {0};
    for(int i=1;i<=u;++i)
    {
        int temp=i;
        while(temp<=u)
        {
            ++(d[temp]);
            temp+=i;
        }
        cout << i << " " << d[i] << endl;
    }
    
    int Mnk[u] {0};
    
    int tree[k-1*10000]={};
    for(int i=0;i<k-1;++i)
    {
        insert(tree,d[i]);
    }
    
    
    
    return 0;
}

