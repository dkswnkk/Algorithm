#include <iostream>
#include <vector>


using namespace std;

// O
int block_x[4][3] = { {0,1,1}, {0,0,1}, {0,0,1}, {0,1,1} };
int block_y[4][3] = { {0,-1,0}, {0,1,0}, {0,1,1}, {0,0,1} };

char board[51][51];

int n,m;

int dfs(){
    int x=0, y=0;
    bool flag = true;   //  보드가 전부 검은색이면 true이다.
    
    for(int i=0; i<n; i++){       // 흰 칸을 찾는다.
        for(int k=0; k<m; k++){
            if(board[i][k]=='.'){    // 만약 흰 칸이 있다면 그 부분을 x,y 좌표로 삼는다.
                x=i; y=k;
                flag = false;   //  흰 칸이 있으니 flag를 false로 바꿔준다.
                break;
            }
        }
        if(!flag) break;
    }
    
    if(flag) return 1;  //보드가 만약 전부 검은색이라면 카운터를 증가하고 재귀를 끝낸다.
    
    int cnt=0;
    for(int i=0; i<4; i++){
        bool flag = true;   //4개의 블럭 중 해달 블럭을 놓을 수 있는지 기록하는 변수
        for(int k=0; k<3; k++){
            int nx = x+block_x[i][k];
            int ny = y+block_y[i][k];
            if(nx>=n||ny>=m||nx<0||ny<0){
                flag = false;
                break;
            }
            if(board[nx][ny]=='#'){
                flag = false;
                break;
            }
        }
        
        if(!flag) continue; // 해당 블럭 사용할 수 없으면 다음 블럭 사용
        
        for(int k=0; k<3; k++){ // 놓을수 있는 블럭
            int nx = x+block_x[i][k];
            int ny = y+block_y[i][k];
            board[nx][ny]='#';   // 블럭을 놓으니 검은 칸으로 만들어준다.
        }
        
        cnt+=dfs();  // 계속 탐색한다.
        
        for(int k=0; k<3; k++){ // 놓은 블럭을 원상태로 되돌린다.(다른 블럭을 놓기위해)
            int nx = x+block_x[i][k];
            int ny = y+block_y[i][k];
            board[nx][ny]='.';
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int k=0; k<m; k++){
                cin>>board[i][k];
            }
        }
        cout<<dfs()<<'\n';
    }
}
