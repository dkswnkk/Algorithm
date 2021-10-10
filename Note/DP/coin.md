## Coin ##
- [n개의 동전으로 k원을 만드는 '경우의 수'](#1)
- [n개의 동전으로 k원을 만들수 있는 '최소한의 동전 갯수'](#2)



<a name="1"></a>
## [n개의 동전으로 k원을 만드는 '경우의 수'](https://www.acmicpc.net/problem/2293) ##

```cpp
#include <iostream>
using namespace std;

int dp[10001];
int coin[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k; cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        cin>>coin[i];
    }
    dp[0]=1;
    for(int i=1 ; i<=n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j]+=dp[j-coin[i]];
        }
    }
    cout<<dp[k];
}
```
![스크린샷 2021-10-11 오전 1 26 38](https://user-images.githubusercontent.com/74492426/136704730-122e10d5-68ed-41f9-aa57-d9c9ec55ccf5.png)


<a name="2"></a>
## [n개의 동전으로 k원을 만들수 있는 '최소한의 동전 갯수'](https://www.acmicpc.net/problem/2294) ##
```cpp
#include <iostream>
#include <algorithm>
#define INF 2e9

using namespace std;

int coin[101];
int dp[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k; cin>>n>>k;
    
    fill(dp, dp+100001, INF);
    
    for(int i=1; i<=n; i++){
        cin>>coin[i];
        dp[coin[i]]=1;
    }
    
    dp[0]=0;
    
    for(int i=1; i<=n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }
    
    if (dp[k]==2e9) cout <<-1;
    else cout<<dp[k];
}
```


