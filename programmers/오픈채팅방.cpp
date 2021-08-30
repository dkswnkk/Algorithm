#include <string>
#include <vector>
#include <map>

using namespace std;


struct DB{
    string status;
    string id;
    string name;
};

map<string,string>m;
vector<DB>userDB;

void inp(string s){
    int cnt=0;
    DB db;
    string temp;
    for(int i=0; i<s.length(); i++){
        if(s[i]!=' ') temp+=s[i];
        else{
            if(cnt==0) db.status=temp;
            else if(cnt==1) db.id=temp;
            cnt++;
            temp.clear();
        }
    }
    if(cnt==1) db.id=temp;
    if(cnt==2) db.name=temp;
    if(db.status!="Leave") m[db.id]=db.name;
    userDB.push_back(db);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(int i=0; i<record.size(); i++){
        inp(record[i]);
        }
    
    for(int i=0; i<userDB.size(); i++){
        string inp;
        userDB[i].name=m[userDB[i].id];
        if(userDB[i].status=="Leave"){
            inp=userDB[i].name+"님이 나갔습니다.";
            answer.push_back(inp);
        }   
        else if(userDB[i].status=="Enter"){
            inp=userDB[i].name+"님이 들어왔습니다.";
            answer.push_back(inp);
        }
    }
    return answer;
}

/* 시간초과 풀이

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DB{
    string status;
    string id;
    string name;
};
vector<DB>userDB;

void change(string name,string id){
    for(int i=0; i<userDB.size(); i++){
        if(userDB[i].id==id) userDB[i].name=name;
    }
}
string find_name(string id){
    string name;
    for(int i=(int)userDB.size(); i>=0; i--){
        if(userDB[i].id==id) name=userDB[i].name;
    }
    return name;
}
void inp(string s){
    int cnt=0;
    DB db;
    string temp;
    for(int i=0; i<s.length(); i++){
        if(s[i]!=' ') temp+=s[i];
        else{
            if(cnt==0) db.status=temp;
            else if(cnt==1) db.id=temp;
            cnt++;
            temp.clear();
        }
    }
    if(cnt==1) db.id=temp;
    if(cnt==2) db.name=temp;
    if(db.status=="Change"||db.status=="Enter"){
        change(db.name,db.id);
    }
    else if(db.status=="Leave") db.name=find_name(db.id);
    userDB.push_back(db);
}
int main(){
    
    int n; cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string s; getline(cin,s);
        inp(s);
    }
    for(int i=0; i<userDB.size(); i++){
        if(userDB[i].status=="Enter") cout<<userDB[i].name<<"님이 들어왔습니다."<<'\n';
        else if(userDB[i].status=="Leave") cout<<userDB[i].name<<"님이 나갔습니다."<<'\n';
    }
}
*/
