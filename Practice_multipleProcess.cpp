#include <bits/stdc++.h>
using namespace std;
set<int>s;
vector<int > forbidden,permissible,collision;
int reservation[100][100] = {{1, 0, 0, 0, 0, 0, 1},
                             {0,1, 0, 1, 0, 1, 0},
                             {0, 0, 1, 0, 1, 0, 0}};



void printTable(int n,int m){
     for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << reservation[i][j] << " ";
        }cout << endl;
    }
}
void makeForbidden(int n, int m){
    for(int i = 0;i < n;i++){
        for(int j = 0; j < m;j++){
            for(int k = j+1;k < m;k++){
                if(reservation[i][j] == 1 && reservation[i][k] == 1){
                    s.insert(abs(k-j));
                }
            }
        }
    }
    for(auto i : s){
        forbidden.push_back(i);
    }
}
void printForbidden(){
    for(auto i : forbidden)cout << i << " ";
    cout << endl;
}
void makePermissible(int m){
    for(int i = 1;i <= m;i++){
        if(s.find(i) == s.end())permissible.push_back(i);
    }
}
void printPermissible(){
    for(auto i : permissible)cout << i << " ";
    cout << endl;
}
void makeCollisionVector(){
    int maxi = *max_element(forbidden.begin(),forbidden.end());
    for(int i = maxi;i >= 1;i--){
        if(s.find(i) == s.end()){
            collision.push_back(0);
        }else collision.push_back(1);
    }

}
void printCollision(){
    for (auto i : collision){
        cout << i << " ";
    }cout << endl;
}
int main()
{
    int n = 3,m = 7;
    printTable(n,m);
    makeForbidden(n,m);
    printForbidden();
    makePermissible(m);
    printPermissible();
    makeCollisionVector();
    printCollision();
    
    int nop = 1;
    while(1){
        nop++;
        cout << "Enter a latency of new process " << endl;
        int latency,flag = 0;
        cin>> latency;
        if(latency == -1)break;
        for(int i = 0;i < n;i++){
            if(flag == 1)break;
            for(int j = latency;j < (latency+m);j++){
                if(reservation[i][j-latency] == 1){
                    if(reservation[i][j] == 0)reservation[i][j] = nop;
                    else{
                        printf("Collision occured at %d %d with %d %d processes\n",i+1,j+1,reservation[i][j],nop);
                        reservation[i][j] = -1;
                        flag = 1;
                        break;
                    }
                }else continue;
            }
        }
        printTable(n,(m+latency));
    }
    return 0;
}