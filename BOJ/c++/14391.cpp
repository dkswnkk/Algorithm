//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/14391
//  BOJ14391 종이 조각

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int map[4][4];

int main(){
    
    
    int N,M; cin>>N>>M;
    
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            scanf("%1d",&map[i][k]);
        }
    }
    
    int ans=-9999;
    
    for(int i=0; i<(1<<N*M); i++){ //0: -(가로), 1:|(세로)
        int sum=0;
        for(int a=0; a<N; a++){ //가로 의 누적 합 검사
            int score=0;
            for(int b=0; b<M; b++){
                int row=a*M+b;  //각 칸마다 순서대로 번호를 매겼을때 인덱스 번호;
                if((i&(1<<row))==0) score=score*10+map[a][b];  //연속되는 가로 일때 점수 더해줌
                else{
                    sum+=score;
                    score=0;
                }
            }
            sum+=score;
        }
        
        
        for(int a=0; a<M; a++){ //세로의 누적 합 검사
            int score=0;
            for(int b=0; b<N; b++){
                int col=b*M+a;
                if((i&(1<<col))!=0) score=score*10+map[b][a];  //연속되는 가로 일때 점수 더해줌
                else{
                    sum+=score;
                    score=0;
                }
            }
            sum+=score;
        }
        ans=max(ans,sum);
    }
    
    cout<<ans;
}



