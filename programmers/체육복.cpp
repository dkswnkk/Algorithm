#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    map<int,int>lost_m,reserve_m;
    
    for(int i=0; i<lost.size(); i++){
        lost_m[lost[i]]++;
    }
    for(int i=0; i<reserve.size(); i++){
        reserve_m[reserve[i]]++;
    }
    
    for(int i=1; i<=n; i++){
        if(lost_m[i]==1&&reserve_m[i]==1){ //체육복을 도난 당했고, 본인 여벌옷이 있을때
            reserve_m[i]--;
            lost_m[i]--;
            
        }
    }
    
    for(int i=1; i<=n; i++){
        if(lost_m[i]==1){ //체육복을 도난 당했을 때
            for(auto k=reserve_m.begin(); k!=reserve_m.end(); k++){ //체육복을 빌릴 수 있는지 알아본다.
                if(k->first==i-1&&k->second==1){
                    k->second--;
                    lost_m[i]--;
                    break;
                }
                else if(k->first==i+1&&k->second==1){
                    k->second--;
                    lost_m[i]--;
                    break;
                }
                
            }
        }
    }
    
    for(auto i=lost_m.begin(); i!=lost_m.end(); i++){
        if(i->second!=0) n--;
    }
    
    answer=n;
    return answer;
}
