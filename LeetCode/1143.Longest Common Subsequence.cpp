class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    int dp[1001][1001];
    
    for(int i=1; i<=text1.length(); i++){
        for(int k=1; k<=text2.length(); k++){
            if(text1[i-1]==text2[k-1]) dp[i][k]=dp[i-1][k-1]+1;
            else dp[i][k]=max(dp[i-1][k],dp[i][k-1]);
        }
    }
        return dp[text1.length()][text2.length()];
    }
};
