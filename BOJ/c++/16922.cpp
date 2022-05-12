#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
unordered_map<string,int>combi_str;
unordered_map<int,int> combi_num;
vector<string> roma = {"I", "V" , "X", "L"};

int trans(string s){
    int ans = 0;
    for(char c:s){
        if(c=='I') ans += 1;
        if(c=='V') ans += 5;
        if(c=='X') ans += 10;
        if(c=='L') ans += 50;
    }
    return ans;
}

void combi(int index, int len, string s){
    if(len == N){
        combi_str[s]=1;
        return;
    }
    for(int i=index; i<4; i++){
        combi(i, len+1, s+roma[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;

    for(int i=0; i<4; i++) combi(i,1,roma[i]);
    
    for(auto it = combi_str.begin(); it!=combi_str.end(); it++){
        int num = trans(it->first);
        combi_num[num]=1;
    }
    cout<<combi_num.size();
}
