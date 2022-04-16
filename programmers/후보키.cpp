#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
map<string,int> uniqueness_table;
vector<string> uniqueness_vec;
set<string> candidate;


bool cmp(string s1, string s2){
    if(s1.length()!=s2.size()) return s1.length()<s2.length();
    return s1<s2;
}

void combination(int index, vector<vector<string>> relation, vector<int> pick){
    map<string,int>temp;
    for(int i=0; i<relation.size(); i++){
        string inp = "";
        for(int k=0; k<pick.size(); k++) inp += relation[i][pick[k]];
        temp[inp]++;
    }
    
    if(temp.size() == relation.size()){
        string inp = "";
        for(int num:pick) inp += to_string(num);
        uniqueness_table[inp] = 1;
        return;
    }
    for(int i=index+1; i<relation[0].size(); i++){
        pick.push_back(i);
        combination(i, relation, pick);
        pick.pop_back();
    }
}

void minimality_check(){
    candidate.insert(uniqueness_vec[0]);
    
    for(int i=1; i<uniqueness_vec.size(); i++){
        bool flag = true;
        for(auto it = candidate.begin(); it!=candidate.end(); it++){
            int cnt = 0;
            for(int k=0; k<it->length(); k++){
                if(uniqueness_vec[i].find(it->data()[k])!=string::npos) cnt++;
            }
            if(cnt == it->length()) flag = false;
        }
        if(flag) candidate.insert(uniqueness_vec[i]);
    }
}

int solution(vector<vector<string>> relation) {
    for(int i=0; i<relation[0].size(); i++) combination(i, relation, {i});
    
    for(auto it = uniqueness_table.begin(); it!= uniqueness_table.end(); it++) uniqueness_vec.push_back(it->first);
    
    sort(uniqueness_vec.begin(),uniqueness_vec.end(),cmp);
    minimality_check();
    
    return candidate.size();
}
