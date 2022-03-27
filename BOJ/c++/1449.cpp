#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,L; cin>>N>>L;
    vector<int>v;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    sort(v.begin(),v.end());
    double start = 0, end = 0, now = 0;
    int cnt = 0;
    for(int i=0; i<N; i++){
        start = v[i]-0.5;
        end = v[i]+0.5;
        if(now<end){
            if(now<start) now = start;
            int temp_cnt = (end - now) / L;
            if(temp_cnt==0) temp_cnt = 1;
            cnt += temp_cnt;
            now = start+ (L * temp_cnt);
        }
        
    }
    cout<<cnt;
    
}
