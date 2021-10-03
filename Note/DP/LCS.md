## LCS ##
- [설명](#1)
- [가장 긴 수열 길이 찾기](#2)
- [가장 긴 수열 길이 + 수열 찾기](#3)


<a name="1"></a>
# 설명 ##
<img src = "https://user-images.githubusercontent.com/74492426/135763969-90605aa1-e0c8-46fa-a8ae-e546e7c052be.png" width="70%" height="10%">

<a name="2"></a>
## [LCS 1](https://www.acmicpc.net/problem/9251) ##
```cpp
#include <iostream>
using namespace std;

int dp[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string A,B; cin>>A>>B;
    
    for(int i=1; i<=A.length(); i++){
        for(int k=1; k<=B.length(); k++){
            if(A[i-1]==B[k-1]) dp[i][k]=dp[i-1][k-1]+1;
            else dp[i][k]=max(dp[i-1][k],dp[i][k-1]); 
        }
    }
    cout<<dp[A.length()][B.length()];
}
```

## [LCS 2](https://www.acmicpc.net/problem/9252) ##
<a name="3"></a>
```cpp
곧 추가 할것 .
}
```
