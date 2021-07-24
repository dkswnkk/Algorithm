#include <string>
#include <vector>

using namespace std;

int sum,targets,answer;

void dfs(const vector<int>&numbers, int index, int sum){
    if(index<numbers.size()){
        dfs(numbers,index+1,sum+numbers[index]);
        dfs(numbers,index+1,sum-numbers[index]);
    }
    else{
        if(targets==sum)answer++;
        return;
    }
}

int solution(vector<int> numbers, int target) {
    
    targets=target;
    dfs(numbers,0,sum);
    
    return answer;
}
