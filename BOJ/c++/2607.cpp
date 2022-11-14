#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    string base; cin>>base;
    int ans = 0;
    for(int i=0; i<n-1; i++){
        string cmp; cin>>cmp;
        int cnt = 0;
        for(int j=0; j<base.length(); j++){
            for(int k=0; k<cmp.length(); k++){
                if(base[j] == cmp[k]){
                    cnt++;
                    cmp[k] = '*';   // 의미 없는 값
                    break;
                }
            }
        }
        if(base.length() - cnt <=1 && cmp.length() - cnt <= 1) ans++;
    }
    cout<<ans;
}
