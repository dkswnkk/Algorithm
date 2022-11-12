#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    for(int T=1; T<=N; T++){
        vector<int> arr(1001);
        int n = 0;
        int cnt = 0;
        for(int k=-1; k<20; k++){
            if(k==-1) cin>>n;
            else cin>>arr[k];
        }
        vector<int> v;
        for(int i=0; i<20; i++){
            int max = -1;
            int index = -1;
            if(v.empty()){
                v.push_back(arr[i]);
                continue;
            }
            for(int k=v.size()-1; k>=0; k--){
                max = v[k];
                if(max <= v[k] && v[k]>arr[i]){
                    cnt++;
                    max = v[k];
                    index = k;
                }
            }
            if(index != -1){
                v.insert(v.begin() + index, arr[i]);
            }
            else v.push_back(arr[i]);
        }
        cout<<n << ' '<<cnt<<'\n';
    }
    
}
