//21:20

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,find; cin>>N>>find;
    
    int arr[1000][1000] = {0, };
    int x=0, y=0;
    int num = N*N;
    int down_up_cnt = N, right_left_cnt=N-1;
    
    for(int i=0; i<N*N; i++){
        switch(i%4){
            case 0: //아래방향
                if(arr[x][y]!=0) break;
                for(int k=0; k<down_up_cnt; k++){
                    arr[x][y]=num;
                    num--;
                    x++;
                }
                x--;
                y++;
                down_up_cnt--;
                break;
                
            case 1: //오른쪽 방향
                if(arr[x][y]!=0) break;
                for(int k=0; k<right_left_cnt; k++){
                    arr[x][y]=num;
                    num--;
                    y++;
                }
                y--;
                x--;
                right_left_cnt--;
                break;
                
            case 2: //위쪽 방향
                if(arr[x][y]!=0) break;
                for(int k=0; k<down_up_cnt; k++){
                    arr[x][y]=num;
                    num--;
                    x--;
                }
                x++;
                y--;
                down_up_cnt--;
                break;
                
            case 3: //왼쪽 방향
                if(arr[x][y]!=0) break;
                for(int k=0; k<right_left_cnt; k++){
                    arr[x][y]=num;
                    num--;
                    y--;
                }
                y++;
                x++;
                right_left_cnt--;
                break;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(arr[i][k]==find) x=i+1, y = k+1;
            cout<<arr[i][k]<<' ';
        }
        cout<<'\n';
    }
    
    cout<<x<< ' '<<y;
}
