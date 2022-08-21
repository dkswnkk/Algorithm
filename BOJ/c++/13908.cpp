#include <iostream>

using namespace std;


int N, M, ans;
bool num[10], visited[10];


void backtracking(int depth, string _num){
    
    if(depth == N){
        bool flag = true;
        for(int i=0; i<10; i++){
            if(num[i]){
                if(_num.find(i+'0') == string::npos){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) ans++;
        
        return;
    }
    
    for(int i=0; i<=9; i++){
        visited[i] = 1;
        backtracking(depth+1, _num + to_string(i));
        visited[i] = 0;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    
    for(int i=0; i<M; i++){
        int inp; cin>>inp;
        num[inp] = 1;
    }
    backtracking(0, "");
    
    cout<<ans;
}
