#include <iostream>
using namespace std;

int arr[101];
int N;

void boy(int num){
    for(int i=num; i<=N; i++){
        if(i % num == 0) arr[i] = !arr[i];
    }
}

void girl(int num){
    int left = num - 1;
    int right = num + 1;
    while(true){
        if(left < 1 || right > N) break;
        if(arr[left] == arr[right]){
            left--;
            right++;
        }
        else break;
    }
    left++;
    right--;
    for(int i=left; i<=right; i++) arr[i] = !arr[i];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=1; i<=N; i++) cin>>arr[i];
    int peo; cin>>peo;
    for(int i=0; i<peo; i++){
        int a, b; cin>>a>>b;
        if(a == 1) boy(b);
        else if(a == 2) girl(b);
    }
    for(int i=1; i<=N; i++){
        cout<<arr[i] <<' ';
        if(i % 20 == 0) cout<<'\n';
    }
    
}

