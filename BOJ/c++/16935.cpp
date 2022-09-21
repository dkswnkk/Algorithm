#include <iostream>
#include <memory.h>

using namespace std;

int N, M, R;

int map[101][101];

void print(){
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cout<<map[i][k]<<' ';
        }
        cout<<'\n';
    }
}


void cmd1(){   // 배열 상하 반전
    int temp[101][101] = {0, };
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            temp[N-i-1][k] = map[i][k];
        }
    }
    memcpy(map, temp, sizeof(map));
}
void cmd2(){   // 배열 좌우 반전
    int temp[101][101] = {0, };
    for(int i=0; i<M; i++){
        for(int k=0; k<N; k++){
            temp[k][M-i-1] = map[k][i];
        }
    }
    memcpy(map, temp, sizeof(map));
}

void cmd3(){  // 시계방향 90도 회전
    int temp[101][101] = {0, };
    swap(N, M); // (6, 8) -> (8, 6)
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            temp[i][k] = map[M - k -1][i];
        }
    }
    memcpy(map, temp, sizeof(map));
}

void cmd4(){    //시계 반대방향 90도 회전
    int temp[101][101] = {0, };
    swap(N, M);  // (6, 8) -> (8, 6)
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            temp[i][k] = map[k][N-1-i];
        }
    }
    memcpy(map, temp, sizeof(map));
}

void cmd5(){
    int temp[101][101] = {0, };
    for(int i=0; i<N/2; i++){   // 1 -> 2
        for(int k=0; k<M/2; k++){
            temp[i][M/2+k] = map[i][k];
        }
    }
    for(int i=0; i<N/2; i++){   // 2 -> 3
        int idx = M/2;
        for(int k=M/2; k<M; k++){
            temp[N/2+i][idx++] = map[i][k];
        }
    }
    for(int i=N/2; i<N; i++){   // 3 -> 4
        int idx1 = i;
        int idx2 = 0;
        for(int k=M/2; k<M; k++){
            temp[idx1][idx2++] = map[i][k];
        }
        idx1++;
    }
    
    int idx = 0;
    for(int i=N/2; i<N; i++){   // 4 -> 1
        for(int k=0; k<M/2; k++){
            temp[idx][k] = map[i][k];
        }
        idx++;
    }
    memcpy(map, temp, sizeof(map));
}

void cmd6(){
    int temp[101][101] = {0, };
    for(int i=0; i<N/2; i++){   // 1 -> 2
        for(int k=0; k<M/2; k++){
            temp[i][k] = map[i][M/2+k];
        }
    }
    for(int i=0; i<N/2; i++){   // 2 -> 3
        int idx = M/2;
        for(int k=M/2; k<M; k++){
            temp[i][k] = map[N/2+i][idx++];
        }
    }
    for(int i=N/2; i<N; i++){   // 3 -> 4
        for(int k=0; k<M/2; k++){
            temp[i][M/2+k] = map[i][k];
        }
    }
    
    for(int i=0; i<N/2; i++){   // 4 -> 1
        for(int k=0; k<M/2; k++){
            temp[N/2+i][k] = map[i][k];
        }
    }
    memcpy(map, temp, sizeof(map));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M>>R;
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin>>map[i][k];
        }
    }
    
    for(int i=0; i<R; i++){
        int cmd; cin>>cmd;
        if(cmd==1) cmd1();
        if(cmd==2) cmd2();
        if(cmd==3) cmd3();
        if(cmd==4) cmd4();
        if(cmd==5) cmd5();
        if(cmd==6) cmd6();
    }
    
    print();
}
