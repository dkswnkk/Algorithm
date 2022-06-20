#include <iostream>
#include <map>
#include <set>
using namespace std;


string s;
map<set<string>,int> visited;
void dfs(int left, int right, string now, set<string> temp){
    if(now.length()>=s.length()){
        if(now == s) visited[temp] = 1;
        return;
    }
    if(left>0){
        temp.insert(s[left-1]+now);
        dfs(left-1, right, s[left-1]+now, temp);
        temp.erase(s[left-1]+now);
    }
    if(right<s.length()){
        temp.insert(now+s[right+1]);
        dfs(left, right+1, now+s[right+1], temp);
        temp.erase(now+s[right+1]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s;
    
    for(int i=0; i<s.length(); i++){
        string temp = "";
        set<string> set_temp = {temp+s[i]};
        dfs(i,i, temp+s[i], set_temp);
    }
    cout<<visited.size();
}
