#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

int backtracking(int index, int explore_cnt, int curr_point, vector<vector<int>>& dungeons){
    
    for(int i=index; i<dungeons.size(); i++){
        int need_point = dungeons[i][0];
        int use_point = dungeons[i][1];
        
        if(curr_point>=need_point){
            ans = max(ans, backtracking(i+1, explore_cnt+1, curr_point - use_point, dungeons));
        }
    }
    return explore_cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    sort(dungeons.begin(),dungeons.end());
    
    do{
        backtracking(0,0,k,dungeons);
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    
    backtracking(0,0,k,dungeons);
    return ans;
}
