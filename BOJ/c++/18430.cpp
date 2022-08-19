#include <iostream>
#include <vector>

using namespace std;

int N, M , ans;
int map[6][6];
bool visited[6][6];
vector<pair<int,int>> coor[4] = { {{-1, 0 }, {0, 1}}, {{-1,0}, {0, -1}}, {{0, -1}, {1, 0}}, {{0, 1}, {1,0}} };

void backtracking(int x, int y, int sum){
    ans = max(ans, sum);
    
    if(y==M){
        y = 0;
        x++;
    }
    
    if(x==N) return;

    if(!visited[x][y]){
        for(int c = 0; c<4; c++){   // 부메랑 만들고 넘어가기
            int nx1 = x + coor[c][0].first;
            int ny1 = y + coor[c][0].second;
            int nx2 = x + coor[c][1].first;
            int ny2 = y + coor[c][1].second;
            
            if(nx1>=0 && nx2>=0 && nx1<N && nx2<N && ny1>=0 && ny2>=0 && ny1<M && ny2<M){
                if(visited[nx1][ny1] || visited[nx2][ny2]) continue;
                visited[nx1][ny1] = 1;
                visited[nx2][ny2] = 1;
                visited[x][y] = 1;
                
                backtracking(x, y+1, sum + (map[x][y]*2) + map[nx1][ny1] + map[nx2][ny2]);
                
                visited[x][y] = 0;
                visited[nx1][ny1] = 0;
                visited[nx2][ny2] = 0;
            }
        }
    }
    backtracking(x, y+1, sum);  // 부메랑 만들지 않고 넘어가기
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin>>map[i][k];
        }
    }
    
    backtracking(0, 0, 0);
    cout<<ans;
}
