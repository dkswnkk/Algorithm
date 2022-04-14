#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n>0){
        bool flag = false;
        if(n%3==0){
            answer+='4';
            flag = true;
        }
        if(n%3==1) answer+='1';
        if(n%3==2) answer+='2';
        n/=3;
        if(flag) n-=1;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
