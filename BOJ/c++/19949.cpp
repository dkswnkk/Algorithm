#include <iostream>
#define MAX 10
using namespace std;

int arr[MAX], ans;

void bactracking(int idx, int before_before, int before, int correct){
    if(idx == MAX){
        if(correct >= 5) ans++;
        return;
    }
    
    for(int i=1; i<=5; i++){
        if(before_before == before && before_before == i && before == i) continue;
        
        int _correct = correct;
        if(i == arr[idx]) _correct++;
        bactracking(idx+1, before, i, _correct);
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<MAX; i++) cin>>arr[i];
    
    bactracking(0, 0, 0, 0);
    cout<<ans;
}

