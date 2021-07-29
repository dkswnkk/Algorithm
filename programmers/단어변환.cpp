#include <string>
#include <vector>

using namespace std;

bool visited[1001];
int cnt,ans=9999;

void dfs(string begin,string target,int cnt, vector<string>& words){
    if(begin==target) ans=min(ans,cnt);
    for(int i=0; i<words.size(); i++){
        int check=0;
        for(int k=0; k<words[i].length(); k++){
            if(words[i][k]!=begin[k]) check++;
        }
        if(check==1){
            if(visited[i]) continue;    //이미 탐색했다면 탐색안함.
            visited[i]=true;
            dfs(words[i],target,cnt+1, words);
            cnt--;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    
    int answer = 0;
    
    dfs(begin,target,cnt,words);
    
    if(ans!=9999) answer=ans;
    return answer;
}
