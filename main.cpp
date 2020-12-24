//
//  main.cpp
//  HanoiTower
//
//  Created by ZQ314159 on 14/7/2563 BE.
//  Copyright © 2563 ZQ314159. All rights reserved.
//

#include <iostream>
using namespace std;
const int height = 5;
const int column = 3;
void print(int n[3][column])
{
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0 ; j < column ; j++)
        {
            for(int k = 0; k < height-n[i][j];k++)
            {
                cout<<" ";
            }
            for(int k = 0; k < n[i][j];k++)
            {
                cout<<"x";
            }
            cout<<"|";
            for(int k = 0; k < n[i][j];k++)
            {
                cout<<"x";
            }
            for(int k = 0; k < height-n[i][j];k++)
            {
                cout<<" ";
            }
            cout<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

}
void solve(int t[height][column],int from,int to ,int n)
{
    if(n==0)return;
    if (n==1) {
        int top_1= 0;
        while (top_1<height && t[top_1][from]==0) {
            top_1++;
        }
        int top_2= 0;
        while (top_2<height && t[top_2][to]==0) {
            top_2++;
        }
        top_2--;
        t[top_2][to] = t[top_1][from];
        t[top_1][from] = 0;
        print(t);
        return;
    }
    int another = 3-from-to;
    solve(t, from, another, n-1);
    solve(t, from, to, 1);
    solve(t, another, to, n-1);
}
int main(int argc, const char * argv[]) {
    int tower[5][column];
    for (int i=0; i<5; i++) {
        for (int j=0; j<3; j++) {
            tower[i][j] = 0;
        }
    }
    int from,to;
    cout<<"from column(1-3) :";
    cin>>from;
    cout<<"to   column(1-3) :";
    cin>>to;
    for (int k=0; k<height; k++) {
        tower[k][from-1] = k+1;
    }
    
    print(tower);
    solve(tower, from-1, to-1, height);
    return 0;
}
