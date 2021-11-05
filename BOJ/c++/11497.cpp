#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

/*
 정규분포표처럼 배열 가운데 제일 큰 값을 넣고 양쪽에 점점 작아지는 수로 나열시킨다.
 그 후 선형탐색을 해서 차이를 구해 차이가 젤 큰  값을 출력한다.
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("jump.inp", "r", stdin);
    freopen("jump.out", "w", stdout);
    
    int T; cin>>T;
    
    while(T--){
        int n,ans=0; cin>>n;
        vector<int>v;
        for(int i=0; i<n; i++){
            int inp; cin>>inp;
            v.push_back(inp);
        }
        sort(v.begin(),v.end());
        
        
        deque<int> dq;
        int max_value;
        
        for(int i=v.size()-1; i>=0; i--){
            max_value = v[i];
            if(i&1) dq.push_back(max_value);
            else dq.push_front(max_value);
        }
        
        
        ans=max(abs(dq[0]-dq[dq.size()-1]),abs(dq[dq.size()-1]-dq[dq.size()-2]));
        
        for(int i=1; i<dq.size()-1; i++){
            ans=max(abs(dq[i]-dq[i-1]),max(abs(dq[i]-dq[i+1]),ans));
        }
        cout<<ans<<'\n';
        
    }
}
