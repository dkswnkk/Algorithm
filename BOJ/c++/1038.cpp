#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;


vector<ll> v;

void backtracking(string s){
    if(s > "9876543210") return;
    string temp = s;
    reverse(temp.begin(), temp.end());
    v.push_back(stoll(temp));
    for(int i=s.back() - '0' + 1; i<=9; i++){
        string num = to_string(i);
        backtracking(s + num);
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    for(int i=0; i<=9; i++){
        string num = to_string(i);
        backtracking(num);
    }
    sort(v.begin(), v.end());
    
    if(n>=v.size()) cout<<-1;
    else cout<<v[n];
}
