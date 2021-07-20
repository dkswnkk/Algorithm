#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<pair<char,int>>v,temp;
    
    for(int i=0; i<skill.length(); i++){
        v.push_back({skill[i],1});
    }
    
    temp=v;
    
    for(int i=0; i<skill_trees.size(); i++){
        auto it =temp.begin();
        for(int k=0; k<skill_trees[i].length(); k++){
            char check=skill_trees[i][k];
            if(it->first==check){
                it->second--;
                it++;
            }
        }
        
        bool flag=true;
        
        for(auto it=temp.begin(); it!=temp.end(); it++){
            for(int k=0; k<skill_trees[i].length(); k++){
                if(skill_trees[i][k]==it->first &&it->second!=0) flag=false;
            }
        }
        
        if(flag) answer++;
        temp=v;
    }
    
    return answer;
}
