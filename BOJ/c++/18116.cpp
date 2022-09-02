#include <iostream>
#include <vector>
using namespace std;


int N;
int parent[1000001];
int child_cnt[1000001];

int find_parent(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find_parent(parent[x]);
    
}

void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if(a<b){
        parent[b] = a;
        child_cnt[a] += child_cnt[b];
        child_cnt[b] = 0;
    }
    else{
        parent[a] = b;
        child_cnt[b] += child_cnt[a];
        child_cnt[a] = 0;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    for(int i=1; i<1000001; i++){
        parent[i] = i;
        child_cnt[i] = 1;
    }
    
    for(int i=0; i<N; i++){
        char cmd; cin>>cmd;
        if(cmd == 'I'){
            int a, b; cin>>a>>b;
            if(find_parent(a) != find_parent(b)) union_parent(a, b);
        }
        else if(cmd == 'Q'){
            int a; cin>>a;
            cout<< child_cnt[find_parent(a)]<<'\n';
        }
    }
}
