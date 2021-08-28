#include <vector>
#include <queue>

using namespace std;

int cnt=0;
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};

void bfs(int x,int y,int m,int n,vector<vector<int>> picture,int number_of_area,int visited[101][101]){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()){
        cnt++;
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<m&&ny>=0&&ny<n){
                if(!visited[nx][ny]&&picture[nx][ny]==picture[x][y]){
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area=0, max_size_of_one_area=0;
    int visited[101][101]={0,};
    
    for(int i=0; i<m; i++){
        for(int k=0; k<n; k++){
            if(!visited[i][k]&&picture[i][k]!=0){
                number_of_area++;
                bfs(i,k,m,n,picture,number_of_area,visited);
                max_size_of_one_area=max(max_size_of_one_area,cnt);
                cnt=0;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
