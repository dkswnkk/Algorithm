#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    sort(v.begin(), v.end(), greater<int>());
    
    int ans = 0, before = 0;
    bool flag = false;
    int negative_idx = -1;
    for(int i=0; i<N; i++){
        if(v[i] <= 0){
            negative_idx = i;
            break;
        }
        else if(!flag){
            if(v[i] > 1){
                flag = true;
                before = v[i];
            }
            else if(v[i] == 1){
                before = v[i];
                flag = true;
            }
        }
        else{
            if(v[i] > 1){
                ans += v[i] * before;
                before = 0;
                flag = false;
            }
            else if(v[i] == 1){
                if(flag){
                    flag = false;
                    ans += max(v[i] + before, v[i] * before);
                    before = 0;
                }
            }
        }
    }
    
    if(flag && before != 0) ans += before;
    else flag = true;
    flag = false;
    before = 0;
    
    if(negative_idx != -1){
        for(int i=N-1; i>=negative_idx; i--){
            if(!flag){
                flag = true;
                before = v[i];
            }
            else{
                ans += v[i] * before;
                before = 0;
                flag = false;
            }
        }
    }
    if(flag) ans += before;
    cout<<ans;
}
