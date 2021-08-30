#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 9999;
    
    if(s.length()==1) answer=1;
    else{
        for(int i=1; i<s.length(); i++){
            int cnt=1,temp_ans=0;
            string before,temp;
            before=s.substr(0,i);
            for(int k=i; k<s.length(); k+=i ){
                temp=s.substr(k,i);
                if(temp==before) cnt++;
                else{
                    if(cnt>1){
                        string plus=to_string(cnt);
                        temp_ans+=plus.length()+before.length();
                    }
                    else if(cnt==1) temp_ans+=before.length();
                    cnt=1;
                    before=temp;
                }
            }
            if(cnt>1){
                string plus=to_string(cnt);
                temp_ans+=plus.length()+before.length();
            }
            else temp_ans+=before.length();
            answer=min(answer,temp_ans);
        }
        
    }
    
    return answer;
}
