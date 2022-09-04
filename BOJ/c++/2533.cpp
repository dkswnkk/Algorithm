/*
    본인이 얼리어답터라면 자식노드는 얼리어답터 이거나 아니어도 된다.
    본인이 얼리어답터가 아니라면 자식 노드는 반드시 얼리어답터여야 한다.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int>graph[1000001];
int dp[1000001][2]; //본인이 얼리답터일떄, 본인이 얼리어답터가 아닐때
int N;

void dfs(int node, int before){
    dp[node][0] = 0;
    dp[node][1] = 1;
    for(auto next: graph[node]){
        if(next != before){
            dfs(next,node);
            dp[node][0] += dp[next][1];
            dp[node][1] += min(dp[next][0], dp[next][1]);
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N-1; i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<100001; i++){
        dp[i][0] = 1e9;
        dp[i][1] = 1e9;
    }
    
    dfs(1, 0);
    cout<< min(dp[1][0], dp[1][1]);
}
