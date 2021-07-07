#include <string>
#include <vector>

using namespace std;

string small="abcdefghijklmnopqrstuvwxyz";
string big="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a'&&s[i]<='z'){ //소문자일 경우
            for(int k=0; k<small.length(); k++){
                if(s[i]==small[k]){
                    s[i]=small[(n+k)%small.length()];
                    break;
                }
            }
        }
        else if(s[i]>='A'&&s[i]<='Z'){    //대문자일 경우
            for(int k=0; k<big.length(); k++){
                if(s[i]==big[k]){
                    s[i]=big[(n+k)%big.length()];
                    break;
                }
            }
        }
    }
    answer=s;
    return answer;
}
