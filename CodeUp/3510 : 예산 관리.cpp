#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;
int B,N,ans;

void backtracking(int sum,int index){
    if(sum>B) return;
    ans= max(ans,sum);
    for(int i=index+1; i<N; i++){
        if(sum+v[i]>B) continue;
        backtracking(sum+v[i], i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>B;
    cin>>N;
    
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    
    sort(v.begin(),v.end(),greater<>());
    for(int i=0; i<N; i++){
        backtracking(v[i], i);
    }
   
    cout<<ans;
}
