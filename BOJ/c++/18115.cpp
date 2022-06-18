#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    vector<int>v(N);
    deque<int>dq;
    for(int i=0; i<N; i++) cin>>v[i];
    reverse(v.begin(),v.end());
    int num = 1;
    
    for(int i:v){
        if(i==1) dq.push_back(num);
        else if(i==2){
            int temp = dq.back();
            dq.pop_back();
            dq.push_back(num);
            dq.push_back(temp);
        }
        else if(i==3) dq.push_front(num);
        num++;
    }
    
    while(!dq.empty()){
        int out = dq.back();
        cout<<out<<' ';
        dq.pop_back();
    }
}
