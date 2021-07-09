#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++){
        vector<int>split;
        int first=commands[i][0];
        int second=commands[i][1];
        int third=commands[i][2];
        for(int k=first; k<=second; k++){
            split.push_back(array[k-1]);
        }
        sort(split.begin(),split.end());
        answer.push_back(split[third-1]);
    }    
    return answer;
}
