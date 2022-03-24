// 23:14~23:57

#include <iostream>
using namespace std;

int dp[4001][4001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1,s2; cin>>s1>>s2;
    int ans = 0;
    
    for(int i=0; i<s1.length(); i++){
        for(int k=0; k<s2.length(); k++){
            if(i==0||k==0){
                if(s1[i]==s2[k]) dp[i][k]=1;
            }
            else if(s1[i]==s2[k]) dp[i][k] = dp[i-1][k-1]+1;
            ans = max(ans, dp[i][k]);
        }
    }
    cout<<ans;
    
}
