#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int check(int n){
    if(n<=1) return 6;
    return 7-n;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int,int>m;
    int best = 0, worst = 0;
    
    for(int lotto: lottos) m[lotto]++;
    for(int win: win_nums){
        if(m.find(win)!=m.end()) m[win]--;
    }
    
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->first==0){
            best+=it->second;
            worst+=it->second;
        } 
        else if(it->first!=0){
            if(it->second==0) best++;
            else worst++;
        }
    }
    
    answer.push_back(check(best));
    answer.push_back(check(6-worst));
    return answer;
}
