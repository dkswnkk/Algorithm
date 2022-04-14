#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> people;
    
    for(string par: participant) people[par]++;
    for(string comple: completion) people[comple]--;
    for(auto it = people.begin(); it!=people.end(); it++){
        if(it->second!=0){
            answer = it->first;
            return answer;
        }
    }
    return answer;
}
