#include <iostream>
using namespace std;

int parent[500001];

int n, m;

int find_parent(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    int ans = 0;
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        if(find_parent(a) == find_parent(b)){
            ans = i + 1;
            break;
        }
        union_parent(a, b);
    }
    cout<<ans;
    
}
