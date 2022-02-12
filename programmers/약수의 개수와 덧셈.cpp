#include <string>
#include <vector>
#include <map>


using namespace std;

int solution(int left, int right) {
    int answer = 0;
    map<int,int>divisor;
    for(int i=1; i<1000; i++){
        for(int k=1; k<=i; k++){
            if(i%k==0) divisor[i]++;
        }
    }
    
    for(int i=left; i<=right; i++){
        if(divisor[i]&1) answer-=i;
        else answer+=i;
    }
    return answer;
}
