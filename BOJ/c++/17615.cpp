#include <iostream>
#include <regex>
using namespace std;

int ans = 1e9;
string s;
int jump(char move, char stop){
    bool stop_check = false, move_check = false;
    int cnt1 = 0;
    int len = s.length();
    for(int i=len-1; i>=0; i--){
        char c = s[i];
        if(c == move) move_check = true;
        if(c == stop && move_check) stop_check = true;
        if(c == stop && stop_check){
            stop_check = false;
            cnt1++;
        }
    }
    
    int cnt2 = 0;
    stop_check = false; move_check = false;
    for(int i=0; i<len; i++){
        char c = s[i];
        if(c == move) move_check = true;
        if(c == stop && move_check) stop_check = true;
        if(c == stop && stop_check){
            stop_check = false;
            cnt2++;
        }
    }
    return min(cnt1,cnt2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    cin>>s;
    
    ans = min(jump('R', 'B'), ans);
    ans = min(jump('B', 'R'), ans);
    
    cout<<ans;
}
