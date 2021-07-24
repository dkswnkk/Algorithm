#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,vector<string>>>v;
    map<string,int>m;
    for(int i=1; i<s.length()-1; i++){
        string temp_s;
        vector<string>temp_v;
        if(s[i]=='{'){
            while(s[i]!='}'&&i!=s.length()-1){
                if(s[i]>='0'&&s[i]<='9'&&s[i]!=' ')temp_s+=s[i];
                else{
                    temp_v.push_back(temp_s);
                    temp_s.clear();
                }
                i++;
            }
            if(temp_s.length()!=0) temp_v.push_back(temp_s);
            v.push_back({temp_v.size(),temp_v});
        }
        
        
    }
    
    sort(v.begin(),v.end());
    
    for(int i=0; i<v.size(); i++){
        for(int k=1; k<v[i].second.size(); k++){
            if(m[v[i].second[k]]==0){
                m[v[i].second[k]]++;
                answer.push_back(stoi(v[i].second[k]));
            }
            
        }
    }
    
    return answer;
}
