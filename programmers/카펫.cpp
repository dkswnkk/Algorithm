#include <string>
#include <vector>

using namespace std;
struct Coordinate{
    int x;
    int y;
};

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<Coordinate> v;
    int x=1; int y = brown+yellow;
    
    while(x<y){
        y = (brown+yellow)/x;
        if(x*y==brown+yellow)v.push_back({x,y});
        x++;
    }
    
    for(int i=0; i<v.size(); i++){
        int x = v[i].x-2;
        int y = v[i].y-2;
        if(x*y==yellow){
            answer.push_back(y+2);
            answer.push_back(x+2);
        }
    }
    return answer;
}
