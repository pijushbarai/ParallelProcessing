#include <bits/stdc++.h>
using namespace std;
set<int>s;
vector<int > forbidden,permissible,collision,binary;
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

vector<int> make_Binary(int n){
    binary.clear();
    int x = n;
    while(x){
        binary.push_back(x%2);
        x = x/2;
    }
    reverse(binary.begin(),binary.end());
    return binary;
}
int make_int(vector<int> v){
    int l = v.size();
    int sum = 0,pos = 0;
    for(int i = l-1;i >= 0;i--){
        sum  = sum + v[i]*(pow(2,pos));
        pos++;
    }
    return sum;
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
    int icv = make_int(collision);

    queue<int>state;
    map<int,bool>vis;
    state.push(icv);
    int ps;
    vector<int>network[1<<m];
    while (!state.empty())
    {
        ps = state.front();
        vis[ps] = true;
        state.pop();
        vector<int>bin = make_Binary(ps);
        int temp = ps,ans;
        int l = bin.size()-1,shift = 0;
        for(int i = l;i >= 0;i--){
            shift++;
            if(bin[i] == 0){
                // cout << ps << " shift " << shift << endl;
                temp = ps>>shift;
                ans = temp | icv;
                network[ps].push_back(ans);
                
                if(!vis[ans])
                    state.push(ans);
            }
        }
    }

    cout << "Printing states"<<endl;
    state.push(icv);
    while (!state.empty())
    {
        int ps = state.front();
        cout << "root ";
        cout<< ps << endl;
        cout << "childs " << endl;
        state.pop();

        if(vis[ps]){  
        for(int i = 0; i < network[ps].size();i++){
            cout << network[ps][i]<< " ";
            if(vis[network[ps][i]]){
                state.push(network[ps][i]);
            }
        }cout << endl;
        }
        vis[ps] = false;
    }
    
    

    return 0;
}