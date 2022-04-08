#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

struct Info{
    set<string> member;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string,set<string>> db;
    map<string,int>reported_cnt;
    map<string,int>memory;
    
    for(string s: report){
        vector<string> report_split;
        istringstream ss(s);
        string stringBuffer;
        while(getline(ss, stringBuffer,' ')){   //공백 스플릿
            report_split.push_back(stringBuffer);
        }
        string reporter = report_split.front();
        
        for(int i=1; i<report_split.size(); i++){   // report 기록
            db[reporter].insert(report_split[i]);
        }
    }
    
    for(auto it=db.begin(); it!=db.end(); it++){    //신고 몇번 받았는지 기록
        for(auto it2 = it->second.begin(); it2!=it->second.end(); it2++){
            reported_cnt[*it2]++;
        }
    }
    
    for(auto it=db.begin(); it!=db.end(); it++){    //신고 몇번 받았는지 기록
        int cnt = 0;
        for(auto it2 = it->second.begin(); it2!=it->second.end(); it2++){
            if(reported_cnt[*it2]>=k) cnt++;
        }
        memory[it->first] = cnt;
    }
    
    for(int i=0; i<id_list.size(); i++){
        answer.push_back(memory[id_list[i]]);
    }
    
    

    
    return answer;
}
