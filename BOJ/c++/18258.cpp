// 23:21~23:27

#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    deque<int>dq;
    while(N--){
        string cmd; cin>>cmd;
        
        if(cmd=="push"){
            int num; cin>>num;
            dq.push_back(num);
        }
        else if(cmd=="front"){
            if(dq.empty()) cout<<-1<<'\n';
            else cout<<dq.front()<<'\n';
        }
        else if(cmd=="back"){
            if(dq.empty()) cout<<-1<<'\n';
            else cout<<dq.back()<<'\n';
        }
        else if(cmd=="size"){
            cout<<dq.size()<<'\n';
        }
        else if(cmd=="empty"){
            if(dq.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(cmd=="pop"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }
    }
}
