#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int>answer;
    multiset<int>set;
    
    
    for(int i=0; i<operations.size(); i++){
        
        string operation = operations[i].substr(0,1);
        int num = stoi(operations[i].substr(2));
        
        if(operation=="I") set.insert(num);
        
        else if(operation=="D"){
            if(set.empty()) continue;
            if(num==1) set.erase(--set.end());
            if(num==-1) set.erase(set.begin());
        }
    }
    if(!set.empty()){
    answer.push_back(*(--set.end()));
    answer.push_back(*(set.begin()));
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
    
    
}
