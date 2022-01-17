#include <iostream>
#include <map>
using namespace std;


int arr[11][11];
int ans,N;
map<int,int>check;
void backtraking(int row,int back, int sum){
    if(row>=N){
        ans= max(ans,sum);
        return;
    }
    for(int i=0; i<N; i++){
        if(check[i]==1) continue;
        check[i]=1;
        backtraking(row+1,i,sum+arr[row+1][i]);
        check[i]=0;
    }
    ans= max(ans,sum);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>arr[i][k];
        }
    }
    for(int i=0; i<N; i++){
        check[i]=1;
        backtraking(0,i,arr[0][i]);
        check.clear();
    }
    cout<<ans;
    
}
