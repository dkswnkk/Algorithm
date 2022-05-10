#include <iostream>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n, m; cin>>n>>m;
        int map[201][201];
        for(int i=0; i<n; i++){
            for(int k=0; k<m; k++){
                cin>>map[i][k];
            }
        }
        int ans = -1;
        int max_v = 0;
        for(int i=0; i<n; i++){
            for(int k=0; k<m; k++){
                max_v = 0;
                int x = i, y = k;
                while(x>=0&&y>=0){
                    max_v += map[x][y];
                    x--;
                    y--;
                }
                x = i, y = k;
                while(x>=0&&y<m){
                    max_v += map[x][y];
                    x--;
                    y++;
                }
                x = i, y = k;
                while(x<n&&y>=0){
                    max_v += map[x][y];
                    x++;
                    y--;
                }
                x = i, y = k;
                while(x<n&&y<m){
                    max_v += map[x][y];
                    x++;
                    y++;
                }
                max_v -= (map[i][k]*3);
                ans = max(ans, max_v);
            }
        }
      
        cout<<ans<<'\n';
    }
}
