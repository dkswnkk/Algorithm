#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m; cin>>n>>m;
    
    int left_right_cnt = m, up_down_cnt = n-1;
    int arr[101][101] = {0, };
    int num = n*m;
    int x=0, y=0;
    
    for(int i=0; i<n*m; i++){
        if(arr[x][y]!=0) break;
        switch(i%4){
            case 0: //오른쪽 방향
                for(int k=0; k<left_right_cnt; k++){
                    arr[x][y] = num;
                    num--;
                    y++;
                }
                y--;
                x++;
                left_right_cnt--;
                break;
                
            case 1: //아래쪽 방향
                for(int k=0; k<up_down_cnt; k++){
                    arr[x][y] = num;
                    num--;
                    x++;
                }
                x--;
                y--;
                up_down_cnt--;
                break;
                
            case 2: //왼쪽 방향
                for(int k=0; k<left_right_cnt; k++){
                    arr[x][y] = num;
                    num--;
                    y--;
                }
                y++;
                x--;
                left_right_cnt--;
                break;
                
            case 3: //위쪽 방향
                for(int k=0; k<up_down_cnt; k++){
                    arr[x][y] = num;
                    num--;
                    x--;
                }
                x++;
                y++;
                up_down_cnt--;
                break;
        }
    }
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            cout<<arr[i][k]<<' ';
        }
        cout<<'\n';
    }
}
