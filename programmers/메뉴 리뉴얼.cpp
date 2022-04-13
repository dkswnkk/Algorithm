#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


using namespace std;

map<string,int>cnt;
map<int,int>len_max;

vector<string>combi_arr;

void combination(int index, string combi, string origin, int max_len){
    for(int i=index; i<max_len; i++){
        string inp = combi+origin[i];
        combi_arr.push_back(inp);
        combination(i+1, inp, origin, max_len);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string order:orders){
        set<string>ncr;
        
        for(int i=0; i<order.length(); i++) combination(i,  "", order, order.length());
        
        for(string &combi:combi_arr) sort(combi.begin(),combi.end());
        for(string combi:combi_arr) ncr.insert(combi);
        
        
        for(auto it=ncr.begin(); it!=ncr.end(); it++) cnt[*it]++;
        
        combi_arr.clear();
    }
    
    for(auto it = cnt.begin(); it!=cnt.end(); it++){
        int len = (it->first).length();
        if(len_max[len]<it->second) len_max[len] = it->second;
    }
    for(auto it = cnt.begin(); it!=cnt.end(); it++){
        for(int cos:course){
            if(it->second>=2&&(it->first).length()==cos&&it->second==len_max[(it->first).length()]){
                answer.push_back(it->first);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}

