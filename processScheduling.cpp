#include <bits/stdc++.h>
using namespace std;

set<int> forbiddenSet,u;
int resTable[100][100],table[100][100];
vector<int>forbiddenLatency,permissibleLatency,collisionVector;

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
                    forbiddenSet.insert(abs(j-k));
                }
            }
        }
    }
    set<int>::iterator it;
    for (it = forbiddenSet.begin(); it != forbiddenSet.end(); it++){
        forbiddenLatency.push_back(*it);
    }
}
void makePermissible(int n){
    int len = forbiddenLatency.size();
    for(int i = 1;i <= n;i++){
        if(forbiddenSet.find(i)  == forbiddenSet.end()){
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
void makeCollisionVector(){
    int m = *max_element(forbiddenLatency.begin(), forbiddenLatency.end());
    for(int i = 1;i <= m;i++){
        if(forbiddenSet.find(i)  == forbiddenSet.end()){
            collisionVector.push_back(1);
        }else{
            collisionVector.push_back(0);
        }
    }
}

void printCollision(){
    int l = collisionVector.size();
    for(int i = 0;i < l;i++){
        cout << collisionVector[i] << " ";
    }cout << endl;
}

void initiateTask(int n,int m){
    for(int i = 0;i < n;i++){
            for(int j = 0;j < m; j++){
                if(resTable[i][j] == 1){
                   table[i][j] = 1;
                }else{
                    continue;
                }
            }
        }
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
    makeCollisionVector();
    initiateTask(n,m);
    cout << "forbidden latency : ";
    printForbidden();
    cout << "Permissible latency : ";
    printPermissible();
    cout << "Collision vector : ";
    printCollision();
    int numTask;
    cin>> numTask;
    int latency,maxLatency = 0;
    int cs = 1;
    while (numTask --)
    {
        cs++;
        // cout <<"Input Latency" << endl;
        
        cin>> latency;
        maxLatency = max(latency,maxLatency);
        int flag = 0;
        for(int i = 0;i < n;i++){
            for(int j = latency;j < m+(latency); j++){
                if(resTable[i][j-(latency)] == 1){
                    if((table[i][j] > 0 && table[i][j] <= cs-1) || (table[i][j] == -1)){
                        flag = 1;
                        table[i][j] = -1;
                        cout<< "collision occured with task " <<cs << " at time " <<i+1<<" "<< j+1 << endl;
                    }else{
                        table[i][j] = cs;
                    }
                }else{
                    continue;
                }
            }
        }
        if(flag == 0){
            cout << endl;
            cout << "No collision occured at task " << cs << endl;
        }

    }
    cout << endl << endl<< "Output after multiple task"<< endl;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m+maxLatency;j++){
                cout << table[i][j] << " ";
            }cout << endl;
        }
    
    return 0;
}