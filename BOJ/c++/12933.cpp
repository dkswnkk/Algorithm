#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string inp; cin>>inp;
    int ans = 0;
    for(int i=0; i<inp.length(); i++){
        bool flag = true;
        char before = inp[i];
        vector<int>index;
        if(inp[i] == 'q'){
            index.push_back(i);
            for(int k=i+1; k<inp.length(); k++){
                if(before == '-'){
                    if(inp[k]=='q'){
                        before = 'q';
                        index.push_back(k);
                    }
                }
                else if(before == 'q' && inp[k] == 'u'){
                    index.push_back(k);
                    before = 'u';
                }
                else if(before == 'u' && inp[k] == 'a') {
                    index.push_back(k);
                    before = 'a';
                }
                else if(before == 'a' && inp[k] == 'c'){
                    index.push_back(k);
                    before = 'c';
                }
                else if(before == 'c' && inp[k] == 'k'){
                    index.push_back(k);
                    if(index.size()==5){
                        for (int idx: index) inp[idx] = '-';
                        if(flag) ans++;
                        flag = false;
                        before = '-';
                        index.clear();
                    }
                }
            }
            index.clear();
        }
    }
    for(int i=0; i<inp.length(); i++){
        if(inp[i]!='-'){
            ans = 0;
            break;
        }
    }
    if(ans==0) cout<<-1;
    else cout<<ans;
    
}
