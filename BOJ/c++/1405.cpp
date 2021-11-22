#include <iostream>
using namespace std;

int N,a,b,c,d;

int map[31][31];
int visited[31][31];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

double percent[4],out=0.0;



void dfs(int depth, int x, int y,double ans){
    visited[x][y]=1;
    
    if(depth==N){
        out += ans;
        return;
    }
    
    for(int i=0; i<4; i++){
        if(percent[i]==0) continue;
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!visited[nx][ny]&&percent[i]!=0){
            visited[nx][ny]=1;
            dfs(depth+1,nx,ny,ans*percent[i]);
            visited[nx][ny]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<4; i++){
        double inp; cin>>inp;
        percent[i] = inp/100.0;
    }
    
    dfs(0,14,14,1); //  시작점이 14,14 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    cout.precision(11);
    cout << fixed<<out;
}
