#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    vector<pair<int,int>> v;
    
    for(int i=0; i<N; i++){
        int start, end; cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<v.size(); i++){
        if(pq.empty()) pq.push(v[i].second);
        else{
            if(pq.top()<=v[i].first) pq.pop();
            pq.push(v[i].second);
        }
    }
    cout<<pq.size();
}
