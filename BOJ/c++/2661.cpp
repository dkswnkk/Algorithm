#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int N;
string ans;
bool flag = false;
bool isvalid(string num){
    int end = num.length()-1;
    for(int i=1; i<num.length(); i++){
        if(end-i<0) return true;
        string num1 = num.substr(end, i);
        string num2 = num.substr(end-i, i);
        if(num1 == num2) return false;
        end--;
    }
    
    return true;
}

void backtracking(int idx, string temp){
    if(!isvalid(temp) || flag) return;
    
    if(idx == N){
        ans = temp;
        flag = true;
        return;
    }
  
    backtracking(idx+1, temp+"1");
    backtracking(idx+1, temp+"2");
    backtracking(idx+1, temp+"3");
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    backtracking(0, "");
    cout<<ans;
    
}
