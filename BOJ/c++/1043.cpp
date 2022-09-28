#include <iostream>
#include <vector>
using namespace std;

int parent[101];
int N, M;

void union_parent(vector<vector<int>> &party){
    for(int i=0; i<party.size(); i++){
        bool flag = false;
        for(int k=0; k<party[i].size(); k++){
            if(parent[party[i][k]] == -1){
                flag = true;
                break;
            }
        }
        if(flag){
            for(int k=0; k<party[i].size(); k++){
                parent[party[i][k]] = -1;
            }
        }
    }
    for(int i=party.size()-1; i>=0; i--){
        bool flag = false;
        for(int k=0; k<party[i].size(); k++){
            if(parent[party[i][k]] == -1){
                flag = true;
                break;
            }
        }
        if(flag){
            for(int k=0; k<party[i].size(); k++){
                parent[party[i][k]] = -1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    int know; cin>>know;
    for(int i=0; i<know; i++){
        int peo; cin>>peo;
        parent[peo] = -1;
    }
    
    vector<vector<int>> party;
    
    for(int i=0; i<M; i++){
        int cnt; cin>>cnt;
        vector<int> temp;
        for(int k=0; k<cnt; k++){
            int peo; cin>>peo;
            temp.push_back(peo);
        }
        party.push_back(temp);
    }
    
    int cnt = 50;
    while(cnt--) union_parent(party);

    int ans = 0;
    for(int i=0; i<party.size(); i++){
        bool flag = true;
        for(int k=0; k<party[i].size(); k++){
            if(parent[party[i][k]] == -1){
                flag = false;
                break;
            }
        }
        if(flag) ans ++;
    }
    
    cout<<ans;
}
