#include <iostream>
using namespace std;

int N, M;

char map[3001][3001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;;
    for(int i=0; i<N; i++){
        string inp; cin>>inp;
        for(int k=0; k<M; k++){
            map[i][k] = inp[k];
        }
    }
    
    int move_cnt = 1e9;
    for(int i=0; i<M; i++){ // 몇 칸 이동할지 찾기
        int meteor = 0;
        int ground = 0;
        for(int k=0; k<N; k++){
            if(map[k][i] == 'X') meteor = k + 1;
            if(map[k][i] == '#'){
                ground = k + 1;
                break;
            }
        }
        if(meteor !=0 && ground != 0){
            move_cnt = min(move_cnt, ground - meteor - 1);
        }
    }
    
    for(int i=0; i<M; i++){ // 유성 이동
        for(int k=N-1; k>=0; k--){
            if(map[k][i] == 'X'){
                map[k+move_cnt][i] = 'X';
                map[k][i] = '.';
            }
        }
    }
    for(int i=0; i<N; i++){ // 출력
        for(int k=0; k<M; k++){
            cout<<map[i][k];
        }
        cout<<'\n';
    }
}
