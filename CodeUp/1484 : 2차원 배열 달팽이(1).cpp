#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M; cin>>N>>M;
    
    int num = 1;
    int loop = N*M;
    int arr[101][101] = {0,};
    int x = 0, y = 0;
    int right_left_cnt = M, down_up_cnt = N-1;
    
    for(int i=0; i<loop; i++){
        switch(i%4){
            case 0:
                if(arr[x][y]!=0) break;
                for(int k=0; k<right_left_cnt; k++){
                    arr[x][y] = num;
                    num++;
                    y++;
                }
                y--;
                x++;
                right_left_cnt--;
                break;
                
            case 1:
                if(arr[x][y]!=0) break;
                for(int k=0; k<down_up_cnt; k++){
                    arr[x][y] = num;
                    num++;
                    x++;
                }
                x--;
                y--;
                down_up_cnt--;
                break;
                
            case 2:
                if(arr[x][y]!=0) break;
                for(int k=0; k<right_left_cnt; k++){
                    arr[x][y]=num;
                    num++;
                    y--;
                }
                x--;
                y++;
                right_left_cnt--;
                break;
                
            case 3:
                if(arr[x][y]!=0) break;
                for(int k=0; k<down_up_cnt; k++){
                    arr[x][y]=num;
                    num++;
                    x--;
                }
                x++;
                y++;
                down_up_cnt--;
                break;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cout<<arr[i][k]<<' ';
        }
        cout<<'\n';
    }
}
