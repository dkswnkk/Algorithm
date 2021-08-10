#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct addScore{
    vector<int>score;   //평균점수 계산하는 점수(열)
};


char check(double avg){
    if(avg>=90) return 'A';
    else if(avg>=80&&avg<90) return 'B';
    else if(avg>=70&&avg<80) return 'C';
    else if(avg>=50&&avg<70) return 'D';
    else if(avg<50) return 'F';
    return 0;
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    vector<addScore>addScore;
    map<int,int>m[500];
    
    for(int i=0; i<scores.size(); i++){
        vector<int>temp;
        for(int k=0; k<scores.size(); k++){
            temp.push_back(scores[k][i]);    //세로로 넣어줌(열).
            m[i][scores[k][i]]++;    //중복된 점수 체크
        }
        addScore.push_back({temp});
    }
    
    
    for(int i=0; i<scores.size(); i++){
        
        double sum=0;
        int cnt=0;
        
        int max_value=*max_element(addScore[i].score.begin(), addScore[i].score.end());   //한 학생이 받은 최고점수 찾기
        int min_value=*min_element(addScore[i].score.begin(), addScore[i].score.end());   //한 학생이 받은 최저점수 찾기
        
        for(int k=0; k<scores.size(); k++){
            if(i==k){
                if(scores[k][i]==max_value){  //본인에게 최고점수를 매겨줬을때
                    if(m[i][scores[k][i]]!=1){
                        sum+=scores[k][i];  //중복된 점수가 있다면 평균내줌
                        cnt++;
                    }
                }
                else if(scores[k][i]==min_value){ //본인에게 최저점수를 매겨줬을때
                    if(m[i][scores[k][i]]!=1){
                        sum+=scores[k][i];  //중복된 점수가 있다면 평균내줌
                        cnt++;
                    }
                }
                else{
                    sum+=scores[k][i];
                    cnt++;
                }
            }
            else{
                sum+=scores[k][i];
                cnt++;
            }
        }
        
        sum/=cnt;
        answer+=check(sum);
        
    }
    return answer;
}
