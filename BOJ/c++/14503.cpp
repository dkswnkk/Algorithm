#include <iostream>
using namespace std;

int map[51][51];

int r, c, d, N, M; // d0 북쪽, d1 동쪽, d2 남쪽, d3 서쪽
int clean_cnt = 1;
int isclean[51][51];
bool flag = false;

bool clean(){   // 왼쪽 방향에 청소할 공간이 있는지 확인
    
    int left_r = r, left_c = c; //왼쪽 방향의 청소할 공간의 좌표
    
    if(d == 0) left_c--;
    if(d == 1) left_r--;
    if(d == 2) left_c++;
    if(d == 3) left_r++;
    
    
    if((isclean[r-1][c] || map[r-1][c]) && (isclean[r][c-1] || map[r][c-1]) && (isclean[r+1][c] || map[r+1][c])  && (isclean[r][c+1] || map[r][c+1])) {   // 네 방향 모두 청소가 되어있거나 방향 모두 벽일 경우
        switch (d) {
            case 0:
                if(map[r+1][c]) flag = true;  // 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
                else r+=1; // 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
                return false;
            case 1:
                if(map[r][c-1]) flag = true;  // 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
                else c-=1; // 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
                return false;
            case 2:
                if(map[r-1][c]) flag = true;  // 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
                else r-=1; // 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
                return false;
            case 3:
                if(map[r][c+1]) flag = true;  // 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
                else c+=1; // 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
                return false;
        }
    }
    else if(!isclean[left_r][left_c] && !map[left_r][left_c]){ // 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        d = (d+3) % 4;
        r = left_r;
        c = left_c;
        return true;
    }
    
    d = (d+3) % 4;    // 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    return false;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    cin>>r>>c>>d;
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin>>map[i][k];
        }
    }
    isclean[r][c] = 1;
    
    while(true){
        if(flag || r<0 || r>=N || c<0 || c>=M) break;    //범위 안에 들지 않거나, 종료 조건을 만족 했을 경우 중단
        if(clean()){
            clean_cnt++;
            isclean[r][c] = 1;  // 현재 위치를 청소한다.
        }
    }
    
    cout<<clean_cnt;
}
