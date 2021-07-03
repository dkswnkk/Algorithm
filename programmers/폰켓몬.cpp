#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int,int>m;
    int answer = 0;
    
    for(int i=0; i<nums.size(); i++){
        m[nums[i]]++;
    }
    
    answer=m.size();
    if(answer>nums.size()/2) answer=nums.size()/2;

    
    return answer;
}
