#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string>cache, v;
    
    for(string city:cities){
        v.push_back(city);
    }
    for(int i=0; i<v.size(); i++){
        for(int k=0; k<v[i].length(); k++){
            if(isupper(v[i][k])) v[i][k]+=32;   //대문자면은 소문자로 변경
        }
    }
    for(string city:v){
        
        if(cacheSize==0) answer+=5;
        
        else if(find(cache.begin(), cache.end(), city)==cache.end()){   // 현재 캐시에 없을 때
            answer+=5;  // 실행시간 갱신
            if(cache.size()==cacheSize){
                cache.erase(cache.begin()); // 가장 옛날에 쓰인 캐시 삭제
                cache.push_back(city);
            }
            else if(cache.size()<cacheSize){ //  //캐시가 현재 다 차지 않았을 때
                cache.push_back(city);  // 캐시에 추가
            }
        }
        
        else{   // 현재 캐시에 있을 때
            answer+=1;  // 실행시간 갱신
            int cache_index = find(cache.begin(), cache.end(), city) - cache.begin();
            cache.erase(cache.begin()+cache_index);
            cache.push_back(city);    //캐시 갱신
        }
    }
    return answer;
}
