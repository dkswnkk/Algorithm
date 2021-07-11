#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct info{
    int h_index;
    int min_cnt;
    int max_cnt;
};

int solution(vector<int> citations) {
    int answer = 0;
    vector<info>vec;
    
    sort(citations.begin(),citations.end());    
    
    int max_h=citations.back();
    
    for(int i=0; i<citations.size(); i++){
        vec.push_back({citations[i],i+1,(int)citations.size()-i});
    }    
    
    for(int i=0; i<max_h; i++){
        for(int k=0; k<vec.size(); k++){
            if(vec[k].h_index>=i&&vec[k].max_cnt>=i&&vec[k].min_cnt<=i) answer=max(answer,i);
        }
    }
   
    
    return answer;
}
