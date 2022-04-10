#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    for(int move:moves){
        int pick_num = 0;
        for(int i=0; i<board.size(); i++){
            if(board[i][move-1]!=0){
                pick_num = board[i][move-1];
                board[i][move-1]=0;
                break;
            }
        }
        if(pick_num>0&&!basket.empty()){
            if(basket.top()==pick_num){
                basket.pop();
                answer+=2;
            }
            else basket.push(pick_num);
        }
        else if(basket.empty()){
            basket.push(pick_num);
        }
        
    }
    return answer;
}
