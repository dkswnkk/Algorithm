#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;


bool isPrime(ll num){
    if(num==0 || num==1) return false;
    if(num==2) return true;
    for(int i=2; i<=sqrt(num)+1; i++){
        if(num % i==0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        ll num; cin>>num;
        while(true){
            if(isPrime(num)){
                cout<<num<<'\n';
                break;
            }
            else num++;
        }
    }
    
}
