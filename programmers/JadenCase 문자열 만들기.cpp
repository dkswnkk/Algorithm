#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "",temp;
    
    for(int i=0; i<s.length()+1; i++){
        if(s[i]!=' '&&s[i]!='\0') temp+=s[i];
        else{
            temp[0]=toupper(temp[0]);
            for(int k=1; k<temp.length(); k++){
                temp[k]=tolower(temp[k]);
            }
            if(i==s.length()) answer+=temp;
            else answer+=temp+" ";
            temp.clear();
        }
    }   
    
    return answer;
}
