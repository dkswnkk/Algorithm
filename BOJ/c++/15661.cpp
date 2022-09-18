#include <iostream>
using namespace std;

int map[21][21];
int N;
int min_ability = 1e9;
bool flag[21];

int score(){
    int start_score = 0;
    int link_score = 0;
    for(int i=1; i<=N; i++){
        for(int k=1; k<=N; k++){
            if(flag[i] && flag[k]){
                start_score += map[i][k];
            }
            if(!flag[i] && !flag[k]){
                link_score += map[i][k];
            }
        }
    }
    return abs(start_score - link_score);
}

void backtracking(int idx, int pick_cnt){
    
    if(pick_cnt >= 1 && pick_cnt <= N/2){
        min_ability = min(min_ability, score());
    }

    for(int i=idx; i<=N; i++){
        flag[i] = 1;
        backtracking(i + 1, pick_cnt + 1);
        flag[i] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int k=1; k<=N; k++){
            cin>>map[i][k];
        }
    }
    
    backtracking(1, 0);
    cout<<min_ability;
}
