#include <iostream>
#include <deque>
using namespace std;

int arr[200001];
int cnt[200001];
deque<int> dq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K; cin>>N>>K;
    
    for(int i=0; i<N; i++) cin>>arr[i];
    
    int ans = 0;
    for(int i=0; i<N; i++){
        int num = arr[i];
        cnt[num]++;
        dq.push_back(num);
        if(cnt[num]>K){
            while(true){
                int pop = dq.front();
                if(pop == num){
                    cnt[pop]--;
                    dq.pop_front();
                    break;
                }
                else{
                    cnt[pop]--;
                    dq.pop_front();
                }
            }
        }
        ans = max(ans, (int)dq.size());
        
    }
    cout<<ans;
}
