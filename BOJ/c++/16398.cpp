//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/16398
//  BOJ16398 행성 연결

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long sum;

vector<pair<int,pair<int,int>>>edges;
int parent[1001];

int find_parent(int x){
    if(x==parent[x]) return x;
    else return parent[x]=find_parent(parent[x]);       // x = find_parent(parent[x]) 시에 시간초과
}

void union_parent(int a,int b){
    a=find_parent(a);
    b=find_parent(b);
    
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        parent[i]=i;
    }
    
    for(int i=0; i<n; i++){
        for(int k=0; k<n; k++){
            int cost; cin>>cost;
            if (i < k) edges.push_back({cost,{i,k}});
        }
    }
    
    sort(edges.begin(),edges.end());
    
    for(int i=0; i<edges.size(); i++){
        int cost= edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        
        if(find_parent(a)!=find_parent(b)){
            union_parent(a, b);
            sum+=cost;
        }
    }
    cout<<sum;
}
