#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int N;

struct Data{
    int number;
    string name;
};

bool cmp(const Data &v1, const Data &v2){
    return v1.number<v2.number;
}

map<int,int>check;

int main(){
    cin>>N;
    vector<Data>v;
    for(int i=0; i<N; i++){
        char cmd; int number; string name;
        cin>>cmd>>number>>name;
        if(cmd=='I'){
            if(check[number]==0){
                check[number]=1;
                v.push_back({number,name});
            }
        }
        else if(cmd=='D'){
            if(check[number]==1){
                check[number]=0;
                for(int i=0; i<v.size(); i++){
                    if(v[i].number==number) v.erase(v.begin()+i);
                }
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    
    
    for(int i=0; i<5; i++){
        int find; cin>>find;
        cout<<v[find-1].number<<' '<<v[find-1].name<<'\n';
        
    }
    
    
}
