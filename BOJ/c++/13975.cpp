#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        priority_queue<long long int,vector<long long int>,greater<>> pq;
        for (int i=0; i<n; i++){
            int inp; cin>>inp;
            pq.push(inp);
        }
        long long int ans = 0;
        while(!pq.empty()){
            if(pq.size()==1) break;
            long long int a = pq.top(); pq.pop();
            long long int b = pq.top(); pq.pop();
            long long int cost = a + b;
            ans += cost;
            pq.push(cost);
        }
        
        cout<<ans<<'\n';
    }
}
