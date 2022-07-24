#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    string s; cin>>s;
    
    
    
    char before = 'B';
    bool flag = true;
    int job = 1;
    
    for(int i=0; i<N; i++){
        if(s[i] == before){
            if(flag) job++;
            flag = false;
        }
        else{
            flag = true;
        }
    }
    before = 'R';
    flag = true;
    int job2 = 1;
    
    for(int i=0; i<N; i++){
        if(s[i] == before){
            if(flag) job2++;
            flag = false;
        }
        else{
            flag = true;
        }
    }
    cout<<min(job,job2);
}
