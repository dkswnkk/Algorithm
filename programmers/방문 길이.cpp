#include <string>
#include <vector>
#include <map>

using namespace std;


/*
 이 문제의 핵심은 방향성이 없다는 것이다
 즉 (-1,0) 에서 (0,0) 으로 화살표와 (0,0)에사 (-1,0)으로의 화살표가 같다는 의미이다.
 */

bool range_check(int x, int y){
    if(x>5||y>5||x<-5||y<-5) return false;
    return true;
}

int solution(string dirs) {
    
    map<vector<int>,int>check;
    
    int answer = 0;
    int x=0,y=0;
    
    for(int i=0; i<dirs.length(); i++){
        char dir = dirs[i];
        if(dir=='R'){
            if(range_check(x+1,y)){
                vector<int> temp1{x,y,x+1,y};
                vector<int> temp2{x+1,y,x,y};
                if(check[temp1]==0&&check[temp2]==0) answer++;
                check[temp1]++;
                check[temp2]++;
                x+=1;
            }
        }
        if(dir=='L'){
            if(range_check(x-1,y)){
                vector<int> temp1{x,y,x-1,y};
                vector<int> temp2{x-1,y,x,y};
                if(check[temp1]==0&&check[temp2]==0) answer++;
                check[temp1]++;
                check[temp2]++;
                x-=1;
                
            }
        }
        if(dir=='D'){
            if(range_check(x,y-1)){
                vector<int> temp1{x,y,x,y-1};
                vector<int> temp2{x,y-1,x,y};
                if(check[temp1]==0&&check[temp2]==0) answer++;
                check[temp1]++;
                check[temp2]++;
                y-=1;
            }
        }
        if(dir=='U'){
            if(range_check(x,y+1)){
                vector<int> temp1{x,y,x,y+1};
                vector<int> temp2{x,y+1,x,y};
                if(check[temp1]==0&&check[temp2]==0) answer++;
                check[temp1]++;
                check[temp2]++;
                y+=1;
            }
        }
    }
    return answer;
}
