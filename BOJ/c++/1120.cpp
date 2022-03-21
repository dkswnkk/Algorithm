//23:20~00:17
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1,s2; cin>>s1>>s2;
    
    int match_cnt = 1e9;
    for(int i=0; i<s2.length(); i++){
        int temp_cnt = 0;
        bool flag = true;
        for(int k=0; k<s1.length(); k++){
            if(i+s1.length()>s2.length()){
                flag = false;
                break;
            }
            if(s2[i+k]!=s1[k]) temp_cnt++;
        }
        if(flag) match_cnt = min(match_cnt,temp_cnt);
        
    }
    cout<<match_cnt;
}
