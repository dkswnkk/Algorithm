#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int check(int grade){
    int ans;
    if(grade==6) return ans=1;
    else if(grade==5) return ans=2;
    else if(grade==4) return ans=3;
    else if(grade==3) return ans=4;
    else if(grade==2) return ans=5;
    else return ans=6;
    
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int,int>lottos_m,win_nums_m;
    
    for(int i=0; i<lottos.size(); i++){
        lottos_m[lottos[i]]++;
    }
    
    for(int i=0; i<win_nums.size(); i++){
        win_nums_m[win_nums[i]]++;
    }
    
    int less=0,great=0;
    
    for(auto i=lottos_m.begin(); i!=lottos_m.end(); i++){
        for(auto k=win_nums_m.begin(); k!=win_nums_m.end(); k++){
            if(i->first==k->first){
                i->second--;  //로또번호가 일치할때 갯수를 깐다.
                k->second--;
                less++;
            }
        }
    }
    
    for(auto k=win_nums_m.begin(); k!=win_nums_m.end(); k++){
        if(k->second!=0&&lottos_m[0]!=0){
            lottos_m[0]--;
            k->second--;
            great++;
        }
    }
    
    great+=less;
    
    answer.push_back(check(great));
    answer.push_back(check(less));
    
    return answer;
}
