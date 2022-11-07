#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;

int arr[60001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,d,k,c; cin>>N>>d>>k>>c;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
        arr[i+N] = arr[i];
    }
    
    deque<int> dq;
    unordered_map<int,int> cnt;
    
    bool coupon = false;
    int ans = -1;
    for(int i=0; i<N*2; i++){
        if(dq.size() < k){
            dq.push_back(arr[i]);
            if(arr[i] == c) coupon = true;
            cnt[arr[i]]++;
        }
        if(dq.size() == k){
            if(coupon) ans = max(ans, (int)cnt.size());
            else ans = max(ans, (int)cnt.size() + 1);
            int front = dq.front();
            if(front == c && cnt[front] <=1) coupon = false;
            dq.pop_front();
            if(cnt[front] <= 1) cnt.erase(front);
            else cnt[front]--;
        }
    }
    cout<< ans;
}
