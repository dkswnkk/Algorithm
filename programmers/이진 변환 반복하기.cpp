#include <string>
#include <vector>
#include <algorithm>
// 13:35~47
using namespace std;

int zero_cnt;
int trans_cnt;

string delete_zero(string s){
    string bit = "";
    for(char c:s){
        if(c=='0') zero_cnt++;
        else bit+=c;
    }
    return bit;
}

string make_bit(string s){
    trans_cnt++;
    int num = s.length();
    string bit = "";
    while(num!=0){
        bit += to_string(num%2);
        num /= 2;
    }
    reverse(bit.begin(),bit.end());
    return bit;
}
vector<int> solution(string s) {
    
    while(s!="1"){
        s = delete_zero(s);
        s = make_bit(s);
    }
    return {trans_cnt,zero_cnt};
}
