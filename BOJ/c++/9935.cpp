#include <iostream>
#include <vector>
using namespace std;

vector<char> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, bomb; cin>>s>>bomb;
    
    for(int i=0; i<s.length(); i++){
        v.push_back(s[i]);
        if(v.size() >= bomb.length()){
            bool flag = true;
            for(int k=0; k<bomb.length(); k++){
                if(v[v.size()-bomb.size()+k] != bomb[k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(int k=0; k<bomb.size(); k++){
                    v.pop_back();
                }
            }
        }
    }
    if(v.empty()){
        cout<<"FRULA";
    }
    else{
        for(char c: v){
            cout<<c;
        }
    }
}
