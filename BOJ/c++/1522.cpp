#include <iostream>
using namespace std;

int main(){
    /*
     "ababab" 일때 a의 총 갯수 = 3개
     "aba"bab  -> b = 1개
     a"bab"ab -> b = 2개
     ab"aba"b -> b = 1개
     aba"bab"  -> b =  2개
     _abab_a_b  -> b = 1개
     _a_baba_b  -> b = 2개
     따라서 가장 작은 1개가 정답.
     */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin>>s;
    
    int cnt = 0;
    for(char c: s){
        if(c == 'a') cnt++;
    }
    s+=s;
    int len = s.length();
    int ans = 1e9, temp = 0;
    for(int i=0; i<len-cnt; i++){
        for(int k=i; k<i+cnt; k++){
            if(s[k] == 'b') temp++;
        }
        ans = min(ans, temp);
        temp = 0;
    }
    cout<<ans;
}
