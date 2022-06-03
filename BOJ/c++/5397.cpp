#include <iostream>
#include <list>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int n; cin>>n;
    while(n--){
        list<char>li;
        auto it = li.begin();
        string s; cin>>s;
        
        for(char c: s){
            if(c=='>'){
                if(it!=li.end()) it++;
            }
            else if(c=='<'){
                if(it!=li.begin()) it--;
            }
            else if(c=='-'){
                if(it!=li.begin()){
                    it--;
                    it=li.erase(it);
                }
            }
            else li.insert(it, c);
        }
        
        for(auto it=li.begin(); it!=li.end(); it++) cout<<*it;
        cout<<'\n';
        
    }
}
