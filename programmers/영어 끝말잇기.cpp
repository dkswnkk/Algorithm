#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,int> duplicate;
    int cycle = 1;
    char before_char = words[0].back();
    duplicate[words[0]]++;
    
    for(int i=1; i<words.size(); i++){
        if(i%n==0) cycle++;
        
        if(words[i].front()!=before_char){
            answer.push_back((i%n)+1);
            answer.push_back(cycle);
            return answer;
        }
        
        if(duplicate[words[i]]!=0){
            answer.push_back((i%n)+1);
            answer.push_back(cycle);
            return answer;
        }
        before_char = words[i].back();
        duplicate[words[i]]++;
        
    }
    
    if(answer.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}
