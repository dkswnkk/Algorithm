//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/11444
//  BOJ11444 피보나치수 6

#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;
ll n;

mat mulMatrix(mat &a, mat & b){
    mat tmp(2,vector<ll>(2));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= MOD;
        }
    }
    return tmp;
}

ll fibonacci(ll num){
    mat ans = {{{0,1},{1,0}}};
    mat a = {{1,1},{1,0}};
    while(num > 0){
        if(num & 1) ans = mulMatrix(a,ans);
        a = mulMatrix(a,a);
        num /= 2;
    }
    return ans[0][0];
}



int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    ll num; cin>>num;
    cout<<fibonacci(num);
    
}
