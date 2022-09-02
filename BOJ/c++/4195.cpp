#include <iostream>
#include <unordered_map>
using namespace std;

int N;
unordered_map<string, string> parent;
unordered_map<string, int> connect_cnt;

string find_parent(string x){
    if(x == parent[x]) return x;
    else return parent[x] = find_parent(parent[x]);
}

void union_parent(string a, string b){
    a = find_parent(a);
    b = find_parent(b);
    if(a > b){
        parent[a] = b;
        connect_cnt[b] += connect_cnt[a];
        connect_cnt[a] = 0;
    }
    else{
        parent[b] = a;
        connect_cnt[a] += connect_cnt[b];
        connect_cnt[b] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        cin>>N;
        
        for(int i=0; i<N; i++){
            string a, b; cin>>a>>b;
            if(connect_cnt[a] == 0 && parent.find(a) == parent.end()){
                connect_cnt[a] = 1;
                parent[a] = a;
            }
            if(connect_cnt[b] == 0 && parent.find(b) == parent.end()){
                connect_cnt[b] = 1;
                parent[b] = b;
            }
            
            if(find_parent(a) != find_parent(b)) union_parent(a, b);
            cout<<connect_cnt[(find_parent(a))]<<'\n';
        }
        parent.clear();
        connect_cnt.clear();
    }
}
