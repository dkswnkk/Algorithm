#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int N;
string num = "0123456789";
vector<ll> asc;

void backtracking(int idx, string temp){
    
    if(!temp.empty()){
        string _temp = temp;
        reverse(_temp.begin(),_temp.end());
        asc.push_back(stoll(_temp));
    }
    
    for(int i=idx+1; i<10; i++){
        temp += num[i];
        backtracking(i, temp);
        temp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    
    for(int i=0; i<10; i++){
        string temp = "";
        backtracking(i,temp+=num[i]);
    }
    
    sort(asc.begin(), asc.end());
    
    if(N>asc.size()) cout<<-1;
    else cout<<asc[N-1];
    
}
