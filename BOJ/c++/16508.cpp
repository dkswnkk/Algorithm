#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <memory.h>

using namespace std;

string T;
int N, ans = 1e9;
vector<pair<int, string>>v;
unordered_map<char,int> alphabet_cnt[17];
bool visited[11];

void backtracking(int idx, int cost, int make_len){
    if(idx == N + 1){
        if(make_len == T.length()){
            ans = min(ans, cost);
        }
        return;
    }
    unordered_map<char, int> temp_cnt = alphabet_cnt[idx];
    bool temp_visited[11];
    memcpy(temp_visited, visited, sizeof(visited));
    bool flag = false;
    int flag_cnt = 0;
    for(int i=0; i<T.length(); i++){
        if(alphabet_cnt[idx][T[i]] > 0 && !visited[i]){
            flag_cnt++;
            visited[i] = 1;
            alphabet_cnt[idx][T[i]]--;
            flag = true;
        }
    }
    if(flag) backtracking(idx + 1, cost + v[idx].first, make_len + flag_cnt);
    alphabet_cnt[idx] = temp_cnt;
    memcpy(visited, temp_visited, sizeof(visited));
    backtracking(idx + 1, cost, make_len);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>T>>N;
    for(int i=0; i<N; i++){
        int money; string name; cin>>money>>name;
        v.push_back({money, name});
    }
    for(int i=0; i<v.size(); i++){
        for(int k=0; k<v[i].second.length(); k++){
            alphabet_cnt[i][v[i].second[k]] += 1;
        }
    }
    
    backtracking(0, 0, 0);
    
    if(ans == 1e9) cout<< -1;
    else cout<<ans;
}
