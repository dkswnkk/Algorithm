#include <iostream>
using namespace std;

int map[501][501];
int N, M;
/*
    총 19개의 모양 가능
 */

int dr1[2][3] = {{1, 2, 3}, {0, 0, 0}};
int dc1[2][3] = {{0, 0 ,0}, {1, 2, 3}};
int dr2[3] = {0, 1, 1};
int dc2[3] = {1, 0, 1};
int dr3[8][3] = {{1, 2, 2}, {0, 0, 1}, {0, 1, 2}, {1, 1, 1}, {0, -1, -2}, {0, 0, 1}, {0, 1, 2}, {0, 0, -1}};
int dc3[8][3] = {{0, 0, 1}, {1, 2, 0}, {1, 1, 1}, {0, 1, 2}, {1, 1, 1}, {1, 2, 2 }, {1,0, 0}, {1, 2, 2}};
int dr4[4][3] = {{1, 1, 2}, {0, -1, -1}, {0, -1, 1}, {0, 1, 1}};
int dc4[4][3] = {{0, 1, 1}, {1, 1, 2}, {1, 1, 0}, {1, 1, 2}};
int dr5[4][3] = {{0, 1, 0}, {0, -1, 1}, {0, -1,0}, {-1, 1, 0}};
int dc5[4][3] = {{1, 1, 2}, {1, 1, 1}, {1, 1, 2}, {0, 0, 1}};

int max_v = -1;
void go(){
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            int r = i;
            int c = k;
            int cnt = 1;
            int temp = map[r][c];
            
            for(int a=0; a<2; a++){ // 첫번째 테트로미노
                for(int b=0; b<3; b++){
                    int nr = r + dr1[a][b];
                    int nc = c + dc1[a][b];
                    if(nr>=0 && nr<N && nc>=0 && nc<M){
                        temp += map[nr][nc];
                        cnt++;
                    }
                }
                if(cnt == 4) max_v = max(max_v, temp);
                cnt = 1;
                temp = map[r][c];
            }
            
            for(int a=0; a<3; a++){ // 두번째 테트로미노
                int nr = r + dr2[a];
                int nc = c + dc2[a];
                if(nr>=0 && nr<N && nc>=0 && nc<M){
                    temp += map[nr][nc];
                    cnt++;
                }
                
                if(cnt == 4) max_v = max(max_v, temp);
            }
            
            cnt = 1;
            temp = map[r][c];
            
            for(int a=0; a<8; a++){ // 세번째 테트로미노
                for(int b=0; b<3; b++){
                    int nr = r + dr3[a][b];
                    int nc = c + dc3[a][b];
                    if(nr>=0 && nr<N && nc>=0 && nc<M){
                        temp += map[nr][nc];
                        cnt++;
                    }
                }
                if(cnt == 4) max_v = max(max_v, temp);
                cnt = 1;
                temp = map[r][c];
            }
            for(int a=0; a<4; a++){ // 네번째 테트로미노
                for(int b=0; b<3; b++){
                    int nr = r + dr4[a][b];
                    int nc = c + dc4[a][b];
                    if(nr>=0 && nr<N && nc>=0 && nc<M){
                        temp += map[nr][nc];
                        cnt++;
                    }
                }
                if(cnt == 4) max_v = max(max_v, temp);
                cnt = 1;
                temp = map[r][c];
            }
            for(int a=0; a<4; a++){ // 다섯번째 테트로미노
                for(int b=0; b<3; b++){
                    int nr = r + dr5[a][b];
                    int nc = c + dc5[a][b];
                    if(nr>=0 && nr<N && nc>=0 && nc<M){
                        temp += map[nr][nc];
                        cnt++;
                    }
                }
                if(cnt == 4) max_v = max(max_v, temp);
                cnt = 1;
                temp = map[r][c];
            }
        }
    }
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
    
    go();
    cout<<max_v;
}
