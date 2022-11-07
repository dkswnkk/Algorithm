#include <iostream>
#include <algorithm>
using namespace std;


string s, make;
bool flag = false;

void dfs(string temp){
    if(temp == s){
        flag = true;
        return;
    }
    
    if(temp.empty()) return;
    
    if(temp.back() == 'A'){
        string _temp = temp;
        _temp.pop_back();
        dfs(_temp);
    }
    if(temp.front() == 'B'){
        string _temp = temp;
        _temp.erase(_temp.begin());
        reverse(_temp.begin(), _temp.end());
        dfs(_temp);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s>>make;
    dfs(make);
    if(flag) cout<<1;
    else cout<<0;
}
