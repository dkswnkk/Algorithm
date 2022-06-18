#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

void parsing(string s, deque<int> &dq){
    istringstream ss(s);
    string stringbuffer;
    while(getline(ss, stringbuffer, ',')){
        dq.push_back(stoi(stringbuffer));
    }
    
    
}
int main(){
    int T; cin>>T;
    while(T--){
        string cmd; cin>>cmd;
        int len; string arr; cin>>len>>arr;
        deque<int> dq;
        vector<int>v;
        reverse(arr.begin(), arr.end());
        arr.pop_back();
        reverse(arr.begin(), arr.end());
        arr.pop_back();
        
        parsing(arr, dq);
        bool flag = true, rev = false;
        for(char c: cmd){
            if(c=='D'){
                if(dq.empty()){
                    flag = false;
                    break;
                }
                if(!rev) dq.pop_front();
                else dq.pop_back();
            }
            else if(c=='R'){
                rev=!rev;
            }
        }
        if(!flag) cout<<"error"<<'\n';
        else{
            if(!rev){
                cout<<"[";
                while(!dq.empty()){
                    cout<<dq.front();
                    dq.pop_front();
                    if(dq.size()>=1)cout<<",";
                }
                cout<<"]"<<'\n';;
            }
            else{
                cout<<"[";
                while(!dq.empty()){
                    cout<<dq.back();
                    dq.pop_back();
                    if(dq.size()>=1)cout<<",";
                }
                cout<<"]"<<'\n';;
            }
        }
    }
}
