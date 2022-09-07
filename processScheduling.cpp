#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("intput.txt","r",stdin);
    int n,m;
    cin>> n >> m;
    int resTable[n+2][m+2];
    //input Reservtion Table;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>resTable[i][j];
        }
    }
    
}