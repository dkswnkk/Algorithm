#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int max_v = -1, min_v = 1e9+1;

void backtraking(string s, int cnt){
    for(char c : s){
        if((c-'0')&1) cnt++;    // 홀수 갯수 카운팅
    }
    if(s.length() == 1){
        max_v = max(max_v , cnt);
        min_v = min(min_v, cnt);
        return;
    }
    if(s.length() == 2){
        backtraking(to_string(s.front()- '0' + s.back() - '0'), cnt); // 수가 두 자리이면 2개로 나눠서 합을 구하여 새로운 수로 생각한다.
    }
    if(s.length()>=3){
        for(int i=1; i<s.length(); i++){
            for(int k= i+1; k<s.length(); k++){
                string a = s.substr(0, i);
                string b = s.substr(i, k-i);
                string c = s.substr(i + k - i, s.length() - k);
//                cout <<s << ' '<<a << ' '<< b << ' '<< c <<'\n';
                if(a == "") a = "0";
                if(b == "") b = "0";
                if(c == "") c = "0";
                backtraking(to_string(stoi(a) + stoi(b) + stoi(c)), cnt);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin>>s;
    backtraking(s, 0);
    cout<<min_v<<' ' << max_v;
}
