#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int index;

bool cmp(string a,string b){
    if(a[index]!=b[index]) return a[index]<b[index];
    else return a<b;
}



vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    index=n;
    
    sort(strings.begin(),strings.end(),cmp);
    
    answer=strings;
    
    return answer;
}
