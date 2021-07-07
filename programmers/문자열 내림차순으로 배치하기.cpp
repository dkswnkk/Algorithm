#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char a, char b){
    if(a>'a'&&a<'z'&&b>'a'&&b<'z') return a>b; //둘다 소문자 일 경우
    else if(a>'a'&&a<'z'&&b>'A'&&b<'B')  return a<b;    //B가 대문자일 경우
    else return a>b;
}


string solution(string s) {
    string answer = "";

    vector<char>v; 
    
    for(int i=0; i<s.length(); i++){
        v.push_back(s[i]);
    }
    
    sort(v.begin(),v.end(),cmp);
    
    for(char c:v){
        answer+=c;
    }
    
    return answer;
}
