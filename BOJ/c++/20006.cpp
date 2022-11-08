#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, pair<int,vector<pair<string, int>>>> room;  // key: 룸번호, data: 방정보 {level, {이름, 레벨}}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int p, m; cin>>p>>m;
    int room_number = 1;
    for(int i=0; i<p; i++){
        int l; cin>>l;
        string n; cin>>n;
        bool isjoin = false;
        for(auto it = room.begin(); it!= room.end(); it++){
            int level = it->second.first;
            if(l-10<=level && level<=l+10){ // 정원이 차지 않은 방이 존재한다면
                if(it->second.second.size() < m){
                    it->second.second.push_back({n, l});
                    isjoin = true;
                    break;
                }
            }
        }
        if(!isjoin){
            room.insert({room_number, {l,{{n,l}}}});
            room_number++;
        }
    }
    
    for(auto it = room.begin(); it!= room.end(); it++){
        sort(it->second.second.begin(), it->second.second.end());
        if(it->second.second.size()==m){
            cout<<"Started!"<<'\n';
            for(int k=0; k<it->second.second.size(); k++){
                cout<<it->second.second[k].second<<' ' <<it->second.second[k].first<<'\n';
            }
        }
        else{
            cout<<"Waiting!"<<'\n';
            for(int k=0; k<it->second.second.size(); k++){
                cout<<it->second.second[k].second<<' ' <<it->second.second[k].first<<'\n';
            }
        }
    }
}
