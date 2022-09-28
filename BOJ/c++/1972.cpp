#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(true){
        bool flag = true;
        string s; cin>>s;
        if(s == "*") break;
        for(int i=1; i<s.length(); i++){    // 몇개씩 건너 뛸 건지
            unordered_map<string, int> visited;
            for(int k=0; k<s.length()-i; k++){    // 인덱스
                string slice = "";
                slice += s[k];
                slice += s[k+i];
                if(visited.find(slice) != visited.end()){
                    flag = false;
                    break;
                }
                else{
                    visited.insert({slice, 1});
                }
            }
            if(!flag) break;
        }
        if(flag) cout<< s << " is surprising." << '\n';
        else cout<< s << " is NOT surprising." <<'\n';
    }
}
