#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int N, M;
unordered_map<string, vector<pair<int ,string>>> graph;
unordered_map<string, int> visited;
int file_cnt, file_type_cnt;

void dfs(string node){
    for(auto it: graph[node]){
        if(it.first == 0){
            if(!visited[it.second]){
                visited[it.second] = 1;
                file_type_cnt++;
            }
            file_cnt++;
        }
        if(it.first == 1){
            dfs(it.second);
        }
    }
}


vector<string> parsing(string s){
    vector<string> v;
    istringstream ss(s);
    string stringbuffer;
    
    while(getline(ss, stringbuffer, '/')){
        v.push_back(stringbuffer);
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    for(int i=0; i<N+M; i++){
        string P, E; int C; cin>>P>>E>>C;
        vector<pair<int ,string>> v = graph[P];
        v.push_back({C, E});
        graph[P] = v;
    }
    int Q; cin>>Q;
    for(int i=0; i<Q; i++){
        string s; cin>>s;
        vector<string> v = parsing(s);
        dfs(v.back());
        cout<<file_type_cnt << ' '<< file_cnt << '\n';
        file_cnt = 0;
        file_type_cnt = 0;
        visited.clear();
    }
}
