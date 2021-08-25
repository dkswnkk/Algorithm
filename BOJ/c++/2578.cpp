//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/2578
//  BOJ2578 빙고

#include <iostream>
#include <vector>
using namespace std;


vector<pair<int,int>>map[6];

bool bingo_check(){
    int bingo_cnt=0;
    
    for(int i=0; i<5; i++){ //가로 검사
        int cnt=0;
        for(int k=0; k<5; k++){
            if(map[i][k].second==1) cnt++;
        }
        if(cnt==5) bingo_cnt++;
        if(bingo_cnt==3) return true;
    }
    
    for(int i=0; i<5; i++){ //세로검사
        int cnt=0;
        for(int k=0; k<5; k++){
            if(map[k][i].second==1) cnt++;
        }
        if(cnt==5) bingo_cnt++;
        if(bingo_cnt==3) return true;
    }
    
    int diag=0;
    for(int i=0; i<5; i++){ //대각선 검사 ↘
        if(map[i][i].second==1) diag++;
        if(diag==5) bingo_cnt++;
        if(bingo_cnt==3) return true;
    }
    diag=0;
    int a=4;
    for(int i=0; i<5; i++){ //대각선 검사 ↗
        if(map[i][a].second==1) diag++;
        a--;
        if(diag==5) bingo_cnt++;
        if(bingo_cnt==3) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    for(int i=0; i<5; i++){ //빙고판 정보 입력
        for(int k=0; k<5; k++){
            int inp; cin>>inp;
            map[i].push_back({inp,0});
        }
    }
    
    for(int i=1; i<=25; i++){ //빙고 숫자 부르기
        int inp; cin>>inp;
        for(int a=0; a<5; a++){  //빙고 숫자 체크
            for(int b=0; b<5; b++){
                if(map[a][b].first==inp){
                    map[a][b].second=1;    //숫자를 불렀을떄 1로 처라
                    if(bingo_check()){     //빙고가 되었는지 확인
                        cout<<i;
                        exit(0);
                    }
                    
                    break;
                }
            }
        }
    }
}
