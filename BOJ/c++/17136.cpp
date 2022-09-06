#include <iostream>
#include <memory.h>

using namespace std;

int N = 10, ans = 1e9;
int map[10][10];
int paper_cnt;
int blank_cnt;
int paper_sum[6] = {5, 5, 5, 5, 5, 5};

bool paper_attach(int x, int y, int size){
    for(int i = x; i < x+size; i++){
        for(int k = y; k < y+size; k++){
            if(i >= 10 || k >= 10 || map[i][k] == 0) return false;
        }
    }
    for(int i = x; i < x+size; i++){
        for(int k = y; k < y+size; k++){
            if(map[i][k] == 1){
                blank_cnt--;
                map[i][k] = 0;
            }
        }
    }
    return true;
}

void backtracking(int x, int y){
    if(blank_cnt == 0){
        ans = min(ans, paper_cnt);
        return;
    }
    
    if(y == 10){
        x += 1;
        y = 0;
    }
    
    if(x == 10) return;
    
    int memory_arr[10][10];
    memcpy(memory_arr, map, sizeof(memory_arr));
    int memory_blank_cnt = blank_cnt;
    
    if(map[x][y] == 1){
        for(int i=5; i>=1; i--){
            if(paper_sum[i] > 0){
                if(paper_attach(x, y, i)){
                    paper_cnt++;
                    paper_sum[i]--;
                    backtracking(x, y + 1);
                    blank_cnt = memory_blank_cnt;
                    paper_sum[i]++;
                    paper_cnt--;
                    memcpy(map, memory_arr, sizeof(map));
                }
            }
        }
    }
    else backtracking(x, y+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
            if(map[i][k] == 1) blank_cnt++;
        }
    }
    
    backtracking(0, 0);
    
    if(ans == 1e9) cout<<-1;
    else cout<<ans;
}
