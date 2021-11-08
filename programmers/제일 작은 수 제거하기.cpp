#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int min_index = min_element(arr.begin(),arr.end())-arr.begin();
    if(arr.size()==1) answer.push_back(-1);
    else{
        arr.erase(arr.begin()+min_index);
        answer=arr;
    }
    return answer;
}
