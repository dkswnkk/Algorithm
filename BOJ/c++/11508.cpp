#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    deque<int> dq;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        dq.push_back(inp);
    }
    sort(dq.begin(),dq.end());    // 오름차순
    
    int cost = 0;
    
    while(!dq.empty()){
        if(dq.size()>=3){
            cost += dq.back();
            dq.pop_back();
            cost += dq.back();
            dq.pop_back();
            dq.pop_back();
        }
        else if(dq.size()==2){
            cost += dq.back();
            dq.pop_back();
            cost += dq.back();
            dq.pop_back();
        }
        else if(dq.size()==1){
            cost += dq.back();
            dq.pop_back();
        }
    }
    cout<<cost;
}
