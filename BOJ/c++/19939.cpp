#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K; cin>>N>>K;
    int sum = (K * (K+1)) / 2;  // 등차수열 합
    
    if(sum > N) cout << -1;
    else if((N - sum) % K == 0) cout<< K - 1;
    else cout<< K;
}
