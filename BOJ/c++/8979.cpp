#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int country[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K; cin>>N>>K;
    vector<pair<int,pair<int,pair<int,int>>>> v; // {금, 은, 동, 나라 번호}
    
    for(int i=0; i<N; i++){
        int num, gold, silver, bronze; cin>>num>>gold>>silver>>bronze;
        v.push_back({gold, {silver, {bronze, num}}});
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    int be_gold = 0, be_silver = 0, be_bronze = 0, be_index = 0;
    int same_rank = 0;
    for(auto it: v){
        int now_gold = it.first;
        int now_silver = it.second.first;
        int now_bronze = it.second.second.first;
        int now_index = it.second.second.second;
        if(now_gold == be_gold && now_silver == be_silver && now_bronze == be_bronze){
            country[now_index] = country[be_index];
            same_rank++;
        }
        else{
            country[now_index] = country[be_index] + 1 + same_rank;
            same_rank = 0;
        }
        be_gold = now_gold;
        be_silver = now_silver;
        be_bronze = now_bronze;
        be_index = now_index;
    }
    
    cout<<country[K];
}

