//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/14889
//  BOJ14889 스타트와 링크

#include <iostream>
#include <vector>

using namespace std;

int map[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
        }
    }
    
    int ans=9999;
    
    for(int i=0; i<(1<<N); i++){    //000000~111111(모두 0번팀에 속하는 경우부터 모두 1번팀에 속하는 경우까지)
        vector<int>first,second;
        for(int k=0; k<N; k++){
            if(i&(1<<k)) first.push_back(k);    // i번째 집합에 k가 포함되어 있으면, 1번팀
            else second.push_back(k);           // 포함되어 있지 않다면, 2번팀
        }
        
        if(first.size()!=N/2) continue;  //팀이 반반씩 안 나뉘어 졌을때 진행x
        int scoreA=0,scoreB=0;
        for(int a=0; a<first.size(); a++){
            for(int b=0; b<second.size(); b++){
                if(a==b) continue;
                scoreA+=map[first[a]][first[b]];
                scoreB+=map[second[b]][second[a]];
            }
        }
        ans=min(ans,abs(scoreA-scoreB));
    }
    cout<<ans;
}
