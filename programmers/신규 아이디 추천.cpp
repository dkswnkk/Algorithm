#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string s=new_id;
    string ans="";
    
     for(int i=0; i<s.length(); i++){    //1단계
        s[i]=tolower(s[i]);
    }
    
    for(int i=0; i<s.length(); i++){    //2단계
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')||s[i]=='-'||s[i]=='_'||s[i]=='.'){
            ans+=s[i];
        }
    }
    
    s=ans;
    ans.clear();
    
    for(int i=0; i<s.length(); i++){   //3단계
        if(s[i]=='.'){
            if(s[i+1]!='.'){
                ans+=s[i];
            }
        }
        else ans+=s[i];
    }
    
    if(ans[0]=='.') ans.erase(0,1);     //4단계
    if(ans[ans.length()-1]=='.') ans.pop_back();
    
    if(ans.length()==0) ans+='a';   //5단계
    
    while(ans.length()>=16){    //6단계
        ans.pop_back();
    }
    if(ans[ans.length()-1]=='.') ans.pop_back();
    
    
    if(ans.length()<=2){    //7단계
        char add=ans[ans.length()-1];
        while(ans.length()<3){
            ans+=add;
        }
    }
    answer=ans;
    return answer;
}
