#include <iostream>
#include <deque>
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
    
    sort(dq.begin(), dq.end(), greater<int>());
    double drink = dq.front();
    dq.pop_front();
    
    while(!dq.empty()){
        if(drink>dq.front()/2.0) drink += dq.front()/2.0;
        else drink = dq.front() + drink/2.0;
        dq.pop_front();
    }
    cout<<drink;
}
