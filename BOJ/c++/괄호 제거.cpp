#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

bool except[201];
vector<pair<int,int>>close;
stack<int> open;
set<string> ans;
string s;

void dfs(int index, int delete_cnt){
    
    if(delete_cnt >= 1){
        string temp = "";
        for(int i=0; i<s.length(); i++){
            if(!except[i]) temp+=s[i];
        }
        ans.insert(temp);
    }
    
    for(int i=index; i<close.size(); i++){
        except[close[i].first] = 1;
        except[close[i].second] = 1;
        dfs(i+1, delete_cnt+1);
        except[close[i].first] = 0;
        except[close[i].second] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') open.push(i);
        else if(s[i]==')'){
            close.push_back({open.top(), i});
            open.pop();
        }
    }
    dfs(0,0);
    
    for(auto it=ans.begin(); it!=ans.end(); it++){
        cout<<*it<<'\n';
    }
}
