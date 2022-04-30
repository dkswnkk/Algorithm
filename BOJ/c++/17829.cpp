// 13:00 ~ 13:50
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>>v;
int N;

int dx[3] = {1,0,1};
int dy[3] = {0,1,1};

int find(int i, int k){
    priority_queue<int>pq;
    pq.push(v[i][k]);
    for(int j=0; j<3; j++){
        int nx = i+dx[j];
        int ny = k+dy[j];
        pq.push(v[nx][ny]);
    }
    pq.pop();
    return pq.top();
}

vector<vector<int>> divide(vector<vector<int>> &v, int n){
    
    vector<vector<int>>fin;
    
    for(int i=0; i<n; i+=2){
        vector<int>ing;
        for(int k=0; k<n; k+=2){
            ing.push_back(find(i,k));
        }
        fin.push_back(ing);
    }
    
    return fin;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    for(int i=0; i<N; i++){
        vector<int>temp;
        for(int k=0; k<N; k++){
            int inp; cin>>inp;
            temp.push_back(inp);
        }
        v.push_back(temp);
    }
    
    while(v.size()!=1){
        vector<vector<int>>temp =divide(v, v[0].size());
        v = temp;
    }
    
    cout<<v[0][0];
}
