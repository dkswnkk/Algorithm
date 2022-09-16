#include <iostream>
#include <memory.h>

using namespace std;

int arr[6][3];

bool flag_check(){
    for(int i=0; i<6; i++){
        for(int k=0; k<3; k++){
            if(arr[i][k] != 0) return false;
        }
    }
    return true;
}

bool flag = false;

void backtracking(int idx, int next, int depth){
    if(idx == 5 && depth == 15){
        if(flag_check()) flag = true;
        return;
    }
    if(arr[idx][0] > 0 && arr[next][2] > 0){
        arr[idx][0]--;
        arr[next][2]--;
        backtracking(idx, next + 1, depth + 1);
        arr[idx][0]++;
        arr[next][2]++;
    }
    if(arr[idx][1] > 0 && arr[next][1] > 0){
        arr[idx][1]--;
        arr[next][1]--;
        backtracking(idx, next + 1, depth + 1);
        arr[idx][1]++;
        arr[next][1]++;
    }
    if(arr[idx][2] > 0 && arr[next][0] > 0){
        arr[idx][2]--;
        arr[next][0]--;
        backtracking(idx, next + 1, depth + 1);
        arr[idx][2]++;
        arr[next][0]++;
    }
    if(idx < 5) backtracking(idx + 1, idx + 2, depth);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<4; i++){
        memset(arr, 0, sizeof(arr));
        int c = 0;
        for(int k=0; k<18; k++){
            cin>>arr[k/3][c];
            c++;
            if(c == 3) c = 0;
        }
        backtracking(0, 1, 0);
        if(flag) cout<<1<<' ';
        else cout<<0<<' ';
        flag = false;
    }
    
}
