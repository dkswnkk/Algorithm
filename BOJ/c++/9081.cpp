#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    while(n--){
        string s; cin>>s;
        string temp = s;
        bool flag= false;
        do{
            if(temp != s){
                flag = true;
                break;
            }
            
        }while(next_permutation(temp.begin(), temp.end()));
        
        if(flag) cout<<temp<<'\n';
        else cout<<s<<'\n';
    }
}
