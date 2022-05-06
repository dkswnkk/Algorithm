#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;


bool visited[1001];
int max_duplic = -1;
int ans;
int main(){
    int n; cin>>n;
    vector<vector<int>>v(n+1,vector<int>(n+1));
    
    for(int i=0; i<n; i++){ // 학년
        for(int k=0; k<5; k++){ //학생
            cin>>v[i][k];
        }
    }
    
    
    for(int a=0; a<n; a++){    //학생 뽑기
        memset(visited,0,sizeof(visited));
        int cnt = 0;
        for(int b=0; b<5; b++){ //학년 탐색
            int peo_class = v[a][b];
            for(int c=0; c<n; c++){    //비교할 학생
                if(a!=c && peo_class == v[c][b]){
                    if(!visited[c]){
                        visited[c] = 1;
                        cnt++;
                    }
                }
            }
        }
        if(max_duplic<cnt){
            max_duplic = cnt;
            ans = a+1;
        }
    }
    cout<<ans;
}
