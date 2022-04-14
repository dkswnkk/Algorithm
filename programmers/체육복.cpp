#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int,int> student;
    for(int i=1; i<=n; i++) student[i] = 1; // 체육복 셋팅
    for(int peo:lost) student[peo]--;   // 체육복 잃어버림
    for(int reser: reserve) student[reser]++;   // 여유 체육복 가지고 있음
    
    for(auto it = student.begin(); it!=student.end(); it++){
        if(it->second==0){  // 체육복이 없을 경우
            
            int left = (it->first!=0)?(it->first)-1:-1;   // 왼쪽 사람
            int right = (it->first!=n)?(it->first)+1:-1;  // 오른쪽 사람
            
            if(student[left]>1){    // 왼쪽 사람이 여유복이 있을 경우
                student[left]--;    // 빌려줌
                it->second++;   
            }
            else if(student[right]>1){ // 오른쪽 사람이 여유복이 있을 경우
                student[right]--;   //빌려줌
                it->second++;
            }
        }
    }
    
     for(auto it = student.begin(); it!=student.end(); it++){
        if(it->second!=0) answer++;   
     }
    
    
    
    return answer;
}
