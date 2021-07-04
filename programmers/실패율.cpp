#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int,int>m;
vector<pair<int,double>>fault;

bool cmp(pair<int,double>a,pair<int,double>b){
    if(a.second==b.second) return a.first<b.first;
    
    return a.second>b.second;
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    for(int i=0; i<stages.size(); i++){
        m[stages[i]]++;
    }
    
    for(int i=1; i<=N; i++){
        int total_peo=0;
        for(auto k=m.begin(); k!=m.end(); k++){
            if(k->first>=i){
                total_peo+=k->second;
            }
        }
        
        if(total_peo==0) fault.push_back({i,0});
        else{
         double fault_p=(double)m[i]/(double)total_peo;
         fault.push_back({i,fault_p});
        }
    }
    sort(fault.begin(),fault.end(),cmp);
    
    for(int i=0; i<fault.size(); i++){
        answer.push_back(fault[i].first);
    }
    
    return answer;
}
