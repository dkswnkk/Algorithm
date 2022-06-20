#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int> left;
    priority_queue<int,vector<int>, greater<>> right;
    
    int N; cin>>N;
    for(int i=1; i<=N; i++){
        int inp; cin>>inp;
        
        if(i==1) left.push(inp);
        else if(right.empty()){
            if(left.top()<inp) right.push(inp);
            else left.push(inp);
        }
        else{
            if(inp>right.top()) right.push(inp);
            else left.push(inp);
        }
        int diff = abs((int)right.size() - (int)left.size());
        if(diff>=2){
            if(right.size()>left.size()){
                left.push(right.top());
                right.pop();
            }
            else{
                right.push(left.top());
                left.pop();
            }
        }
        
        if(i&1){    //홀수일 때
            if(right.size()>left.size()) cout<<right.top()<<'\n';
            else cout<<left.top()<<'\n';
        }
        else{   //짝수일 때
            cout<<min(left.top(), right.top())<<'\n';
        }
        
    }
}
