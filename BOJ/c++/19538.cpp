#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;


vector<string> parsing_time(string s){
    istringstream ss(s);
    string stringbuffer;
    vector<string> v;
    while(getline(ss,stringbuffer, ':')){
        v.push_back(stringbuffer);
    }
    return v;
}

vector<string> parsing_blank(string s){
    istringstream ss(s);
    string stringbuffer;
    vector<string> v;
    while(getline(ss,stringbuffer, ' ')){
        v.push_back(stringbuffer);
    }
    return v;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string start_time, end_time, streaming_time; cin>>start_time>>end_time>>streaming_time;
    
    int start, end, stream, ans = 0;
    
    vector<string> v = parsing_time(start_time);
    start = stoi(v[0])*60 + stoi(v[1]);
    
    v = parsing_time(end_time);
    end = stoi(v[0])*60 + stoi(v[1]);
    
    v = parsing_time(streaming_time);
    stream = stoi(v[0])*60 + stoi(v[1]);
    
    string s;
    unordered_map<string, pair<bool,bool>> peo_check;
    cin.ignore();
    
    while(getline(cin, s)){
        v = parsing_blank(s);
        vector<string> time = parsing_time(v[0]);
        int hour = stoi(time[0]) * 60;
        int minute = stoi(time[1]);
        if(start>=hour+minute) peo_check[v[1]].first=true;
        else if(end<=hour+minute && stream>=hour+minute) peo_check[v[1]].second=true;
    }
    
    for(auto it = peo_check.begin(); it!=peo_check.end(); it++){
        if(it->second.first && it->second.second) ans++;
    }
    
    cout<<ans;
    
}
