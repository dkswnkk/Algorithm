#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s;
    s=to_string(n);
    
    reverse(s.begin(),s.end());
    
    for(int i=0; i<s.length(); i++){
        long long inp=s[i]-'0';
        answer.push_back(inp);
    }
    
    return answer;
}
