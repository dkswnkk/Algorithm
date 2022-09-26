#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        string a, b; cin>>a>>b;
        queue<int> zero, one;
        int ans = 0;
        
        for(int i=0; i<a.length(); i++){
            if(a[i] != b[i]){
                if(a[i] == '0') zero.push(i);
                else if(a[i] == '1') one.push(i);
            }
        }
        int len = min(zero.size(), one.size());
        
        while(len--){   // 하나의 이진수에서 서로 다른 자리에 있는 두 숫자의 위치를 바꾼다.
            swap(a[zero.front()], a[one.front()]);
            zero.pop();
            one.pop();
            ans++;
        }
        for(int i=0; i<a.length(); i++){    // 하나의 이진수에서 임의의 자리의 숫자를 0 또는 1로 바꾼다.
            if(a[i] != b[i]) ans++;
        }
        cout<<ans<<'\n';
    }
    
}
