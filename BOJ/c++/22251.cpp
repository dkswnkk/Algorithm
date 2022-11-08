#include <iostream>
using namespace std;
/*
    https://astrid-dm.tistory.com/444
 */

int N, K, P, X; // N = 1~N층, K = 디스플레이 최대 자리의 수, P = 최대 P개 반전 가능, X = 멈춰있는 층

bool num[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},  //0
    {0, 0, 1, 0, 0, 0, 1},  //1
    {0, 1, 1, 1, 1, 1, 0},  //2
    {0, 1, 1, 1, 0, 1, 1},  //3
    {1, 0, 1, 1, 0, 0, 1},  //4
    {1, 1, 0, 1, 0, 1, 1},  //5
    {1, 1, 0, 1, 1, 1, 1},  //6
    {0, 1, 1, 0, 0, 0, 1},  //7
    {1, 1, 1, 1, 1, 1, 1},  //8
    {1, 1, 1, 1, 0, 1, 1}   //9
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        
    cin>>N>>K>>P>>X;
    
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(X==i) continue;
        int cnt = 0;
        int now = X, next = i;
        for(int j=0; j<K; j++){
            for(int k=0; k<7; k++){
                if(num[now%10][k] != num[next%10][k]) cnt++;
            }
            now /= 10;
            next /= 10;
        }
        if(cnt <= P) ans++;
    }
    cout<<ans;
}
