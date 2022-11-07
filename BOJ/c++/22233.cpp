#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;


vector<string> split(string s){
    istringstream ss (s);
    string stringbuffer;
    vector<string> v;
    while(getline(ss, stringbuffer, ',')){
        v.push_back(stringbuffer);
    }
    return v;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<string, int> um;
    
    int N, M; cin>>N>>M;
    for(int i=0; i<N; i++){
        string s; cin>>s;
        um.insert({s, 1});
    }
    for(int i=0; i<M; i++){
        string s; cin>>s;
        vector<string>v = split(s);
        for(auto it : v){
            um.erase(it);
        }
        cout<<um.size() <<'\n';
    }
}
