#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

bool visited[26];


vector<string> parsing(string s){
    istringstream ss(s);
    string stringbuffer;
    vector<string> v;
    while(getline(ss, stringbuffer, ' ')){
        v.push_back(stringbuffer);
    }
    return v;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin>>N;
    cin.ignore();
    for(int i=0; i<N; i++){
        string s; getline(cin, s);
        vector<string> v = parsing(s);
        
        bool flag = false;
        int string_idx = 0;
        for(int k=0; k<v.size(); k++){
            if(!visited[tolower(v[k][0]) - 97]){
                visited[tolower(v[k][0]) - 97] = 1;
                flag = true;
                string_idx = k;
                break;
            }
        }
        if(flag){
            int idx = 0;
            for(int i=0; i<string_idx; i++){
                idx += v[i].length() + 1;
            }
            for(int k=0; k<s.length(); k++){
                if(idx == k) cout<<'['<<s[k]<<']';
                else cout<<s[k];
            }
        }
        
        int idx = -1;
        string_idx = 0;
        if(!flag){
            for(int i=0; i<v.size(); i++){
                for(int k=0; k<v[i].length(); k++){
                    if(!visited[tolower(v[i][k]) - 97]){
                        visited[tolower(v[i][k]) - 97] = 1;
                        string_idx = i;
                        idx = k;
                        break;
                    }
                    if(idx != -1) break;
                }
            }
            
            if(idx == -1) cout<<s;
            else{
                for(int i=0; i<string_idx; i++){
                    idx += v[i].length() + 1;
                }
                for(int k=0; k<s.length(); k++){
                    if(idx == k) cout<<'['<<s[k]<<']';
                    else cout<<s[k];
                }
            }
        }
        
        cout<<'\n';
    }
}

