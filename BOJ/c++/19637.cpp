#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin>>N>>M;
    multimap<int, string> m;
    for(int i=0; i<N; i++){
        string a; int b;
        cin>>a>>b;
        m.insert({b,a});
    }
    
    for(int i=0; i<M; i++){
        int inp; cin>>inp;
        cout<< (m.lower_bound(inp)) ->second <<'\n';
    }
    
}
