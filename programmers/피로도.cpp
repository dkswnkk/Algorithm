#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

int backtracking(vector<int> visited, int explore_cnt, int curr_point, vector<vector<int>>& dungeons){
    
    for(int i=0; i<dungeons.size(); i++){
        int need_point = dungeons[i][0];
        int use_point = dungeons[i][1];
        
        if(curr_point>=need_point){
            if(!visited[i]){
                visited[i]=1;
                ans = max(ans, backtracking(visited, explore_cnt+1, curr_point - use_point, dungeons));
                visited[i]=0;
            } 

        }
    }
    return explore_cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<int>visited(50);
    backtracking(visited,0,k,dungeons);
    
    return ans;
}
