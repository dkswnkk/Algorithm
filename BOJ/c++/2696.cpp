#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        priority_queue<int> max_heap;   // max_heap에는 중간값 이하의 값만 담겨야 한다.
        priority_queue<int,vector<int>,greater<>> min_heap;
        vector<int>ans;
        int mid = 0;
        for(int i=1; i<=n; i++){
            int number; cin>>number;
            if(i==1) mid = number;
            
            if(mid<number) min_heap.push(number);
            else max_heap.push(number);
            
            if(i&1){    // 홀수 번째 숫자일 때
                while(min_heap.size()>max_heap.size()){
                    mid = min_heap.top();
                    max_heap.push(mid);
                    min_heap.pop();
                }
                while(min_heap.size()<max_heap.size()){
                    mid = max_heap.top();
                    min_heap.push(mid);
                    max_heap.pop();
                }
                ans.push_back(mid);
            }
            
        }
        
        cout<<ans.size()<<'\n';
        for(int i=0; i<ans.size(); i++){
            if(i%10==0&&i!=0) cout<<'\n';
            cout<<ans[i]<<' ';
        }
    }
}
