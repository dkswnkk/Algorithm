#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N; cin>>N;
    while(N--){
        string inp; cin>>inp;
        
        sort(inp.begin(), inp.end());
        do{
            cout<<inp<<'\n';
        }while(next_permutation(inp.begin(), inp.end()));
    }
}
