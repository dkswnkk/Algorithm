#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int len = land.size();
    for(int i=0; i<4; i++) dp[0][i] = land[0][i];
    
    for(int i=1; i<len; i++){
        for(int k=0; k<4; k++){
            if(k==0) dp[i][k] = max({dp[i-1][k+1],dp[i-1][k+2],dp[i-1][k+3]})+land[i][k];
            if(k==1) dp[i][k] = max({dp[i-1][k-1],dp[i-1][k+1],dp[i-1][k+2]})+land[i][k];
            if(k==2) dp[i][k] = max({dp[i-1][k-2],dp[i-1][k-1],dp[i-1][k+1]})+land[i][k];
            if(k==3) dp[i][k] = max({dp[i-1][k-3],dp[i-1][k-2],dp[i-1][k-1]})+land[i][k];
            answer = max(answer, dp[i][k]);
        }
    }
    
    return answer;
}
