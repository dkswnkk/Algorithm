#include <iostream>
#include <vector>

using namespace std;

int N,add,sub,mul,divd;
int max_v=-1e9-1, min_v = 1e9+1;

void backtrack(int result,int index, vector<int>&num, int add, int sub, int mul, int divd){
    
    if(index==N){
        max_v = max(max_v, result);
        min_v = min(min_v, result);
        return;
    }
    
    if(add>0) backtrack(result+num[index], index+1, num, add-1, sub, mul, divd);
    if(sub>0) backtrack(result-num[index], index+1, num, add, sub-1, mul, divd);
    if(mul>0) backtrack(result*num[index], index+1, num, add, sub, mul-1, divd);
    if(divd>0) backtrack(result/num[index], index+1, num, add, sub, mul, divd-1);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    vector<int>num(N);
    
    for(int i=0; i<N; i++) cin>>num[i];
    cin>>add>>sub>>mul>>divd;
    backtrack(num[0],1,num,add,sub,mul,divd);
    cout<<max_v<<'\n'<<min_v;
}
