#include <iostream>
#include <cmath>
using namespace std;

int map[2188][2188];
bool visited[2188][2188];
int N;

int cnt[3];
bool check(int r, int c, int div){
    int cmp = map[r][c];
    for(int i=r; i<r+div; i++){
        for(int k=c; k<c+div; k++){
            if(map[i][k] != cmp) return false;
        }
    }
    return true;
}

void go(int r, int c, int div){
    if(check(r,c, div)){
        cnt[map[r][c] + 1] ++;
    }
    else{
        int size = div / 3;
        for(int i=0; i<3; i++){
            for(int k=0; k<3; k++){
                go(r+size*i, c+size*k, size);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
        }
    }
    go(0,0,N);
    
    cout<<cnt[0]<<'\n'<<cnt[1]<<'\n'<<cnt[2];
}
