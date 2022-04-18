#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string binary(int n){
    string bit = "";
    while(n!=0){
        bit+= to_string(n%2);
        n/=2;
    }
    reverse(bit.begin(), bit.end());
    return bit;
}

int one_check(string bit){
    int cnt = 0;
    for(char c : bit){
        if(c=='1') cnt++;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int one_cnt = 0;
    string n_bit = binary(n);
    one_cnt = one_check(n_bit);
    
    while(true){
        n+=1;
        string temp = binary(n);
        int temp_one_cnt = one_check(temp);
        if(one_cnt==temp_one_cnt){
            answer = n;
            break;
        }
    }
    return answer;
}
