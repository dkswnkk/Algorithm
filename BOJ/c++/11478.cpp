#include <iostream>
#include <set>
using namespace std;

set<string> st;
string inp;
void dfs(int index, string s){
    if(index > inp.length()) return;
    st.insert(s);
    dfs(index+1, s + inp[index]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>inp;
    for(int i=0; i<inp.length(); i++){
        dfs(i, inp[i]+"");
    }
    
    cout<<st.size() - 1;
}
