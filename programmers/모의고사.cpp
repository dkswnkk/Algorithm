#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info{
    vector<int>check_num;
    int peo_num;
    int correct_cnt;
};

vector<info>peo;
vector<int>peo1={1,2,3,4,5};
vector<int>peo2={2,1,2,3,2,4,2,5};
vector<int>peo3={3,3,1,1,2,2,4,4,5,5};

bool cmp(info a,info b){
    return a.correct_cnt>b.correct_cnt;
}


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    peo.push_back({peo1,1,0});
    peo.push_back({peo2,2,0});
    peo.push_back({peo3,3,0});
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==peo[0].check_num[i%5]) peo[0].correct_cnt++;
        if(answers[i]==peo[1].check_num[i%8]) peo[1].correct_cnt++;
        if(answers[i]==peo[2].check_num[i%10]) peo[2].correct_cnt++;
    }
    sort(peo.begin(),peo.end(),cmp);
    
    int max_correct=peo[0].correct_cnt;
    
    for(int i=0; i<peo.size(); i++){
        if(peo[i].correct_cnt==max_correct) answer.push_back(peo[i].peo_num);
    }
    
    return answer;
}
