#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a,b; cin>>a>>b;
    
    cout<<b-gcd(a,b);
}
