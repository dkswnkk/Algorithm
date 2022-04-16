#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
map<string,int> duplicate_candidate_table;
vector<string> duplicate_candidate_vec;
set<string> candidate;


bool cmp(string s1, string s2){
    if(s1.length()!=s2.size()) return s1.length()<s2.length();
    return s1<s2;
}

bool check(string inp){
    if(duplicate_candidate_table.find(inp)!=duplicate_candidate_table.end()) return false;    //이미 유일성은 만족하는게 있음
    return true;
}

void combination(int index, vector<vector<string>> relation, vector<int> pick){
    map<string,int>temp;
    
    bool flag = true;
    for(int i=0; i<relation.size(); i++){
        string inp = "";
        string num = "";
        for(int k=0; k<pick.size(); k++){
            inp += relation[i][pick[k]];
            num+=to_string(pick[k]);
            if(!check(num)){
                flag = false;;
                break;
            }
        }
        temp[inp]++;
        if(!flag)break;
    }
    
    if(temp.size() == relation.size()){
        string inp = "";
        for(int num:pick) inp += to_string(num);
        duplicate_candidate_table[inp] = 1;
        return;
    }
    for(int i=index+1; i<relation[0].size(); i++){
        pick.push_back(i);
        combination(i, relation, pick);
        pick.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    for(int i=0; i<relation[0].size(); i++) combination(i, relation, {i});
    
    for(auto it = duplicate_candidate_table.begin(); it!= duplicate_candidate_table.end(); it++) duplicate_candidate_vec.push_back(it->first);
    sort(duplicate_candidate_vec.begin(),duplicate_candidate_vec.end(),cmp);
    
    for(int i=0; i<duplicate_candidate_vec.size(); i++){
        if(candidate.empty()){
            candidate.insert(duplicate_candidate_vec[i]);
            continue;
        }
        bool flag = true;
        for(auto it = candidate.begin(); it!=candidate.end(); it++){
            int cnt = 0;
            for(int k=0; k<it->length(); k++){
                if(duplicate_candidate_vec[i].find(it->data()[k])!=string::npos) cnt++;
            }
            if(cnt == it->length()) flag = false;
        }
        if(flag) candidate.insert(duplicate_candidate_vec[i]);
    }
    return candidate.size();
}

