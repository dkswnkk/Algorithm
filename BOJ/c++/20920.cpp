#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;
unordered_map<string, int> cnt, visited;

bool cmp(string a, string b){
    if(cnt[a] != cnt[b]){
        return cnt[a] > cnt[b];
    }
    else{
        if(a.length() != b.length()){
            return a.length() > b.length();
        }
        else return a < b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin>>N>>M;
    
    for(int i=0; i<N; i++){
        string s; cin>>s;
        if(s.length()>=M){
            v.push_back(s);
            cnt[s]++;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto s: v){
        if(!visited[s]) cout<<s<<'\n';
        visited[s] = 1;
    }
    
}
