#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> min_heap;    // {끝나는 시간, 좌석번호}
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> seats;    // {좌석번호, 끝나는 시간}
    vector<pair<int,int>>time;
    vector<int>cnt(N);
    int ans = 0;
    
    for(int i=0; i<N; i++){
        int start, end; cin>>start>>end;
        time.push_back({start,end});
    }
    
    sort(time.begin(),time.end());
    int computer_num = 0;
    
    for(int i=0; i<N; i++){
        int start = time[i].first;
        int end = time[i].second;
        
        while(!min_heap.empty()){
            if(min_heap.top().first<start){
                seats.push({min_heap.top().second, min_heap.top().first});
                min_heap.pop();
            }
            else break;
        }
        
        if(seats.empty()){
            min_heap.push({end, ++computer_num});
            cnt[computer_num]++;
        }
        else{
            int seat = seats.top().first;
            min_heap.push({end, seat});
            cnt[seat]++;
            seats.pop();
        }
    }
    
    
    cout<<computer_num<<'\n';
    for(int i=1; i<=computer_num; i++){
        cout<<cnt[i]<<' ';
    }
}
