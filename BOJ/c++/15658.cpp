#include <iostream>
#include <vector>

using namespace std;

int N;
int _add, _sub, _mul, _div;
vector<int> v;

int _max = -1e9, _min = 1e9;

void dfs(int add, int sub, int mul, int div, int result, int idx){
    
    
    if(idx == N){
        _max = max(_max, result);
        _min = min(_min, result);
        return;
    }
    
    if(add>0) dfs(add-1, sub, mul, div, result + v[idx], idx +1);
    if(sub>0) dfs(add, sub-1, mul, div, result - v[idx], idx +1);
    if(mul>0) dfs(add, sub, mul-1, div, result * v[idx], idx +1);
    if(div>0) dfs(add, sub, mul, div-1, result / v[idx], idx +1);
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    
    cin>>_add>>_sub>>_mul>>_div;
    dfs(_add, _sub, _mul, _div, v[0], 1);
    cout<<_max << ' '<< _min;
    
    
}
