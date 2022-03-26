#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int index = 1;
    while(true){
        int L, P, V; cin>>L>>P>>V;
        if(!L&&!V&&!P) break;
        
        cout<<"Case " <<index << ": " <<((V/P)*L) + (V%P>L?L:V%P)<<'\n';
        index++;
    }
}
