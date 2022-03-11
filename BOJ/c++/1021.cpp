// 22:49~23:22
#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M,ans=0; cin>>N>>M;
    deque<int>dq;
    
    for(int i=1; i<=N; i++) dq.push_back(i);
    
    for(int i=0; i<M; i++){
        int find; cin>>find;
        
        if(find == dq.front()) dq.pop_front();
        else{
            int cnt_second=0, cnt_third=0;
            deque<int> temp_second = dq, temp_third = dq;
            while(true){    // 2번 연산
                if(temp_second.front()==find){
                    temp_second.pop_front();
                    break;
                }
                temp_second.push_back(temp_second.front());
                temp_second.pop_front();
                cnt_second++;
            }
            
            while(true){    //3번 연산
                if(temp_third.front()==find){
                    temp_third.pop_front();
                    break;
                }
                temp_third.push_front(temp_third.back());
                temp_third.pop_back();
                cnt_third++;
            }
            
            if(cnt_second<cnt_third){
                ans += cnt_second;
                dq = temp_second;
            }
            else{
                ans += cnt_third;
                dq = temp_third;
            }
            
        }
        
    }
    cout<<ans;
}
