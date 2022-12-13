#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    int max_l = 0, max_h = 0, max_index = 0;
    int ans = 0;
    
    for(int i=0; i<N; i++){
        int L, H; cin>>L>>H;
        v.push_back({L, H});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        if(v[i].second>max_h){
            max_index = i;
            max_h = v[i].second;
            max_l = v[i].first;
        }
    }
    
    int left_max_l = 0, left_max_h = 0, left_max_index = 0;
    int index = max_index;
    int before_max_l = max_l, before_max_h = max_h;
    while(index != 0){
        for(int i=0; i<index; i++){
            if(v[i].second > left_max_h){
                left_max_l = v[i].first;
                left_max_h = v[i].second;
                left_max_index = i;
            }
        }
        ans += abs((before_max_l - left_max_l)) * left_max_h;
        before_max_l = left_max_l;
        index = left_max_index;
        left_max_l = 0;
        left_max_h = 0;
    }
    
    int right_max_l = 0, right_max_h = 0, right_max_index = 0;
    index = max_index;
    before_max_l = max_l, before_max_h = max_h;
    
    while(index != v.size()-1){
        for(int i=index + 1; i<v.size(); i++){
            if(v[i].second > right_max_h){
                right_max_l = v[i].first;
                right_max_h = v[i].second;
                right_max_index = i;
            }
        }
        ans += abs((before_max_l - right_max_l)) * right_max_h;
        before_max_l = right_max_l;
        index = right_max_index;
        right_max_l = 0;
        right_max_h = 0;
    }
    
    
    cout<<ans + max_h;
    
}
