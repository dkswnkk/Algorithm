#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    vector<lli> v(N);
    for(int i=0; i<N; i++) cin>>v[i];
    sort(v.begin(), v.end());
    lli M = 0;
    
    if(N&1){
        M = v.back();
        for(int i=0; i<N-1; i++){
            if(i == 0) M = max(M, v[i] + v[N-2 - i]);
            else M = max(M, v[i] + v[N-2 - i]);
        }
    }
    else{
        for(int i=0; i<N; i++){
            M = max(M, v[i] + v[N-1 - i]);
        }
    }
    
    cout<<M;
}
