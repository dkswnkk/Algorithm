#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string bit = "";
    while(n!=0){
        int mod = n%3;
        bit+=mod+'0';
        n/=3;
    }
    reverse(bit.begin(),bit.end());
    for(int i=0; i<bit.length(); i++){
        if(bit[i]!='0') answer+= pow(3,i)*(bit[i]-'0');
    }
    
    return answer;
}
