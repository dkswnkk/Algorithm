#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string N; cin>>N;
    int ans = 0;
    int mul = 9;
    int cnt = 1;
    for(int i=0; i<N.length()-1; i++){
        ans+=(mul*cnt);
        mul*=10;
        cnt++;
    }
    int start_num = 1;
    for(int i=0; i<N.length()-1; i++){
        start_num*=10;
    }
    ans+= abs(stoi(N)-start_num+1)*N.length();
    cout<<ans;
}
