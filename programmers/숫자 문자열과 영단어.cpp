#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string change(string word){
    if(word=="zero") return "0";
    else if(word=="one") return "1";
    else if(word=="two") return "2";
    else if(word=="three") return "3";
    else if(word=="four") return "4";
    else if(word=="five") return "5";
    else if(word=="six") return "6";
    else if(word=="seven") return "7";
    else if(word=="eight") return "8";
    else if(word=="nine") return "9";
    else return "-1";
}

int solution(string s) {
    string ans;
    int answer = 0;
    for(int i=0; i<s.length();){
        if(s[i]>='a'&&s[i]<='z'){ //단어가 영단어일때
            string temp;
            int k=i;
            while(s[k]>='a'&&s[k]<='z'){
                temp+=s[k];
                k++;
                i=k;
                if(change(temp)!="-1"){
                    ans+=change(temp);
                    i=k;
                    break;
                }
            }
        }
        else{
            ans+=s[i];
            i++;
        }
    }
    
    answer=stoi(ans);
    return answer;
}
