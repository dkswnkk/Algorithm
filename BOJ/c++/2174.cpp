//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/2174
//  BOJ2174 로봇 시뮬레이션

#include <iostream>
#include <vector>

using namespace std;

struct info{
    int robot_num;  //로봇 번호
    int dir;        //로봇 방향 정보
    int x;          //로봇 x좌표
    int y;          //로봇 y좌표
};

int check_dir(char dir){
    if(dir=='E') return 1;
    else if(dir=='N') return 2;
    else if(dir=='W') return 3;
    else return 4;
}

int A,B,N,M;    //A= 맵 가로, B=맵 세로, N=로봇의 개수, M=로봇 명령 갯수
vector<info>simulation;  //로봇의 정보를 기입하는 테이블


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>A>>B>>N>>M;
    
    for(int i=0; i<N; i++){ //로봇의 정보를 입력
        int x,y; char dir;  //dir=방향
        cin>>x>>y>>dir;
        simulation.push_back({i+1,check_dir(dir),x,y});
    }
    
    for(int i=0; i<M; i++){
        int num,cnt; char cmd;    //num=로봇 번호, cmd=명령, cnt=명령 횟수
        cin>>num>>cmd>>cnt;
        
        for(int k=0; k<simulation.size(); k++){
            if(num==simulation[k].robot_num) num=k;
        }
        while(cnt--){
            if(cmd=='L'){   //L명령일 경우
                simulation[num].dir+=1;    //왼쪽으로 90도 회전
                if(simulation[num].dir==5) simulation[num].dir=1;
            }
            else if(cmd=='R'){  //R명령일 경우
                simulation[num].dir-=1; //오른쪽으로 90도 회전
                if(simulation[num].dir==0) simulation[num].dir=4;
            }
            
            else if(cmd=='F'){  //F명령일 경우
                
                if(simulation[num].dir==1)simulation[num].x+=1;   //방향이 현재 E 일떄 오른쪽으로 이동
                else if(simulation[num].dir==2)simulation[num].y+=1;   //방향이 현재 N 일떄 위쪽으로 이동
                else if(simulation[num].dir==3)simulation[num].x-=1;   //방향이 현재 W 일떄 왼쪽으로 이동
                else if(simulation[num].dir==4)simulation[num].y-=1;   //방향이 현재 S 일떄 아래쪽으로 이동
            }
        
        for(int z=0; z<simulation.size(); z++){  //다른 로봇이랑 위치가 겹치는지 확인
            if(simulation[z].robot_num==simulation[num].robot_num) continue;    //자기 자신이라면 무시
            if(simulation[num].x==simulation[z].x&&simulation[num].y==simulation[z].y){   //다른 로봇이랑 위치가 겹친다면 충돌
                cout<<"Robot "<<simulation[num].robot_num<<" crashes into robot "<<simulation[z].robot_num;
                exit(0);
            }
        }
        if(simulation[num].x<1||simulation[num].y<1||simulation[num].x>A||simulation[num].y>B){ //로봇이 벽이랑 충돌
            cout<<"Robot "<<simulation[num].robot_num<<" crashes into the wall";
            exit(0);
        }
        
        }
    }
    
    
    cout<<"OK";
}
