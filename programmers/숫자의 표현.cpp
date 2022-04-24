#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int k=i; k<=n; k++){
            sum+=k;
            if(sum>n) break;
            else if(sum == n){       
                answer++;
                break;
            }
        }
    }
    return answer;
}
