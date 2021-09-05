#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    for(int k=0;k<moves.size(); k++){ //뽑는 순서대로 진행
        
        int curCrain=moves[k]; //뽑아야할 크레인 위치
        int num=-1;
        for(int i=0;i<board[curCrain-1].size();i++){ //크레인위치에서 제일 위에 있는 번호 뽑기
            if(board[i][curCrain-1]!=0){   //0이 아니라면 뽑아야 할 수
                num=board[i][curCrain-1];
                board[i][curCrain - 1] = 0;
                break;
            }
        }
        if(num!=-1){
            if(!st.empty()){
                if(st.top()==num){
                    st.pop();
                    answer+=2;
                }
                else st.push(num);
            }
            else st.push(num);
        }
    }
    return answer;
}
