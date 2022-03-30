#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K; cin>>N>>K;
    
    int ans = 0;
    
    for(ans;; ans++){
        int cnt = 0;
        int temp_N = N;
        while(temp_N!=0){
            if(temp_N%2) cnt++;
            temp_N/=2;
        }
        if(cnt<=K) break;
        N++;
    }
    
    cout<<ans;
}


