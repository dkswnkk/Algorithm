#include <iostream>
#include <unordered_map>
using namespace std;

int train[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin>>N>>M;
    for(int i=0; i<M; i++){
        int cmd; cin>>cmd;
        if(cmd == 1 || cmd == 2){
            int num, seat; cin>>num>>seat;
            if(cmd == 1){
                train[num] |= 1<<seat;
            }
            if(cmd == 2){
                train[num] &= ~(1<<seat);
            }
        }
        else{
            int num; cin>>num;
            if(cmd == 3){
                train[num] = train[num] << 1;
                train[num] &= ~(1<<21);
            }
            if(cmd == 4){
                train[num] = train[num] >> 1;
                train[num] &= ~1;
            }
        }
    }
    
    unordered_map<int,int> check;
    for(int i=1; i<=N; i++) check[train[i]]++;
    cout<<check.size();
}
