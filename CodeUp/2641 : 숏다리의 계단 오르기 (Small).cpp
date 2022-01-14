#include <iostream>

using namespace std;

int dp[16];
int N,ans;
void dfs(int current,int before_step,int before_before_step){
    if(current==N){
        ans++;
        return;
    }
    else if(current>N) return;
    else{
        if(before_step==3||before_before_step==3){
            dfs(current+1,1,before_step);
            dfs(current+2,2,before_step);
        }
        else{
            dfs(current+1,1,before_step);
            dfs(current+2,2,before_step);
            dfs(current+3,3,before_step);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    dfs(1,1,0);   //첫 시작을 한칸
    dfs(2,2,0);   //첫 시작을 두칸
    dfs(3,3,0);   //첫 시작을 세칸
    cout<<ans;
    
}
