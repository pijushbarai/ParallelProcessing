#include <bits/stdc++.h>
using namespace std;

set<int> s,u;
int resTable[100][100];
vector<int>forbiddenLatency,permissibleLatency;

//printing function of Reservation Table;
void printTable(int n, int m){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << resTable[i][j] << " ";
        }cout << endl;
    }
}
void makeForbidden(int n,int m){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int k = 0;k < m;k++){
                if((resTable[i][j] == 1 )&& (resTable[i][k] == 1) && (j!=k)){
                    s.insert(abs(j-k));
                }
            }
        }
    }
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++){
        forbiddenLatency.push_back(*it);
    }
}
void makePermissible(int n){
    int len = forbiddenLatency.size();
    for(int i = 1;i <= n;i++){
        if(s.find(i)  == s.end()){
            permissibleLatency.push_back(i);
        }
    }
}

void printForbidden(){
    int l = forbiddenLatency.size();
    for(int i = 0;i < l;i++){
        cout << forbiddenLatency[i] << " ";
    }cout << endl;
}

void printPermissible(){
    int l = permissibleLatency.size();
    for(int i = 0;i < l;i++){
        cout << permissibleLatency[i] << " ";
    }cout << endl;
}
int main(){
   freopen("input.txt","r",stdin);
    int n,m;
    cin>> n >> m;
    //input Reservtion Table;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>resTable[i][j];
        }
    }
    printTable(n,m);
    cout << endl << endl;
    makeForbidden(n,m);
    makePermissible(m);
    printForbidden();
    printPermissible();
    return 0;
}