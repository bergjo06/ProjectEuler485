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

/*
 * 
 */
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
    
    
    
    
    return 0;
}

