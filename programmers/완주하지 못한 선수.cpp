#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int>m;
    
    for(int i=0; i<participant.size(); i++){
        m[participant[i]]++;
    }
    for(int i=0; i<completion.size(); i++){
       m[completion[i]]--;
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        if(i->second!=0){
            answer=i->first;
            break;
        }
    }
    
    return answer;
}
