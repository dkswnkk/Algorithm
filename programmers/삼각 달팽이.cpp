#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int num = 1;
    int move_cnt = n;
    
    int arr[1001][1001]={0,};
    int x=0, y=0;
    
    for(int i=0; i<n*n; i++){
        if(arr[x][y]!=0) break;
        switch(i%4){
            case 0: //아래로 이동
                for(int k=0; k<move_cnt; k++){
                    arr[x][y] = num;
                    num++;
                    x++;
                }
                x--;
                y++;
                move_cnt--;
                break;
                
            case 1: //우측으로 이동
                for(int k=0; k<move_cnt; k++){
                    arr[x][y] = num;
                    num++;
                    y++;
                }
                y--;
                x--;
                move_cnt--;
                break;
                
            case 2: //위쪽으로 이동
                for(int k=0; k<move_cnt; k++){
                    arr[x][y] = num;
                    num++;
                    x--;
                }
                x++;
                y--;
                move_cnt--;
                break;
                
            case 3: //좌측으로 이동
                x++;
                int move_x = x, move_y = y;
               
                while(true){
                    if(arr[move_x][move_y]!=0)break;
                    move_y--;
                }
                y = move_y+1;
                break;
        }
    }
    
    for(int i=0; i<1001; i++){
        for(int k=0; k<1001; k++){
            if(arr[i][k]!=0){
                answer.push_back(arr[i][k]);
            }
        }
    }
    return answer;
}
