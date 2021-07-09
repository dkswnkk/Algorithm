#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int cnt=0;
    
    for(int i=0; i<s.length(); i++){
       bool flag=false;
        if(s[i]==' '){
            cnt=0;
            flag=true;
            continue;
        }
        if(cnt%2==0) s[i]=toupper(s[i]); //짝수번째일때 대문자로
        else s[i]=tolower(s[i]); //홀수번째일때 소문자로
        cnt++;
    }
    
    answer=s;
    return answer;
    
}
