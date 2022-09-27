#include <iostream>
#include <memory.h>

using namespace std;

int D[10001], S[10001], v[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K; cin>>N>>K;
    for(int i=1; i<=N; i++) cin>>S[i];
    for(int i=1; i<=N; i++) cin>>D[i];
    
    
    while(K--){
        for(int i=1; i<=N; i++){
            v[D[i]] = S[i];
        }
        memcpy(S,v,sizeof(S));
    }
    for(int i=1; i<=N; i++) cout<< v[i] << ' ';
}
