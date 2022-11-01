#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin>>s;
    int len = s.length();
    
    bool flag = true;
    unordered_map<char,int> cnt;
    for(int i=0; i<len; i++){
        if(s[i] == 'w') cnt['w']++;
        else if(s[i] != 'f') cnt[s[i]]++;
        else if(s[i] == 'f') cnt['f']++;
        
        if( (s[i] == 'w' && (s[i+1] == 'l'|| s[i+1] == 'f'))
            || (s[i] == 'o' && (s[i+1] == 'f' || s[i+1] == 'w'))
            || (s[i] == 'l' && (s[i+1] == 'w' || s[i+1] == 'o'))
            || (s[i] == 'f' && (s[i+1] == '0' || s[i+1] == 'l'))){
            flag = false;
            break;
        }
        if(s[i] == 'f' && s[i+1] != 'f'){
            int num = cnt['w'];
            if(cnt['w'] == num && cnt['o'] == num && cnt['l'] == num && cnt['f'] == num){
                cnt.clear();
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
    }
    
    int num = cnt['w'];
    if(!(cnt['w'] == num && cnt['o'] == num && cnt['l'] == num && cnt['f'] == num)) flag = false;
    
    cout<<flag?1:0;

}
