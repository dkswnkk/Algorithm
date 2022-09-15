#include <iostream>
#include <memory.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n, d; cin>>n>>d;
        int map[501][501] = {0, };
        int temp[501][501];
        for(int i=0; i<n; i++){
            for(int k=0; k<n; k++){
                cin>>map[i][k];
            }
        }
        memcpy(temp, map, sizeof(temp));
        if(d > 0){   // 시계방향 45도 회전
            int cnt = d / 45;
            while(cnt--){
                for(int i=0; i<n; i++) temp[i][(n+1)/2 - 1] = map[i][i];
                for(int i=0; i<n; i++) temp[i][i] = map[(n+1)/2 - 1][i];
                for(int i=n-1; i>=0; i--) temp[(n+1)/2 - 1][n-1-i] = map[i][n-1-i];
                for(int i=n-1; i>=0; i--) temp[i][n-1-i] = map[i][(n+1)/2 - 1];
                memcpy(map, temp, sizeof(map));
            }
        }
        else{   // 반 시계방향 45도 회전
            int cnt = abs(d) / 45;
            while(cnt--){
                for(int i=0; i<n; i++) temp[i][i] = map[i][(n+1)/2 - 1];
                for(int i=0; i<n; i++) temp[(n+1)/2 - 1][i] = map[i][i];
                for(int i=n-1; i>=0; i--) temp[i][n-1-i] = map[(n+1)/2 - 1][n-1-i];
                for(int i=n-1; i>=0; i--) temp[i][(n+1)/2 - 1] = map[i][n-1-i];
                memcpy(map, temp, sizeof(map));
            }
        }
        for(int i=0; i<n; i++){
            for(int k=0; k<n; k++){
                cout<<temp[i][k] << ' ';
            }
            cout<<'\n';
        }
    }
}
