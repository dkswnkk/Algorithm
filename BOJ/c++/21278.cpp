#include <iostream>
#define INF 1e9
using namespace std;


int N, M;
int d[101][101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<101; i++){
        for(int k=0; k<101; k++){
            if(i==k) d[i][k] = 0;
            else d[i][k] = INF;
        }
    }
    cin>>N>>M;
    
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    
    for(int k=1; k<=N; k++){
        for(int a=1; a<=N; a++){
            for(int b=1; b<=N; b++){
                d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
            }
        }
    }
    
    int chick1 = 0, chick2 = 0;
    int min_d = 1e9;
    
    for(int i=1; i<=N; i++){    // 치킨집 고르기
        for(int j=i+1; j<=N; j++){
            int temp_d = 0;
            for(int k = 1; k<=N; k++){
                temp_d += min(i==k?0:d[i][k], j==k?0:d[j][k]);    // 치킨집까지의 거리 갱신
            }
            if(temp_d < min_d){
                min_d = temp_d;
                chick1 = i;
                chick2 = j;
            }
        }
    }
    
    cout<< chick1 << ' ' << chick2 << ' ' << min_d * 2;
}
