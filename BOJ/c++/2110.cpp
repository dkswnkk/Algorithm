#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<int> arr;
/*
 간격을 얼마로 할건지를 이분탐색을 통해 설정
 */
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c; cin>>n>>c;
    for(int i=0; i<n; i++){
        int inp; cin>>inp;
        arr.push_back(inp);
    }
    
    sort(arr.begin(), arr.end());
    
    ll l = 0, r = arr[n-1];
    ll ans = 0;
    
    while(l<=r){
        ll mid = (l + r) / 2; // 간격
        int install_cnt = 1;   // 제일 처음 위치는 무조건 설치
        int start = arr[0];
        for(int i=1; i<n; i++){
            int end = arr[i];
            if(end - start >= mid){
                install_cnt++;
                start = end;
            }
        }
        if(install_cnt < c){
            r = mid - 1;
        }
        else{
            l = mid + 1;
            ans = max(ans, mid);
        }
        
    }
    cout<<ans;
}
