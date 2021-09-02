#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int visited[6][6];
string map[6][6];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool check=true;

void dfs(int x,int y,int dist){
    visited[x][y]=1;
    if(dist>0&&dist<=2&&map[x][y]=="P"){
        check=false;
        return;
    }
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<5&&ny>=0&&ny<5){
            if(!visited[nx][ny]&&map[nx][ny]!="X"){
                visited[nx][ny]=1;
                dfs(nx,ny,dist+1);
                visited[nx][ny]=0;
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                map[j][k]=places[i][j][k];
            }
        }
        
        for(int a=0; a<5; a++){
            for(int b=0; b<5; b++){
                memset(visited,0,sizeof(visited));
                if(!visited[a][b]&&map[a][b]=="P"){
                    dfs(a,b,0);
                }
            }
        }
        if(check) answer.push_back(1);
        else answer.push_back(0);
        check=true;
        memset(map,0,sizeof(map));
    }
    
    
    
    return answer;
    
}
