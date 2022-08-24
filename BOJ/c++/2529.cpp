#include <iostream>
#include <vector>
using namespace std;


int k;
vector<char> v;
bool visited[11];
string _max = "000000000", _min = "999999999";

void backtracking(int idx, string result, int before_num, int depth){
    
    if(depth == k){
        if(result>_max) _max = result;
        if(result<_min) _min = result;
        return;
    }
    
    for(int i = 0; i<=9; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        if(result.empty()){
            backtracking(i, result+to_string(i), i, depth);
            visited[i] = 0;
            continue;
        }
        if(v[depth] == '<'){
            if(i>before_num) backtracking(i, result+to_string(i), i, depth+1);
            visited[i] = 0;
        }
        if(v[depth] == '>'){
            if(i<before_num) backtracking(i, result+to_string(i), i, depth+1);
            visited[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>k;
    for(int i=0; i<k; i++){
        char inp; cin>>inp;
        v.push_back(inp);
    }
    
    backtracking(0, "", 0, 0);
    cout<<_max<<'\n'<<_min;
    
}
