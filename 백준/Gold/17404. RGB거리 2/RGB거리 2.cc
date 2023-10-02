#include <iostream>
#define INF 1e9
using namespace std;

int map[1001][3];
int dp[1001][3];
int N;

void init(){
    for(int i=0; i<N; i++){
        dp[i][0] = INF;
        dp[i][1] = INF;
        dp[i][2] = INF;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<3; k++){
            cin>>map[i][k];
        }
    }
    
    int ans = INF;
    for(int i=0; i<3; i++){
        init();
        
        for(int k=0; k<3; k++){
            if(i == k){
                dp[0][k] = map[0][k];
            }
            else{
                dp[0][k] = INF;
            }
        }
        
        for(int k=1; k<N; k++){
            dp[k][0] = map[k][0] + min(dp[k-1][1], dp[k-1][2]);
            dp[k][1] = map[k][1] + min(dp[k-1][0], dp[k-1][2]);
            dp[k][2] = map[k][2] + min(dp[k-1][0], dp[k-1][1]);
        }
        
        for(int k = 0; k<3; k++){
            if(k != i){
                ans = min(ans, dp[N-1][k]);
            }
        }
        
    }
    
    cout<<ans;
    
}
