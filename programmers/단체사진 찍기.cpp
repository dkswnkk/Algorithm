#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(char dir,int want,int dis){
    if(dir=='='){
        if(dis==want) return true;
    }
    else if(dir=='>'){
        if(dis>want) return true;
    }
    else if(dir=='<'){
        if(dis<want) return true;
    }
    return false;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends="ACFJMNRT";
    
    do{
        bool flag=true;
        for(int i=0; i<data.size(); i++){
            char first,second,dir;
            int want;
            first=data[i][0];
            second=data[i][2];
            dir=data[i][3];
            want=data[i][4]-'0';
            int dis=abs(int(friends.find(first))-int(friends.find(second)))-1;
            
            if(!check(dir,want,dis)) flag=false;
        }
        if(flag) answer++;
    }while(next_permutation(friends.begin(),friends.end()));
    
    
    return answer;
}
