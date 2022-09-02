#include <iostream>
using namespace std;


int parent[100001];
int G, P, ans;


int find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void union_parent(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<=100000; i++) parent[i] = i;
    
    cin>>G>>P;
    for(int i=1; i<=G; i++){
        int gate; cin>>gate;
        
        if(find(gate) == 0) break;
        else{
            ans++;
            union_parent(find(gate), find(gate)-1);
        }
    }
    cout<<ans;
}
