#include <string>
#include <vector>
#include <algorithm>
//22:17~22:20
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i:arr){
        if(!(i%divisor)) answer.push_back(i);
    }
    
    if(answer.empty()) answer.push_back(-1);
    
    sort(answer.begin(),answer.end());
    return answer;
    
    
}
