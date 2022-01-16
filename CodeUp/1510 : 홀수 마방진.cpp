#include <iostream>
#include <vector>

using namespace std;
int arr[51][51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    
    
    arr[0][n/2]=1;  //1. 시작은 첫행, 한 가운데 열에 1을 둔다.
    
    int row=0,col=n/2;
    bool flag = false;
    
    for(int i=2; i<=n*n; i++){
        if(flag){
            flag=false;
            row++;
            arr[row][col]=i;
            continue;
        }
        row--; col++;  //2. 행을 갑소, 열을 증가
        if(row<0) row = n-1;  //3. 행은 감소하므로 첫 행보다 작아지는 경우에는 마지막 행으로 넘어간다.
        if(col>n-1) col = 0; //4. 열은 증가하므로 마지막 열보다 커지는 경우에는 첫 열로 넘어간다.
        arr[row][col] = i;
        if(i%n==0) flag=true;   //5. 넣은 수가 n의 배수이면 행만 증가한다. 열은 변화없음.
    }
    
    for(int i=0; i<n; i++){
        for(int k=0; k<n; k++){
            cout<<arr[i][k]<<' ';
        }
        cout<<'\n';
    }
}
