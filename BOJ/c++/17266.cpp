#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    vector<int> v(M);
    
    double height = 0;
    for(int i=0; i<M; i++) cin>>v[i];
    
    if(M==1) height = N;
    height = fmax(v.front(), (ceil(N-v.back())));
    for(int i=0; i<M-1; i++){
        height = fmax(height, ceil((v[i+1]-v[i])/2.0));
    }
    
    cout<<(int)height;
}
