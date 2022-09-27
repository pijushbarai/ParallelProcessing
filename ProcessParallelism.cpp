#include <bits/stdc++.h>
using namespace std;

string process[10];
bool flag = false;
string R1,W1,R2,W2;
int dipendency[10][10];
set<char>::iterator itr;

void makeRWset1(string s){
    int l = s.size();
    for(int i = 0;i < l;i++){
        if(s[i] == ':' && s[i+1] == '=')flag = true;
        if(flag == false){
            if(s[i] >= 'a' && s[i] <= 'z'){
                W1 += s[i];
            }

        }else{
            if(s[i] >= 'a' && s[i] <= 'z'){
                R1 += s[i];
            }
        }
    }
}

void makeRWset2(string s){
    int l = s.size();
    for(int i = 0;i < l;i++){
        if(s[i] == ':' && s[i+1] == '=')flag = true;
        if(flag == false){
            if(s[i] >= 'a' && s[i] <= 'z'){
                W2 += s[i];
            }

        }else{
            if(s[i] >= 'a' && s[i] <= 'z'){
                R2+=s[i];
            }
        }
    }
}


int main(){
    freopen("input.txt","r",stdin);
    for(int  i = 0;i < 5;i++){
        getline(cin,process[i]);
    }
    bool c1,c2,c3;
    for(int i = 0;i < 5-1;i++){
        for(int j = i+1;j < 5;j++){
            c1 = false;
            c2 = false;
            c3 = false;
            R1 = "";
            R2 = "";
            W1 = "";
            W2 = "";
            flag = false;
            makeRWset1(process[i]);
            flag = false;
            makeRWset2(process[j]);

            for(int i = 0;i < R1.size();i++){
                for(int j = 0; j < W2.size();j++){
                    if(R1[i] == W2[j]){
                        c1= true;
                        // anti dependency
                    }
                }
            }
            for(int i = 0;i < W1.size();i++){
                for(int j = 0;j < R2.size();j++){
                    if(W1[i] == R2[j]){
                        c2 = true;
                        // follow dependency
                    }
                }
            }

            for(int i = 0;i < W1.size();i++){
                for(int j = 0;j < W2.size();j++){
                    if(W1[i] == W2[j]){
                        c3 = true;
                        //output dependency
                    }
                }
            }
            if((c1 == false) && (c2 == false) && (c3 == false)){
                dipendency[i][j] = 1;
                dipendency[j][i] = 1;
                cout << "process " << i+1 << " and " << j+1 <<" parallelly Executable" << endl;
            }
            else{
                // cout << "process " << i+1 << " and " << j+1 <<" NOT parallel Executeable" << endl;

            }
        }
        
    }
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cout << dipendency[i][j] << " ";
        }cout << endl;
    }
}
