#include <string>
#include <vector>
#define MOD 1234567
using namespace std;

int dp[100001];

int solution(int n) {
    int answer = 0;
    
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2; i<=n; i++){
        dp[i]=(dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
    }
    answer=dp[n];
    
    return answer;
}
