#include <iostream>
#define INF 1e9
using namespace std;

int switch_first = 0, switch_second = 1 ;

bool check(string blub, string make, int seq){
    for(int i=1; i<blub.length(); i++){
        if(blub == make) return true;
        if(blub[i-1] != make[i-1]){
            blub[i-1]=='0'?blub[i-1]='1':blub[i-1]='0';
            blub[i]=='0'?blub[i]='1':blub[i]='0';
            blub[i+1]=='0'?blub[i+1]='1':blub[i+1]='0';
            if(seq==1) switch_first++;
            else switch_second++;
        }
    }
    if(blub == make) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    string blub, make; cin>>blub>>make;
    //0번 안눌렸을 때
    bool flag1 = check(blub, make, 1);
    if(!flag1) switch_first = INF;
    //0번 눌렸을 때
    blub[0]=='1'?blub[0]='0':blub[0]='1';
    blub[1]=='1'?blub[1]='0':blub[1]='1';
    bool flag2 = check(blub, make, 2);
    if(!flag2) switch_second = INF;
    
    if(switch_first == INF && switch_second == INF) cout<<-1;
    else cout<<min(switch_first, switch_second);
}
