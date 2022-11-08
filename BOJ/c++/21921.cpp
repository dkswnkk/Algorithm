#include <iostream>
using namespace std;

int arr[250001];
int sum[250001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, X; cin>>N>>X;
    
    for(int i=0; i<N; i++) cin>>arr[i];
    
    int cnt = 0, temp = 0;
    int visited = -1;
    for(int i=0; i<N; i++){
        if(cnt != X-1){
            temp += arr[i];
            cnt++;
        }
        else{
            temp -= arr[i-X];
            sum[i] = temp + arr[i];
            visited = max(visited, sum[i]);
            temp += arr[i];
        }
    }
    
    int ans_cnt = 0;
    for(int i=0; i<N; i++){
        if(sum[i] == visited) ans_cnt++;
    }
    if(visited == 0) cout<<"SAD"<<'\n';
    else cout<<visited<<'\n'<<ans_cnt;
    
}
